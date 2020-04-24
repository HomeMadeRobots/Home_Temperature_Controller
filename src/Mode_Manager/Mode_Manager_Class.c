#include "Mode_Manager_Class.h"


extern const Mode_Manager_Class Mode_Manager;


/*============================================================================*/
/* Attribute access */
/*============================================================================*/
#define My_Current_Operating_Mode \
        (Mode_Manager.var_attr->Current_Operating_Mode)


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Mode_Mgr__Operating_Mode__Get_Operating_Mode( E_HTC_Mode* mode )
{
    *mode = My_Current_Operating_Mode;
}


/*============================================================================*/
/* Received events */
/*============================================================================*/
void Mode_Mgr__Mode_Button_Pressed( void )
{
    if( My_Current_Operating_Mode == NORMAL_MODE )
    {
        My_Current_Operating_Mode = HIGH_MODE;
    }
    else if( My_Current_Operating_Mode == HIGH_MODE )
    {
        My_Current_Operating_Mode = LOW_MODE;
    }
    else if( My_Current_Operating_Mode == LOW_MODE )
    {
        My_Current_Operating_Mode = HOMEDAY_MODE;
    }
    else if( My_Current_Operating_Mode == HOMEDAY_MODE )
    {
        My_Current_Operating_Mode = NORMAL_MODE;
    }
    else
    {
        My_Current_Operating_Mode = LOW_MODE;
    }
}