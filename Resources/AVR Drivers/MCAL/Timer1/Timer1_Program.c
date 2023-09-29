#include "ATmega32_RegisterMap.h"
#include "Bit_Math.h"
#include "Timer1_Config.h"
#include "Timer1_Interface.h"
#include "GIE_Private.h"
#include "Timer0_Config.h"

#define TIMER1_PRESCALER_MASK 0b11111000

#define TIMER1_OC1A_MODE_MASK  0b00111111
#define TIMER1_OC1B_MODE_MASK  0b11001111

#define TIMER1_OC1A_SHIFT  6
#define TIMER1_OC1B_SHIFT  4

void Timer1_Init(void)
{
#if(TIMER_1_MODE ==  TIMER1_NORMAL_MODE )
	CLEAR_BIT(TCCR1A, WGM10_BIT);
	CLEAR_BIT(TCCR1A, WGM11_BIT);
	CLEAR_BIT(TCCR1B, WGM12_BIT);
	CLEAR_BIT(TCCR1B, WGM13_BIT);
#elif (TIMER_1_MODE ==  TIMER1_CTC_MODE )
	CLEAR_BIT(TCCR1A, WGM10_BIT);
	CLEAR_BIT(TCCR1A, WGM11_BIT);
	SET_BIT(TCCR1B, WGM12_BIT);
	CLEAR_BIT(TCCR1B, WGM13_BIT);
#elif (TIMER_1_MODE ==  TIMER1_FASTPWM_MODE )
	uint32 arrPrescaler[5] = { 1, 8, 64, 256, 1024 };
	uint32 freqTimer = F_SYS / arrPrescaler[TIMER_1_PRESCALER - 1];
	OCR1A = (freqTimer / TIMER_1_OC1B_FREQ) - 1;
	SET_BIT(TCCR1A, WGM10_BIT);
	SET_BIT(TCCR1A, WGM11_BIT);
	SET_BIT(TCCR1B, WGM12_BIT);
	SET_BIT(TCCR1B, WGM13_BIT);
	TCCR1A = (TCCR1A & TIMER1_OC1B_MODE_MASK) | (TIMER_1_OC1B_MODE << TIMER1_OC1B_SHIFT);
#endif

//	TCCR1A = (TCCR1A & TIMER1_OC1A_MODE_MASK) | (TIMER_1_OC1A_MODE << TIMER1_OC1A_SHIFT);


}

void Timer1_Start(void)
{
	TCCR1B = (TCCR1B & TIMER1_PRESCALER_MASK) | TIMER_1_PRESCALER;
}

void Timer1_SetPWM(uint8 dutyCycle)
{
#if(TIMER_1_OC1B_MODE ==  TIMER0_OC0_PWM_NON_INVERTING)
	OCR1B = ((dutyCycle * (OCR1A+1)) / 100) - 1;
#elif(TIMER_1_OC1B_MODE == TIMER0_OC0_PWM_INVERTING)
	OCR1B = OCR1A - (((dutyCycle * (OCR1A+1))/100)-1);
#endif

}

