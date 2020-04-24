#include "Setting_Manager_Class.h"


extern const Setting_Manager_Class Setting_Manager;


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Setting_Mgr__Setting_Mode__Get_HTC_Setting_Mode( E_Setting_Mode* mode )
{
    *mode = Setting_Manager.var_attr->Setting_Mode;
}


/*============================================================================*/
/* Received events */
/*============================================================================*/
void Setting_Mgr__Increase_Setting_Button_Pressed( void )
{
    switch( Setting_Manager.var_attr->Setting_Mode )
	{
		case NO_SETTING :
			break;
		case DAY_SETTING :
            Setting_Manager.Clock_Setting->Increment_Day();
			break;
		case HOUR_SETTING :
			Setting_Manager.Clock_Setting->Increment_Hour();
			break;
		case MINUTE_SETTING :
			Setting_Manager.Clock_Setting->Increment_Minute();
			break;
        case LOW_TEMPERATURE_SETTING :
            
			break;
		case HIGH_TEMPERATURE_SETTING :
            
			break;
		default :
			break;
	}
}
/*----------------------------------------------------------------------------*/
void Setting_Mgr__Decrease_Setting_Button_Pressed( void )
{
    switch( Setting_Manager.var_attr->Setting_Mode )
	{
		case NO_SETTING :
			break;
		case DAY_SETTING :
            Setting_Manager.Clock_Setting->Decrement_Day();
			break;
		case HOUR_SETTING :
			Setting_Manager.Clock_Setting->Decrement_Hour();
			break;
		case MINUTE_SETTING :
			Setting_Manager.Clock_Setting->Decrement_Minute();
			break;
        case LOW_TEMPERATURE_SETTING :

			break;
		case HIGH_TEMPERATURE_SETTING :

			break;
		default :
			break;
	}
}
/*----------------------------------------------------------------------------*/
void Setting_Mgr__Next_Setting_Button_Pressed( void )
{
    switch( Setting_Manager.var_attr->Setting_Mode )
	{
		case NO_SETTING :
			Setting_Manager.var_attr->Setting_Mode = DAY_SETTING;
			break;
		case DAY_SETTING :
			Setting_Manager.var_attr->Setting_Mode = HOUR_SETTING;
			break;
		case HOUR_SETTING :
			Setting_Manager.var_attr->Setting_Mode = MINUTE_SETTING;
			break;
		case MINUTE_SETTING :
			Setting_Manager.var_attr->Setting_Mode = LOW_TEMPERATURE_SETTING;
			break;
        case LOW_TEMPERATURE_SETTING :
			Setting_Manager.var_attr->Setting_Mode = HIGH_TEMPERATURE_SETTING;
			break;
		case HIGH_TEMPERATURE_SETTING :
			Setting_Manager.var_attr->Setting_Mode = NO_SETTING;
			break;
		default :
			break;
	}
}
/*----------------------------------------------------------------------------*/
void Setting_Mgr__Previous_Setting_Button_Pressed( void )
{
    switch( Setting_Manager.var_attr->Setting_Mode )
	{
		case NO_SETTING :
			Setting_Manager.var_attr->Setting_Mode = HIGH_TEMPERATURE_SETTING;
			break;
		case DAY_SETTING :
			Setting_Manager.var_attr->Setting_Mode = NO_SETTING;
			break;
		case HOUR_SETTING :
			Setting_Manager.var_attr->Setting_Mode = DAY_SETTING;
			break;
		case MINUTE_SETTING :
			Setting_Manager.var_attr->Setting_Mode = HOUR_SETTING;
			break;
        case LOW_TEMPERATURE_SETTING :
			Setting_Manager.var_attr->Setting_Mode = MINUTE_SETTING;
			break;
		case HIGH_TEMPERATURE_SETTING :
			Setting_Manager.var_attr->Setting_Mode = LOW_TEMPERATURE_SETTING;
			break;
		default :
			break;
	}
}