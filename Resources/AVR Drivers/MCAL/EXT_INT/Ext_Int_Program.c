/*
 * EXT_INT_Program.c
 *
 *  Created on: Sep 26, 2023
 *      Author: Dell
 */

#include "EXT_INT_Config.h"
#include "EXT_INT_Interface.h"
#include "ATmega32_RegisterMap.h"
#include "Bit_Math.h"
#include "GIE_Private.h"

static void (*callback_arr[3])(void) = {NULL};

void EXT_INT_Init(uint8 interruptChannel)
{
#if  EXT_INT0_SENSE_CONTROL == RISING_EDGE
	switch (interruptChannel)
	{
	case EXT_INT0:
		MCUCR = (MCUCR & EXT_INT0_MASK) | RISING_EDGE;
		break;
	case EXT_INT1:
		MCUCR = (MCUCR & EXT_INT1_MASK) | (RISING_EDGE << EXT_INT1_SHIFT);
		break;
	case EXT_INT2:
		MCUCR = (MCUCSR & EXT_INT2_MASK) | (0b1 << EXT_INT2_SHIFT);
		break;
	}
#endif
#if  EXT_INT0_SENSE_CONTROL == FALLING_EDGE
	switch (interruptChannel)
	{
	case EXT_INT0:
		MCUCR = (MCUCR & EXT_INT0_MASK) | FALLING_EDGE;
		break;
	case EXT_INT1:
		MCUCR = (MCUCR & EXT_INT1_MASK) | (FALLING_EDGE << EXT_INT1_SHIFT);
		break;
	case EXT_INT2:
		MCUCR = (MCUCSR & EXT_INT2_MASK) | (0b1 << EXT_INT2_SHIFT);
		break;
	}
#endif
#if  EXT_INT0_SENSE_CONTROL == LOGICAL_CHANGE
	switch (interruptChannel)
	{
	case EXT_INT0:
		MCUCR = (MCUCR & EXT_INT0_MASK) | LOGICAL_CHANGE;
		break;
	case EXT_INT1:
		MCUCR = (MCUCR & EXT_INT1_MASK) | (LOGICAL_CHANGE << EXT_INT1_SHIFT);
		break;
	}

#endif
#if  EXT_INT0_SENSE_CONTROL == LOW_LEVEL
	switch (interruptChannel)
	{
	case EXT_INT0:
		MCUCR = (MCUCR & EXT_INT0_MASK) | LOW_LEVEL;
		break;
	case EXT_INT1:
		MCUCR = (MCUCR & EXT_INT1_MASK) | (LOW_LEVEL << EXT_INT1_SHIFT);
		break;
	}

#endif
}





void EXT_INT_Enable(uint8 interrupt_channel)
{
	switch (interrupt_channel)
	{
	case EXT_INT0:
		SET_BIT(GICR, INT0_BIT);
		break;
	case EXT_INT1:
		SET_BIT(GICR, INT1_BIT);
		break;
	case EXT_INT2:
		SET_BIT(GICR, INT2_BIT);
		break;
	}
}

void EXT_INT_Disable(uint8 interrupt_channel)
{
	switch (interrupt_channel)
	{
	case EXT_INT0:
		CLEAR_BIT(GICR, INT0_BIT);
		break;
	case EXT_INT1:
		CLEAR_BIT(GICR, INT1_BIT);
		break;
	case EXT_INT2:
		CLEAR_BIT(GICR, INT2_BIT);
		break;
	}
}

void EXT_INT_Set_Callback(uint8 interrupt_channel,void (*interruptAction)(void))
{
	callback_arr[interrupt_channel] = interruptAction;
}

ISR (INT0_VECT)
{
	callback_arr[EXT_INT0]();
}
ISR (INT1_VECT)
{
	callback_arr[EXT_INT1]();
}
ISR (INT2_VECT)
{
	callback_arr[EXT_INT2]();
}
