#ifndef DIGITAL_CLOCK_LCD_H
#define DIGITAL_CLOCK_LCD_H

#include "LCD_HD44780_4Bit_Actuator.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const LCD_HD44780_4Bit_Actuator HTC_LCD;


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
const LCD_Commands HTC_LCD__Commands;
const LCD_Special_Character_Config HTC_LCD__Special_Character_Config;


#endif