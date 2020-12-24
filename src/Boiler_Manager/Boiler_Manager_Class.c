#include "Boiler_Manager_Class.h"

#include <stddef.h> /* NULL */

/*============================================================================*/
/* Singleton */
/*============================================================================*/
extern const Boiler_Manager_Class Boiler_Manager;


/*============================================================================*/
/* Attributes access */
/*============================================================================*/
#define My_Low_Temperature (Boiler_Manager.var_attr->Low_Temperature)
#define My_High_Temperature (Boiler_Manager.var_attr->High_Temperature)
#define My_Targeted_Temperature (Boiler_Manager.var_attr->Targeted_Temperature)


/*============================================================================*/
/* Required interfaces access */
/*============================================================================*/
#define Clock__Get_Day( day ) \
        Boiler_Manager.Clock->Get_Day( day )
#define Clock__Get_Hour( hour ) \
        Boiler_Manager.Clock->Get_Hour( hour )
#define Clock__Get_Minute( minute ) \
        Boiler_Manager.Clock->Get_Minute( minute )
 
#define Mesured_Temperature__Get_Temperature \
        Boiler_Manager.Mesured_Temperature->Get_Temperature

#define Relay_Cmd__Close_Circuit \
        Boiler_Manager.Relay_Cmd->Close_Circuit
#define Relay_Cmd__Open_Circuit \
        Boiler_Manager.Relay_Cmd->Open_Circuit
        
#define Mode__Get_Operating_Mode( mode ) \
        Boiler_Manager.Mode->Get_Operating_Mode( mode )


/*============================================================================*/
/* Private methods declaration */
/*============================================================================*/
static void Compute_Targeted_Temperature( void );
static void Compute_Targeted_Temperature_Workday( void );
static void Compute_Targeted_Temperature_Homeday( void );
static void Regulate_Temperature( void );


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void Boiler_Manager__Stop_Boiler( void )
{
    Relay_Cmd__Open_Circuit();
}
/*----------------------------------------------------------------------------*/
void Boiler_Manager__Pilot_Boiler( void )
{
    Class_Delay* delay_ref = NULL;

    /* Tick the timer of the delay */
    delay_ref = (Class_Delay*)(Boiler_Manager.Anti_Bounce_Delay);
    Class_Triggered_Timer__Tick( delay_ref->My_Timer );

    /* Check which temperature (HIGH or LOW) shall be targeted depending on 
    clock and mode. */
    Compute_Targeted_Temperature();
    /* Pilot the boiler depending on the target temprature value and the 
    measured temperature. */
    Regulate_Temperature();    
}


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Boiler_Mgr_Class__Temperatures_Setting__Increase_Low_Temperature( void )
{
    if( My_Low_Temperature < My_High_Temperature )
    {
        My_Low_Temperature += TEMPERATURE_0_DOT_5_DEG_CELCIUS;
    }
    else
    {
        My_Low_Temperature = My_High_Temperature;
    }
}
/*----------------------------------------------------------------------------*/
void Boiler_Mgr_Class__Temperatures_Setting__Decrease_Low_Temperature( void )
{
    if( My_Low_Temperature > TEMPERATURE_15_DEG_CELCIUS )
    {
        My_Low_Temperature -= TEMPERATURE_0_DOT_5_DEG_CELCIUS;
    }
    else
    {
        My_Low_Temperature = TEMPERATURE_15_DEG_CELCIUS;
    }
}
/*----------------------------------------------------------------------------*/
void Boiler_Mgr_Class__Temperatures_Setting__Increase_High_Temperature( void )
{
    if( My_High_Temperature < TEMPERATURE_25_DEG_CELCIUS )
    {
        My_High_Temperature += TEMPERATURE_0_DOT_5_DEG_CELCIUS;
    }
    else
    {
        My_High_Temperature = TEMPERATURE_25_DEG_CELCIUS;
    }
}
/*----------------------------------------------------------------------------*/
void Boiler_Mgr_Class__Temperatures_Setting__Decrease_High_Temperature( void )
{
    if( My_High_Temperature > My_Low_Temperature )
    {
        My_High_Temperature -= TEMPERATURE_0_DOT_5_DEG_CELCIUS;
    }
    else
    {
        My_High_Temperature = My_Low_Temperature;
    }
}
/*============================================================================*/
void Boiler_Mgr_Class__Temperatures__Get_High_Temperature(
    T_Ambient_Air_Temperature* temperature )
{
    *temperature = My_High_Temperature;
}
/*----------------------------------------------------------------------------*/
void Boiler_Mgr_Class__Temperatures__Get_Low_Temperature(
    T_Ambient_Air_Temperature* temperature )
{
    *temperature = My_Low_Temperature;
}


/*============================================================================*/
/* Private methods definition */
/*============================================================================*/
static void Compute_Targeted_Temperature( void )
{
    E_HTC_Mode operating_mode = LOW_MODE;
    E_Day current_day = MONDAY;
    
    Mode__Get_Operating_Mode( &operating_mode );
    
    /* Regulate the home temperature depending on the operating mode */
    switch( operating_mode )
    {
        case NORMAL_MODE :
            Clock__Get_Day( &current_day );
            switch( current_day )
            {
                case MONDAY :
                    Compute_Targeted_Temperature_Workday();
                    break;
                case TUESDAY :
                    Compute_Targeted_Temperature_Workday();
                    break;
                case WEDNESDAY :
                    Compute_Targeted_Temperature_Homeday();
                    break;
                case THURSDAY :
                    Compute_Targeted_Temperature_Homeday();
                    break;
                case FRIDAY :
                    Compute_Targeted_Temperature_Workday();
                    break;
                case SATURDAY :
                    Compute_Targeted_Temperature_Homeday();
                    break;
                case SUNDAY :
                    Compute_Targeted_Temperature_Homeday();
                    break;
                default :
                    My_Targeted_Temperature = My_Low_Temperature;
                    break;
            }
            break;
        case HIGH_MODE :
            My_Targeted_Temperature = My_High_Temperature;
            break;
        case LOW_MODE :
            My_Targeted_Temperature = My_Low_Temperature;
            break;
        case HOMEDAY_MODE :
            Compute_Targeted_Temperature_Homeday();
            break;
        default :
            My_Targeted_Temperature = My_Low_Temperature;
            break;
    }    
}
/*----------------------------------------------------------------------------*/
static void Compute_Targeted_Temperature_Workday( void )
{
    /*
    During holiday, the target temperature is HIGH from 06:30 to 07:29 and then
    from 17:00 to 21:59.
    */
    uint8_t current_hour = 0;
    uint8_t current_minute = 0;
    Clock__Get_Hour( &current_hour );
    Clock__Get_Minute( &current_minute );


    if(    ( current_hour==6 && current_minute>=30 )    /* 06:30 <-> 06:59 */
        || ( current_hour==7 && current_minute<30 )        /* 07:00 <-> 07:29 */
        || ( current_hour >= 17 && current_hour < 22 )    /* 17:00 <-> 21:59 */
      )
    {
        My_Targeted_Temperature = My_High_Temperature;
    }
    else
    {
        My_Targeted_Temperature = My_Low_Temperature;
    }    
}
/*----------------------------------------------------------------------------*/
static void Compute_Targeted_Temperature_Homeday( void )
{
    /*
    During home day, the target temperature is HIGH from 06:30 to 21:59.
    */
    uint8_t current_hour = 0;
    uint8_t current_minute = 0;
    Clock__Get_Hour( &current_hour );
    Clock__Get_Minute( &current_minute );
    
    
    if(    (current_hour==6 && current_minute>=30) 
        || (current_hour>=7 && current_hour<22)     )
    { /* from 06:30 to 21:59 */
        My_Targeted_Temperature = My_High_Temperature;
    }
    else
    {
        My_Targeted_Temperature = My_Low_Temperature;
    }    
}
/*----------------------------------------------------------------------------*/
static void Regulate_Temperature( void )
{
    T_Ambient_Air_Temperature mesured_temperature = TEMPERATURE_25_DEG_CELCIUS;
    
    Mesured_Temperature__Get_Temperature( &mesured_temperature );

    if( mesured_temperature>=My_Targeted_Temperature )
    {
        Delay__Reset( (Class_Delay*)Boiler_Manager.Anti_Bounce_Delay );
    }
    else if( mesured_temperature<My_Targeted_Temperature )
    {
        Delay__Set( (Class_Delay*)Boiler_Manager.Anti_Bounce_Delay );
    }

    if( true==Delay__Get( (Class_Delay*)Boiler_Manager.Anti_Bounce_Delay ) )
    {
        Relay_Cmd__Close_Circuit();
    }
    else
    {
        Relay_Cmd__Open_Circuit();
    }
}