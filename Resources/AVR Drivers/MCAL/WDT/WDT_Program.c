#include "WDT_Interface.h"
#include "ATmega32_RegisterMap.h"
#include "Bit_Math.h"

#define WDT_PRESCALER_MASK 0b11111000

void WDT_Enable(void)
{
	SET_BIT(WDTCR, WDE_BIT);
}

void WDT_Disable(void)
{
	WDTCR |= (1<<WDTOE_BIT) | (1<<WDE_BIT);
	CLEAR_BIT(WDTCR, WDE_BIT);
}

void WDT_Sleep(uint8 timeOut)
{
	WDTCR = (WDTCR & WDT_PRESCALER_MASK) | timeOut;
}

void WDT_Refresh(void)
{
	asm("WDR");
}
