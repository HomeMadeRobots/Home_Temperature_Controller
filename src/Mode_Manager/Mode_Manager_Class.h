#ifndef MODE_MANAGER_CLASS_H
#define MODE_MANAGER_CLASS_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include <stdbool.h>
#include "E_HTC_Mode.h"


/* Realized interfaces */
#include "HTC_Mode.h"


/* Received events */
#include "Button_Pressed.h"



/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {
    E_HTC_Mode Current_Operating_Mode;
} Mode_Manager_Class_Var;

typedef struct {

    /* Variable attributes */
    Mode_Manager_Class_Var* var_attr;

} Mode_Manager_Class;


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Mode_Mgr__Operating_Mode__Get_Operating_Mode( E_HTC_Mode* mode );


/*============================================================================*/
/* Received events */
/*============================================================================*/
void Mode_Mgr__Mode_Button_Pressed( void );


#endif