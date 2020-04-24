#ifndef HTC_KEYPAD_H
#define HTC_KEYPAD_H

#include "Five_Buttons_Keypad.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const Five_Buttons_Keypad HTC_Keypad;


/*============================================================================*/
/* Sent events */
/*============================================================================*/
void HTC_Keypad__Select_Button_Pressed( void );
void HTC_Keypad__Up_Button_Pressed( void );
void HTC_Keypad__Down_Button_Pressed( void );
void HTC_Keypad__Left_Button_Pressed( void );
void HTC_Keypad__Right_Button_Pressed( void );
void HTC_Keypad__Any_Button_Pressed( E_Button_Id Pressed_Button );


#endif