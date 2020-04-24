#include "One_Wire.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const ATmega_One_Wire_Interaction_Layer One_Wire = {
    
    /* Configuration_Parameters */
    /* uint8_t* Pin_Address */
    &PIND,
    /* uint8_t Bit_Index */
    6
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void OneWire__Communication__Send_Simple_Command(
    const T_One_Wire_Device_Address* slave_address,
    uint8_t command )
{
    ATmega_OneWire_IL__Communication__Send_Simple_Command(
        &One_Wire,
        slave_address,
        command );
}

static void OneWire__Communication__Send_Write_Command(
    const T_One_Wire_Device_Address* slave_address,
    uint8_t command,
    const uint8_t* message,
    uint8_t nb_bytes )
{
    ATmega_OneWire_IL__Communication__Send_Write_Command(
        &One_Wire,
        slave_address,
        command,
        message,
        nb_bytes );
}

static void OneWire__Communication__Send_Read_Command(
    const T_One_Wire_Device_Address* slave_address,
    uint8_t command,
    uint8_t* message,
    uint8_t nb_bytes )
{
    ATmega_OneWire_IL__Communication__Send_Read_Command(
        &One_Wire,
        slave_address,
        command,
        message,
        nb_bytes );
}
    
const One_Wire_Protocol One_Wire__Communication =
{
    OneWire__Communication__Send_Simple_Command,
    OneWire__Communication__Send_Write_Command,
    OneWire__Communication__Send_Read_Command
};
 
        



    

