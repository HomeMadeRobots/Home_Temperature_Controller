#include "DO_Pin_LCD_Enable.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const Arduino_Discrete_Output_Pin DO_Pin_LCD_Enable = 
{
    /* uint8_t Arduino_Pin_Id */
    9
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void DO_Pin_LCD_Enable__Discrete_Pin__Set_Level( E_IO_Level level )
{
    Arduino_DOP__Discrete_Pin__Set_Level(
        &DO_Pin_LCD_Enable,
        level );
}

const Discrete_Output DO_Pin_LCD_Enable__Discrete_Pin = 
{
    DO_Pin_LCD_Enable__Discrete_Pin__Set_Level
};