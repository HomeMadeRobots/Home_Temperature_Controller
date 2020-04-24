#ifndef HTC_SETTING_MODE_H
#define HTC_SETTING_MODE_H

#include "E_Setting_Mode.h"

typedef struct {
    void (*Get_HTC_Setting_Mode) ( E_Setting_Mode* mode );
} HTC_Setting_Mode;

#endif