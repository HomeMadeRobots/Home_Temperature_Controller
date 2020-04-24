#include "Setting_Manager.h"


/* Required Component_Prototypes */
#include "HTC_Clock.h"
#include "Boiler_Manager.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
static Setting_Manager_Class_Var Setting_Manager_Var =
{
    /* E_Setting_Mode Setting_Mode */
    NO_SETTING 
};


Setting_Manager_Class Setting_Manager =
{
    /* Variable attributes */
    &Setting_Manager_Var,
    
    /* Required interfaces */
    /* Clock_Setting* Clock_Setting */
    &HTC_Clock__Setting,
    /* Target_Home_Temperatures_Setting Temperature_Setting */
    &Boiler_Manager__Temperatures_Setting
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
const HTC_Setting_Mode Setting_Mgr__Setting_Mode = {
    Setting_Mgr__Setting_Mode__Get_HTC_Setting_Mode
};


