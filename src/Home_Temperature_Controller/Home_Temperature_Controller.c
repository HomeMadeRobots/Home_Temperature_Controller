#include "Home_Temperature_Controller.h"

#include "../Component_Prototypes/DO_Pin_LCD_Register_Select.h"
#include "../Component_Prototypes/DO_Pin_LCD_Enable.h"
#include "../Component_Prototypes/DO_Pin_LCD_Data_7.h"
#include "../Component_Prototypes/DO_Pin_LCD_Data_6.h"
#include "../Component_Prototypes/DO_Pin_LCD_Data_5.h"
#include "../Component_Prototypes/DO_Pin_LCD_Data_4.h"
#include "../Component_Prototypes/DO_Pin_LCD_Backlight.h"

#include "../Component_Prototypes/Boiler_Relay_Pin.h"

#include "../Component_Prototypes/HTC_LCD.h"

#include "../Component_Prototypes/Air_Temperature_Sensor.h"

#include "../Component_Prototypes/HTC_Keypad.h"

#include "../Component_Prototypes/HTC_Clock.h"

#include "../Component_Prototypes/Display_Manager.h"

#include "../Component_Prototypes/Boiler_Manager.h"

void HTC__Init( void )
{
    Arduino_DOP__Initialize( &DO_Pin_LCD_Register_Select );
    Arduino_DOP__Initialize( &DO_Pin_LCD_Enable );
    Arduino_DOP__Initialize( &DO_Pin_LCD_Data_7 );
    Arduino_DOP__Initialize( &DO_Pin_LCD_Data_6 );
    Arduino_DOP__Initialize( &DO_Pin_LCD_Data_5 );
    Arduino_DOP__Initialize( &DO_Pin_LCD_Data_4 );
    Arduino_DOP__Initialize( &DO_Pin_LCD_Backlight );
    Arduino_DOP__Initialize( &Boiler_Relay_Pin );
    LCD4BDAct__Initialize( &HTC_LCD );
    Boiler_Manager__Initialize();
    Display_Mgr__Initialize();
}

void HTC__Task_5ms( void )
{
    Five_Buttons_Keypad__Cyclic( &HTC_Keypad );
}

void HTC__Task_500ms( void )
{
    Clock__Tick( &HTC_Clock );
}

void HTC__Task_1000ms( void )
{
    DS18B20__Cyclic( &Air_Temperature_Sensor );
    Boiler_Manager__Pilot_Boiler();
    Display_Mgr__Update_All_Displays();
}