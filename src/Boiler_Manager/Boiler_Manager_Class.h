/*============================================================================*/
/* HTC_Boiler_Manager - Project specific sigleton */
/*============================================================================*/

#ifndef BOILER_MANAGER_CLASS_H
#define BOILER_MANAGER_CLASS_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include "T_Ambient_Air_Temperature.h"


/* Realized interfaces */
#include "../Boiler_Manager/Target_Home_Temperatures.h"
#include "../Boiler_Manager/Target_Home_Temperatures_Setting.h"


/* Required interfaces */
#include "Clock_Data.h"
#include "Ambient_Air_Temperature.h"
#include "Relay_Actuation_Requests.h"
#include "../Mode_Manager/HTC_Mode.h"


/* Inner objects */
#include "Class_Turn_On_Off_Delay.h"


/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {
    T_Ambient_Air_Temperature Low_Temperature;
    T_Ambient_Air_Temperature High_Temperature;
    T_Ambient_Air_Temperature Targeted_Temperature;
} Boiler_Manager_Class_Var;

typedef struct {

    /* Variable attributes */
    Boiler_Manager_Class_Var* var_attr;

    /* Required interfaces */
    const Clock_Data* Clock;
    const Ambient_Air_Temperature* Mesured_Temperature;
    const Relay_Actuation_Requests* Relay_Cmd;
    const HTC_Mode* Mode;

    /* Inner objects */
    const Class_Turn_On_Off_Delay* Anti_Bounce_Delay;

} Boiler_Manager_Class;


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void Boiler_Manager__Initialize( void );
void Boiler_Manager__Pilot_Boiler( void );


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Boiler_Mgr_Class__Temperatures_Setting__Increase_Low_Temperature( void );
void Boiler_Mgr_Class__Temperatures_Setting__Decrease_Low_Temperature( void );
void Boiler_Mgr_Class__Temperatures_Setting__Increase_High_Temperature( void );
void Boiler_Mgr_Class__Temperatures_Setting__Decrease_High_Temperature( void );

void Boiler_Mgr_Class__Temperatures__Get_High_Temperature(
    T_Ambient_Air_Temperature* temperature );
void Boiler_Mgr_Class__Temperatures__Get_Low_Temperature(
    T_Ambient_Air_Temperature* temperature );


#endif