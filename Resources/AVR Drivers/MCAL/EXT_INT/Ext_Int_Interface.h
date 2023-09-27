/*
 * EXT_INT_Interface.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Dell
 */

#ifndef MCAL_EXT_INT_EXT_INT_INTERFACE_H_
#define MCAL_EXT_INT_EXT_INT_INTERFACE_H_

#include "STD_Types.h"
#define EXT_INT0 0
#define EXT_INT1 1
#define EXT_INT2 2

void EXT_INT_Init(uint8 interrupt_channel);
void EXT_INT_Enable(uint8 interrupt_channel);
void EXT_INT_Disable(uint8 interrupt_channel);
void EXT_INT_Set_Callback(uint8 interrupt_channel,void (*interruptAction)(void));

#endif /* MCAL_EXT_INT_EXT_INT_INTERFACE_H_ */
