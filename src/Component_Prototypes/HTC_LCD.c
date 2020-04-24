#include "HTC_LCD.h"

#include "DO_Pin_LCD_Data_4.h"
#include "DO_Pin_LCD_Data_5.h"
#include "DO_Pin_LCD_Data_6.h"
#include "DO_Pin_LCD_Data_7.h"
#include "DO_Pin_LCD_Enable.h"
#include "DO_Pin_LCD_Register_Select.h"
#include "DO_Pin_LCD_Backlight.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
static LCD_HD44780_4Bit_Actuator_Var HTC_LCD_Var =
{
    /* uint8_t Display_Settings_Cmd */
    0b00001100 /* display on, cursor off */
};

const LCD_HD44780_4Bit_Actuator HTC_LCD =
{
    /* Variable attributes */
    &HTC_LCD_Var,
    
    /* Required services */
    /* Register_Select_Pin:Discrete_Output* */
    &DO_Pin_LCD_Register_Select__Discrete_Pin,
    /* Enable_Pin:Discrete_Output* */
    &DO_Pin_LCD_Enable__Discrete_Pin,
    /* Data_4, Data_5, Data_6, Data_ 7 */
    { &DO_Pin_LCD_Data_4__Discrete_Pin, &DO_Pin_LCD_Data_5__Discrete_Pin ,
      &DO_Pin_LCD_Data_6__Discrete_Pin, &DO_Pin_LCD_Data_7__Discrete_Pin },
    &DO_Pin_LCD_Backlight__Discrete_Pin,
    
    /* Constant attributes */
    /* Font_Configuration : uint8_t:1 */
    LCD_CONFIG_FONT_5x8,
    /* Number_Lines_Configuration : uint8_t:1 */
    LCD_CONFIG_NB_LINES_2,
    /* Number_Colomns_Configuration : uint8_t:3 */
    LCD_CONFIG_NB_COLUMNS_16
};


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
static void HTC_LCD__Commands__Set_Cursor_Position(
    uint8_t row_index,
    uint8_t colomn_index )
{
    LCD4BDAct__Commands__Set_Cursor_Position(
        &HTC_LCD,
        row_index,
        colomn_index );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Print(
    char* text )
{
    LCD4BDAct__Commands__Print(
        &HTC_LCD,
        text );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Print_Special_Character(
    uint8_t special_character_idx)
{
    LCD4BDAct__Commands__Print_Special_Character(
        &HTC_LCD,
        special_character_idx );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Hide_Cursor( void )
{
    LCD4BDAct__Commands__Hide_Cursor( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Show_Cursor( void )
{
    LCD4BDAct__Commands__Show_Cursor( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Blink_Cursor( void )
{
    LCD4BDAct__Commands__Blink_Cursor( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__No_Blink_Cursor( void )
{
    LCD4BDAct__Commands__No_Blink_Cursor( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Hide_Text( void )
{
    LCD4BDAct__Commands__Hide_Text( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Show_Text( void )
{
    LCD4BDAct__Commands__Show_Text( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Clear_Text( void )
{
    LCD4BDAct__Commands__Clear_Text( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Turn_Off_Backlight( void )
{
    LCD4BDAct__Commands__Turn_Off_Backlight( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
static void HTC_LCD__Commands__Turn_On_Backlight( void )
{
    LCD4BDAct__Commands__Turn_On_Backlight( &HTC_LCD );
}
/*----------------------------------------------------------------------------*/
const LCD_Commands HTC_LCD__Commands = 
{
    HTC_LCD__Commands__Set_Cursor_Position,
    HTC_LCD__Commands__Print,
    HTC_LCD__Commands__Print_Special_Character,
    HTC_LCD__Commands__Hide_Cursor,
    HTC_LCD__Commands__Show_Cursor,
    HTC_LCD__Commands__Blink_Cursor,
    HTC_LCD__Commands__No_Blink_Cursor,
    HTC_LCD__Commands__Hide_Text,
    HTC_LCD__Commands__Show_Text,
    HTC_LCD__Commands__Clear_Text,
    HTC_LCD__Commands__Turn_Off_Backlight,
    HTC_LCD__Commands__Turn_On_Backlight
};
/*============================================================================*/
static void HTC_LCD__Special_Character_Config__Create_Character(
    uint8_t special_character_id,
    uint8_t* char_map )
{
    LCD4BDAct__Special_Character_Config__Create_Character(
        &HTC_LCD,
        special_character_id,
        char_map );
}
/*----------------------------------------------------------------------------*/
const LCD_Special_Character_Config HTC_LCD__Special_Character_Config =
{
    HTC_LCD__Special_Character_Config__Create_Character
};