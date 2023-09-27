#include "ADC_Interface.h"
#include "Bit_Math.h"
#include "ATmega32_RegisterMap.h"

void ADC_Init (void)
{
	//frequency setting
	MASK_SET(ADCSRA, ADC_PRESCALER_MASK, ADC_PRESCALER_FACTOR, ADC_PRESCALER_SHIFT);

	//channel setting
	MASK_SET(ADMUX, ADC_CHANNEL_MASK, ADC_CHANNEL, ADC_CHANNEL_SHIFT);

	//left or right adjustment (right in this case)
	CLEAR_BIT(ADMUX,ADLAR_BIT);

	//Vref setting
	MASK_SET(ADMUX, ADC_REF_MASK, ADC_REF, ADC_REF_SHIFT );

}

void ADC_Enable (void)
{
	SET_BIT(ADCSRA, ADEN_BIT);
}

void ADC_Disable (void)
{
	CLEAR_BIT(ADCSRA, ADEN_BIT);
}


uint16 ADC_Read (void)
{
	SET_BIT(ADCSRA, ADSC_BIT);
	while (IS_BIT_CLEARED(ADCSRA, ADIF_BIT));
	return ADC_VAL;
}
