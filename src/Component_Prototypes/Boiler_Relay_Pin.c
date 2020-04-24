#include "Boiler_Relay_Pin.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const Arduino_Discrete_Output_Pin Boiler_Relay_Pin = {
    
    /* Constant attributes */
    /* uint8_t Arduino_Pin_Id */
    13
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void Boiler_Relay_Pin__Discrete_Pin__Set_Level( E_IO_Level level )
{
    Arduino_DOP__Discrete_Pin__Set_Level( &Boiler_Relay_Pin, level );
}
const Discrete_Output Boiler_Relay_Pin__Discrete_Pin =
{
    Boiler_Relay_Pin__Discrete_Pin__Set_Level
};