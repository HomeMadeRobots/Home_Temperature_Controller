#include "Mode_Manager.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
static Mode_Manager_Class_Var Mode_Manager_Var =
{
    /* E_HTC_Mode Current_HTC_Mode */
    NORMAL_MODE
};

Mode_Manager_Class Mode_Manager =
{
    /* Variable attributes */
    &Mode_Manager_Var
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
const HTC_Mode Mode_Mgr__Operating_Mode =
{
    Mode_Mgr__Operating_Mode__Get_Operating_Mode
};