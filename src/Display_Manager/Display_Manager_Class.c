#include "Display_Manager_Class.h"

#include <stdio.h> /* sprintf */
#include "Class_Triggered_Timer.h"


static void Print_Air_Temperature( T_Ambient_Air_Temperature temperature );



extern const Display_Manager_Class Display_Manager;

/*============================================================================*/
/* Attributes access */
/*============================================================================*/
#define My_Is_LCD_Backlight_On (Display_Manager.var_attr->Is_LCD_Backlight_On)


/*============================================================================*/
/* Required interfaces access */
/*============================================================================*/
#define Clock__Get_Date \
        Display_Manager.Clock->Get_Date
        
#define Setting_Mode__Get_HTC_Setting_Mode \
        Display_Manager.Setting_Mode->Get_HTC_Setting_Mode
        
#define Mesured_Temperature__Get_Temperature \
        Display_Manager.Mesured_Temperature->Get_Temperature

#define Operating_Mode__Get_Operating_Mode \
        Display_Manager.Operating_Mode->Get_Operating_Mode
        
#define LCD_Cmd__Set_Cursor_Position \
        Display_Manager.LCD_Cmd->Set_Cursor_Position
#define LCD_Cmd__Print \
        Display_Manager.LCD_Cmd->Print
#define LCD_Cmd__Blink_Cursor \
        Display_Manager.LCD_Cmd->Blink_Cursor
#define LCD_Cmd__No_Blink_Cursor \
        Display_Manager.LCD_Cmd->No_Blink_Cursor
#define LCD_Cmd__Turn_On_Backlight \
        Display_Manager.LCD_Cmd->Turn_On_Backlight
#define LCD_Cmd__Turn_Off_Backlight  \
        Display_Manager.LCD_Cmd->Turn_Off_Backlight       
#define LCD_Cmd__Show_Text \
        Display_Manager.LCD_Cmd->Show_Text
#define LCD_Cmd__Hide_Text  \
        Display_Manager.LCD_Cmd->Hide_Text            
        
        
        

/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void Display_Mgr__Update_All_Displays( void )
{
    E_Day current_day = MONDAY;
    uint8_t current_hour = 13;
    uint8_t current_minute = 13;
    uint8_t current_second = 13;
    E_Setting_Mode current_setting_mode = NO_SETTING;
    T_Ambient_Air_Temperature mesured_temp = 0;
    E_HTC_Mode current_operating_mode = NORMAL_MODE;
    
    Class_Triggered_Timer__Tick( Display_Manager.Backlight_Timer );
    
    /* Get data */
    Clock__Get_Date( 
        &current_day, 
        &current_hour, 
        &current_minute, 
        &current_second );
    Setting_Mode__Get_HTC_Setting_Mode( &current_setting_mode );
    Mesured_Temperature__Get_Temperature( &mesured_temp );
    Operating_Mode__Get_Operating_Mode( &current_operating_mode );
    
    /* Update LCD text */
    if( true==My_Is_LCD_Backlight_On )
    {
        LCD_Cmd__Set_Cursor_Position( 1, 1 );
        switch( current_day )
        {
            case MONDAY :
                LCD_Cmd__Print("Monday   ");
                break;
            case TUESDAY :
                LCD_Cmd__Print("Tuesday  ");
                break;
            case WEDNESDAY :
                LCD_Cmd__Print("Wednesday");
                break;
            case THURSDAY :
                LCD_Cmd__Print("Thursday ");
                break;
            case FRIDAY :
                LCD_Cmd__Print("Friday   ");
                break;
            case SATURDAY :
                LCD_Cmd__Print("Saturday ");
                break;
            case SUNDAY :
                LCD_Cmd__Print("Sunday   ");
                break;
            default:
                LCD_Cmd__Print("Unknow   ");
                break;
        }
        
        LCD_Cmd__Set_Cursor_Position( 1, 11 );
        
        /* Display hour */
        char num_str[3];
        sprintf( num_str, "%02d", current_hour );
        LCD_Cmd__Print( num_str );
        
        /* Display ":" */
        LCD_Cmd__Print(":");
        
        /* Display minute */
        sprintf( num_str, "%02d", current_minute );
        LCD_Cmd__Print( num_str );

        /* Display operating mode */
        LCD_Cmd__Set_Cursor_Position( 2, 1 );
        switch( current_operating_mode )
        {
            case NORMAL_MODE :
                LCD_Cmd__Print("Normal    ");
                break;
            case HIGH_MODE :
                LCD_Cmd__Print("High      ");
                break;
            case LOW_MODE :
                LCD_Cmd__Print("Low       ");
                break;
            case HOMEDAY_MODE :
                LCD_Cmd__Print("Home      ");
                break;
            default :
                LCD_Cmd__Print("ERROR     ");
                break;
        }
        
        /* Display mesured air temperature */
        LCD_Cmd__Set_Cursor_Position( 2, 11 );
        Print_Air_Temperature( mesured_temp );
    
        switch( current_setting_mode )
        {
            case NO_SETTING :
                LCD_Cmd__No_Blink_Cursor();
                break;
            case DAY_SETTING :
                LCD_Cmd__Set_Cursor_Position( 1, 1 );
                LCD_Cmd__Blink_Cursor();
                break;
            case HOUR_SETTING :
                LCD_Cmd__Set_Cursor_Position( 1, 12 );
                LCD_Cmd__Blink_Cursor();
                break;
            case MINUTE_SETTING :
                LCD_Cmd__Set_Cursor_Position( 1, 15 );
                LCD_Cmd__Blink_Cursor();
                break;
            case LOW_TEMPERATURE_SETTING :

                break;
            case HIGH_TEMPERATURE_SETTING :

                break;
            default :
                break;            
        }
    }
}


/*============================================================================*/
/* Received events */
/*============================================================================*/
void Display_Mgr__Keypad_Used( void )
{
    My_Is_LCD_Backlight_On = true;
    Display_Mgr__Update_All_Displays();
    LCD_Cmd__Turn_On_Backlight();
    LCD_Cmd__Show_Text();
    
    /* Restart timer for 15s */
    Class_Triggered_Timer__Start( Display_Manager.Backlight_Timer, 3000 );
}


void Display_Mgr__Backlight_Timer__Time_Is_Up( void )
{
    My_Is_LCD_Backlight_On = false;
    LCD_Cmd__Turn_Off_Backlight();
    LCD_Cmd__Hide_Text();
}

static void Print_Air_Temperature( T_Ambient_Air_Temperature temperature )
{
    uint16_t decimal_part = 0;
    uint16_t integer_part = 0;
    
    if( temperature <= 0 )
    {
        LCD_Cmd__Print(" 0.0 C");
    }
    else
    {
        
        decimal_part = ((uint16_t)temperature) & 0x000F;
        integer_part = ((uint16_t)temperature)/16;
        
        /* Print integer part */
        if( integer_part > 99 )
        {
            integer_part = 99;
        }
        char temp_char[3];
        sprintf( temp_char, "%02d", integer_part );
        LCD_Cmd__Print(temp_char);
        
        /* Print decimal part */
        if( decimal_part >= 8 )
        {
            LCD_Cmd__Print(".5 C");
        }
        else
        {
            LCD_Cmd__Print(".0 C");
        }
    }
}
