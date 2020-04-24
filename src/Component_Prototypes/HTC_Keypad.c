#include "HTC_Keypad.h"

/* Required Component_Prototypes */
#include "Keypad_Pin.h"

/* Event receiver Component_Prototypes */
#include "Setting_Manager.h"
#include "Display_Manager.h"
#include "Mode_Manager.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const Five_Buttons_Keypad HTC_Keypad = {
    
    /* Required interfaces */
    /* Analogic_Input* Analog_Pin */
    &Keypad_Pin__Analogic_Pin,

    /* Sent events */
    /* Button_Pressed Select_Button_Pressed */
    HTC_Keypad__Select_Button_Pressed,
    /* Button_Pressed Up_Button_Pressed */
    HTC_Keypad__Up_Button_Pressed,
    /* Button_Pressed Down_Button_Pressed */
    HTC_Keypad__Down_Button_Pressed,
    /* Button_Pressed Left_Button_Pressed */
    HTC_Keypad__Left_Button_Pressed,
    /* Button_Pressed Right_Button_Pressed */
    HTC_Keypad__Right_Button_Pressed,
    /* Any_Button_Pressed Any_Button_Pressed */
    HTC_Keypad__Any_Button_Pressed,

    /* Configuration_Parameters */
    /* T_Voltage No_Button_Threshold */
    1000,
    /* T_Voltage Select_Button_Threshold */
    650,
    /* T_Voltage Left_Button_Threshold */
    450,
    /* T_Voltage Down_Button_Threshold */
    250,
    /* T_Voltage Up_Button_Threshold */
    50
};


/*============================================================================*/
/* Sent events */
/*============================================================================*/
void HTC_Keypad__Select_Button_Pressed( void )
{
    Mode_Mgr__Mode_Button_Pressed();
}
void HTC_Keypad__Up_Button_Pressed( void )
{
    Setting_Mgr__Increase_Setting_Button_Pressed();
}
void HTC_Keypad__Down_Button_Pressed( void )
{
   Setting_Mgr__Decrease_Setting_Button_Pressed();
}
void HTC_Keypad__Left_Button_Pressed( void )
{
    Setting_Mgr__Previous_Setting_Button_Pressed();
}
void HTC_Keypad__Right_Button_Pressed( void )
{
    Setting_Mgr__Next_Setting_Button_Pressed();
}
void HTC_Keypad__Any_Button_Pressed( E_Button_Id Pressed_Button )
{
    Display_Mgr__Keypad_Used();
}