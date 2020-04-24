#include "Air_Temperature_Sensor.h"

/* Required Component_Prototypes */
#include "One_Wire.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
DS18B20_Ambient_Air_Temperature_Sensor_Var Air_Temperature_Sensor_Var = {
    /* T_Ambient_Air_Temperature Air_Temperature */
    0,
    /* uint8_t Last_Performed_Action */
    DS18B20_ACTION_READ_SCRATCHPAD
};
const DS18B20_Ambient_Air_Temperature_Sensor Air_Temperature_Sensor = {
    
    /* Variable attributes (ref) */
    &Air_Temperature_Sensor_Var,
    
    /* Required interfaces */
    &One_Wire__Communication,
    
    /* Configuration_Parameter */
    /* T_One_Wire_Device_Address Device_Address */
    { 0x28, 0xEE, 0xF4, 0x79, 0xA2, 0x0, 0x3, 0xFD }
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void Air_Temp_Sensor__Air_Temperature__Get_Air_Temperature( 
    T_Ambient_Air_Temperature* temperature )
{
    DS18B20__Ambient_Air_Temperature__Get_Temperature(
        &Air_Temperature_Sensor,
        temperature );
}
const Ambient_Air_Temperature Air_Temp_Sens__Air_Temperature =
{
    Air_Temp_Sensor__Air_Temperature__Get_Air_Temperature
};