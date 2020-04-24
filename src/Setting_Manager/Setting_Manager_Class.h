#ifndef SETTING_MANAGER_CLASS_H
#define SETTING_MANAGER_CLASS_H



/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include "E_Setting_Mode.h"


/* Realized interfaces */
#include "HTC_Setting_Mode.h"


/* Required interfaces */
#include "Clock_Setting.h"
#include "../Boiler_Manager/Target_Home_Temperatures_Setting.h"


/* Received events */
#include "Button_Pressed.h"


/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {
    E_Setting_Mode Setting_Mode;
} Setting_Manager_Class_Var;

typedef struct {

    /* Variable attributes */
    Setting_Manager_Class_Var* var_attr;
    
    /* Required interfaces */
    const Clock_Setting* Clock_Setting;
    const Target_Home_Temperatures_Setting* Temperature_Setting;
    
} Setting_Manager_Class;


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Setting_Mgr__Setting_Mode__Get_HTC_Setting_Mode( E_Setting_Mode* mode );


/*============================================================================*/
/* Received events */
/*============================================================================*/
void Setting_Mgr__Increase_Setting_Button_Pressed( void );
void Setting_Mgr__Decrease_Setting_Button_Pressed( void );
void Setting_Mgr__Next_Setting_Button_Pressed( void );
void Setting_Mgr__Previous_Setting_Button_Pressed( void );


#endif