#include "Bit_Math.h"
#include "GIE_Interface.h"
#include "ATmega32_RegisterMap.h"

void GIE_Enable(void)
{
	/* To enable the global interrupt */
	SET_BIT(SREG,I_BIT);
}

void GIE_Disable(void)
{
	/* To disable the global interrupt */
	CLEAR_BIT(SREG,I_BIT);
}

