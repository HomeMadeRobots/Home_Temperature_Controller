#include "Display_Manager.h"



/* Required Component_Prototypes */
#include "HTC_Clock.h"
#include "Setting_Manager.h"
#include "HTC_LCD.h"
#include "Air_Temperature_Sensor.h"
#include "Mode_Manager.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
Class_Triggered_Timer_Var Backlight_Timer_Var = 
{
    /* uint32_t Counter */
    30 /* 15s */
};

Class_Triggered_Timer Backlight_Timer =
{
    /* Sent events */
    /* Time_Is_Up( void ) */
    Display_Mgr__Backlight_Timer__Time_Is_Up,

    /* Variable attributes */
    &Backlight_Timer_Var,

    /* Constants attributes */
    /* uint32_t Recurrence */
    500
};



static Display_Manager_Class_Var Display_Manager_Var =
{
    /* bool Is_LCD_Backlight_On */
    true
};

const Display_Manager_Class Display_Manager =
{
    /* Variable attributes */
    &Display_Manager_Var,
    
    /* Required interfaces */
    /* Clock_Data* Clock */
    &HTC_Clock__Data,
    /* HTC_Setting_Mode* Setting_Mode */
    &Setting_Mgr__Setting_Mode,
    /* LCD_Commands* LCD_Cmd */
    &HTC_LCD__Commands,
    /* LCD_Special_Character_Config* LCD_Config */
    &HTC_LCD__Special_Character_Config,
    /* Ambient_Air_Temperature* Mesured_Temperature */
    &Air_Temp_Sens__Air_Temperature,
    /* HTC_Mode* Operating_Mode */
    &Mode_Mgr__Operating_Mode,
    
    /* Associated objects */
    &Backlight_Timer
};