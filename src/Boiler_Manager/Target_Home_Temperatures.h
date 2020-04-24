#ifndef TARGET_HOME_TEMPERATURES_H
#define TARGET_HOME_TEMPERATURES_H

typedef struct {
    void (*Get_High_Temperature) ( T_Ambient_Air_Temperature* temperature );
    void (*Get_Low_Temperature) ( T_Ambient_Air_Temperature* temperature );
} Target_Home_Temperatures;

#endif