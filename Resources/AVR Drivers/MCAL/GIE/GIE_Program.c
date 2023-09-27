/*
 * GIE_program.c
 *
 *  Created on: Sep 26, 2023
 *      Author: Dell
 */
#include"ATmega32_RegisterMap.h"
#include"Bit_Math.h"
void Gie_Enable(void)
{
	SET_BIT(SREG, I_BIT);
}
void Gie_Disable(void)
{
	CLEAR_BIT(SREG, I_BIT);
}

