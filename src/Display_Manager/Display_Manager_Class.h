#ifndef DISPLAY_MANAGER_CLASS_H
#define DISPLAY_MANAGER_CLASS_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include <stdbool.h>


/* Required interfaces */
#include "Clock_Data.h"
#include "../Setting_Manager/HTC_Setting_Mode.h"
#include "LCD_Commands.h"
#include "LCD_Special_Character_Config.h"
#include "Ambient_Air_Temperature.h"
#include "../Mode_Manager/HTC_Mode.h"
#include "../Boiler_Manager/Target_Home_Temperatures.h"


/* Associated objects */
#include "Class_Triggered_Timer.h"


/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {
    bool Is_LCD_Backlight_On;
} Display_Manager_Class_Var;

typedef struct {

    /* Variable attributes */
    Display_Manager_Class_Var* var_attr;
    
    /* Required interfaces */
    const Clock_Data* Clock;
    const HTC_Setting_Mode* Setting_Mode;
    const LCD_Commands* LCD_Cmd;
    const LCD_Special_Character_Config* LCD_Config;
    const Ambient_Air_Temperature* Mesured_Temperature;
    const HTC_Mode* Operating_Mode;
    const Target_Home_Temperatures* Target_Temperatures;
    
    /* Associated objects */
    const Class_Triggered_Timer* Backlight_Timer;

} Display_Manager_Class;


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void Display_Mgr__Initialize( void );
void Display_Mgr__Update_All_Displays( void );


/*============================================================================*/
/* Received events */
/*============================================================================*/
void Display_Mgr__Keypad_Used( void );


/* Internal event */
void Display_Mgr__Backlight_Timer__Time_Is_Up( void );

#endif