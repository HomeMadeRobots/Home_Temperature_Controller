#include "DO_Pin_LCD_Data_7.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const Arduino_Discrete_Output_Pin DO_Pin_LCD_Data_7 = 
{
    /* uint8_t Arduino_Pin_Id */
    7
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void DO_Pin_LCD_Data_7__Discrete_Pin__Set_Level( E_IO_Level level )
{
    Arduino_DOP__Discrete_Pin__Set_Level(
        &DO_Pin_LCD_Data_7,
        level );
}

const Discrete_Output DO_Pin_LCD_Data_7__Discrete_Pin = 
{
    DO_Pin_LCD_Data_7__Discrete_Pin__Set_Level
};