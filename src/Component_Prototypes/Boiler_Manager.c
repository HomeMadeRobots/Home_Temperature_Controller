#include "Boiler_Manager.h"


/* Required Component_Prototypes */
/* Clock_Data */
#include "HTC_Clock.h"

/* Mesured_Temperature */
#include "Air_Temperature_Sensor.h"

/* Relay_Cmd */
#include "Boiler_Relay_Actuator.h"

/* Mode */
#include "Mode_Manager.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
static Boiler_Manager_Class_Var Boiler_Manager_Attr =
{
    /* T_Ambient_Air_Temperature Low_Temperature */
    TEMPERATURE_15_DEG_CELCIUS,
    /* T_Ambient_Air_Temperature High_Temperature */
    TEMPERATURE_25_DEG_CELCIUS,
    /* T_Ambient_Air_Temperature Targeted_Temperature */
    TEMPERATURE_15_DEG_CELCIUS
};

const Boiler_Manager_Class Boiler_Manager =
{
    /* Variable attributes */
    &Boiler_Manager_Attr,
    
    /* Required interfaces */
    /* Clock:Clock_Data */
    &HTC_Clock__Data,
    /* Mesured_Temperature:Ambient_Air_Temperature */
    &Air_Temp_Sens__Air_Temperature,
    /* Relay_Cmd:Relay_Actuation_Requests */
    &Boiler_Relay_Actuator__Relay_Actuation,
    /* Mode HTC_Mode */
    &Mode_Mgr__Operating_Mode
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
const Target_Home_Temperatures_Setting Boiler_Manager__Temperatures_Setting =
{
    Boiler_Mgr_Class__Temperatures_Setting__Increase_Low_Temperature,
    Boiler_Mgr_Class__Temperatures_Setting__Decrease_Low_Temperature,
    Boiler_Mgr_Class__Temperatures_Setting__Increase_High_Temperature,
    Boiler_Mgr_Class__Temperatures_Setting__Decrease_High_Temperature
};
/*----------------------------------------------------------------------------*/
const Target_Home_Temperatures HTC_Boiler_Manager__Temperatures =
{
    Boiler_Mgr_Class__Temperatures__Get_High_Temperature,
    Boiler_Mgr_Class__Temperatures__Get_Low_Temperature
};