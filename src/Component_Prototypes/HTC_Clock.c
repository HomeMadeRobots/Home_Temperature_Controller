#include "HTC_Clock.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
Clock_Var HTC_Clock_Var = {
    /* uint32_t Clock_Timestamp */
    0,
    /* uint32_t Time_Carrier */
    0,
    /* E_Day Day */
    SUNDAY,
    /* uint8_t Hour */
    11,
    /* uint8_t Minute */
    30,
    /* uint8_t Second */
    0
};

const Clock HTC_Clock = {
    /* Variable attributes */
    &HTC_Clock_Var,
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void HTC_Clock__Data__Get_Date( 
    E_Day* day,
    uint8_t* hour,
    uint8_t* minute,
    uint8_t* second )
{
    Clock__Data__Get_Date( &HTC_Clock, day, hour, minute, second );
}
static void HTC_Clock__Data__Get_Day( E_Day* day )
{
    Clock__Data__Get_Day( &HTC_Clock, day );
}
static void HTC_Clock__Data__Get_Hour( uint8_t* hour )
{
    Clock__Data__Get_Hour( &HTC_Clock, hour );
}
static void HTC_Clock__Data__Get_Minute( uint8_t* minute )
{
    Clock__Data__Get_Minute( &HTC_Clock, minute );
}
static void HTC_Clock__Data__Get_Second( uint8_t* second )
{
    Clock__Data__Get_Second( &HTC_Clock, second );
}

const Clock_Data HTC_Clock__Data = {
    HTC_Clock__Data__Get_Date,
    HTC_Clock__Data__Get_Day,
    HTC_Clock__Data__Get_Hour,
    HTC_Clock__Data__Get_Minute,
    HTC_Clock__Data__Get_Second
};
/*----------------------------------------------------------------------------*/

static void HTC_Clock__Setting__Increment_Day( void )
{
    Clock__Setting__Increment_Day( &HTC_Clock );
}
static void HTC_Clock__Setting__Increment_Hour( void )
{
    Clock__Setting__Increment_Hour( &HTC_Clock );
}
static void HTC_Clock__Setting__Increment_Minute( void )
{
    Clock__Setting__Increment_Minute( &HTC_Clock );
}
static void HTC_Clock__Setting__Increment_Second( void )
{
    Clock__Setting__Increment_Second( &HTC_Clock );
}
static void HTC_Clock__Setting__Decrement_Day( void )
{
    Clock__Setting__Decrement_Day( &HTC_Clock );
}
static void HTC_Clock__Setting__Decrement_Hour( void )
{
    Clock__Setting__Decrement_Hour( &HTC_Clock );
}
static void HTC_Clock__Setting__Decrement_Minute( void )
{
    Clock__Setting__Decrement_Minute( &HTC_Clock );
}
static void HTC_Clock__Setting__Decrement_Second( void )
{
    Clock__Setting__Decrement_Second( &HTC_Clock );
}

const Clock_Setting HTC_Clock__Setting =
{
    HTC_Clock__Setting__Increment_Day,
    HTC_Clock__Setting__Increment_Hour,
    HTC_Clock__Setting__Increment_Minute,
    HTC_Clock__Setting__Increment_Second,
    HTC_Clock__Setting__Decrement_Day,
    HTC_Clock__Setting__Decrement_Hour,
    HTC_Clock__Setting__Decrement_Minute,
    HTC_Clock__Setting__Decrement_Second
};