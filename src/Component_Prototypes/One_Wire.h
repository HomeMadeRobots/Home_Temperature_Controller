#ifndef ONE_WIRE_H
#define ONE_WIRE_H

#include "ATmega_One_Wire_Interaction_Layer.h"


/*============================================================================*/
/* Component_Prototype */
/*============================================================================*/
const ATmega_One_Wire_Interaction_Layer One_Wire;


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
const One_Wire_Protocol One_Wire__Communication;

#endif