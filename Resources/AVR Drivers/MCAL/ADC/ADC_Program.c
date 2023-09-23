#include "ATmega32_RegisterMap.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "Bit_Math.h"

void ADC_Init(void)
{
#if   ADC_V_REF   ==   AVCC
	SET_BIT(ADMUX,REFS0_BIT);
	CLEAR_BIT(ADMUX,REFS1_BIT);
#elif ADC_V_REF   ==   AREF_PIN
	CLEAR_BIT(ADMUX,REFS0_BIT);
	CLEAR_BIT(ADMUX,REFS1_BIT);
#elif ADC_V_REF   ==   _2V56
	SET_BIT(ADMUX,REFS0_BIT);
	SET_BIT(ADMUX,REFS1_BIT);
#endif

	/* To select right adjustment */
	CLEAR_BIT(ADMUX,ADLAR_BIT);

	/* To select an ADC channel */
	ADMUX = (ADMUX & 0b11100000) | ADC_CHANNEL;

	/* To select the ADC frequency */
	ADCSRA = (ADCSRA & 0b11111000) | ADC_PRESCALER;

	/* To enable ADC circuit */
	SET_BIT(ADCSRA,ADEN_BIT);
}

uint16  ADC_Read(void)
{
	/* To start conversion */
	SET_BIT(ADCSRA,ADSC_BIT);
	while(IS_BIT_CLEARED(ADCSRA,ADIF_BIT));
	return ADC_VALUE;
}
