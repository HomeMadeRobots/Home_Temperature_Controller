#ifndef HTC_MODE_H
#define HTC_MODE_H

#include "E_HTC_Mode.h"

typedef struct {
    void (*Get_Operating_Mode) ( E_HTC_Mode* mode );
} HTC_Mode;

#endif