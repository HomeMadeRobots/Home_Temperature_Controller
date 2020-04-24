#ifndef TARGET_HOME_TEMPERATURES_SETTING_H
#define TARGET_HOME_TEMPERATURES_SETTING_H


typedef struct {
    void (*Increase_Low_Temperature) ( void );
    void (*Decrease_Low_Temperature) ( void );
    void (*Increase_High_Temperature) ( void );
    void (*Decrease_High_Temperature) ( void );
} Target_Home_Temperatures_Setting;

#endif