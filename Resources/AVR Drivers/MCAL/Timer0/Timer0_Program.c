#include "ATmega32_RegisterMap.h"
#include "Bit_Math.h"
#include "Timer0_Config.h"
#include "Timer0_Interface.h"
#include "GIE_Private.h"

#define TIMER0_PRESCALER_MASK 0b11111000

#define TIMER0_OC0_MODE_MASK  0b11001111

#define TIMER0_OC0_SHIFT  4


static void (*Timer0_CallBack[2]) (void) = {NULL};

static uint32 Timer0_NumOfOverflows = 0;
static uint8  Timer0_RemTicks = 0;
//static uint32 Timer0_NumOfCm = 0;

void Timer0_Init(void)
{
#if(TIMER_0_MODE ==  TIMER0_NORMAL_MODE )
	CLEAR_BIT(TCCR0, WGM00_BIT);
	CLEAR_BIT(TCCR0, WGM01_BIT);
#elif (TIMER_0_MODE ==  TIMER0_CTC_MODE )
	CLEAR_BIT(TCCR0,WGM00_BIT);
	SET_BIT(TCCR0,WGM01_BIT);
#elif (TIMER_0_MODE ==  TIMER0_PHASECORRECT_MODE )
	SET_BIT(TCCR0,WGM00_BIT);
	CLEAR_BIT(TCCR0,WGM01_BIT);
#elif (TIMER_0_MODE ==  TIMER0_FASTPWM_MODE )
	SET_BIT(TCCR0,WGM00_BIT);
	SET_BIT(TCCR0,WGM01_BIT);
#endif

	TCCR0 = (TCCR0 & TIMER0_OC0_MODE_MASK) | (TIMER_0_OC0_MODE << TIMER0_OC0_SHIFT);

}

void Timer0_SetTime(uint32 timeInMS)
{
	uint32 arrPrescaler[5] = { 1, 8, 64, 256, 1024 };
	uint32 freqTimer = F_SYS / arrPrescaler[TIMER_0_PRESCALER - 1];
	uint64 totalTicks = (timeInMS * (uint64)freqTimer) / 1000;

	Timer0_NumOfOverflows = totalTicks / 256;
	Timer0_RemTicks = totalTicks % 256;
	if (Timer0_RemTicks != 0)
	{
		TCNT0 = 256 - Timer0_RemTicks;
		Timer0_NumOfOverflows++;
	}
}

void Timer0_Start(void)
{
	TCCR0= (TCCR0 & TIMER0_PRESCALER_MASK) | TIMER_0_PRESCALER;
}

void Timer0_Stop(void)
{
	CLEAR_BIT(TCCR0,CS00_BIT);
	CLEAR_BIT(TCCR0,CS01_BIT);
	CLEAR_BIT(TCCR0,CS02_BIT);
}

void Timer0_EnableInt(uint8 intId)
{
	switch (intId) {
	case TIMER0_OVERFLOW_INT_ID:
		SET_BIT(TIMSK, TOIE0_BIT);
		break;
	case TIMER0_COMP_MATCH_INT_ID:
		SET_BIT(TIMSK, OCIE0_BIT);
		break;
	default:
		break;
	}
}

void Timer0_DisableInt(uint8 intId)
{
	switch (intId) {
	case TIMER0_OVERFLOW_INT_ID:
		CLEAR_BIT(TIMSK, TOIE0_BIT);
		break;
	case TIMER0_COMP_MATCH_INT_ID:
		CLEAR_BIT(TIMSK, OCIE0_BIT);
		break;
	default:
		break;
	}
}

void Timer0_SetCallBack(uint8 intId, void (* interruptAction)(void))
{
	Timer0_CallBack[intId] = interruptAction;
}

void Timer0_SetPWM(uint8 dutyCycle) {
#if(TIMER_0_MODE ==  TIMER0_FASTPWM_MODE )

	#if(TIMER_0_OC0_MODE ==  TIMER0_OC0_PWM_NON_INVERTING)
		OCR0 = ((dutyCycle * 256) / 100) - 1;
	#elif(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_INVERTING)
		OCR0 = 255 - (((dutyCycle * 256)/100)-1);
	#endif

#elif(TIMER_0_MODE ==  TIMER0_PHASECORRECT_MODE )

	#if(TIMER_0_OC0_MODE ==  TIMER0_OC0_PWM_NON_INVERTING)
		OCR0 = (dutyCycle* 255)/100;
	#elif(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_INVERTING)
		OCR0 = 255 - ((dutyCycle* 255)/100);
	#endif

#endif
}

ISR(TIMER0_OVF_VECT)
{
	/* To avoid ISR execution before setting callback */
	if(Timer0_CallBack[TIMER0_OVERFLOW_INT_ID] != NULL)
	{
		static uint32 counter = 0;
		counter++;
		if(counter == Timer0_NumOfOverflows)
		{
			Timer0_CallBack[TIMER0_OVERFLOW_INT_ID]();
			counter=0;
			TCNT0 = 256 - Timer0_RemTicks;
		}
	}
}

/* If setTime depends on the CTC mode uncomment it */
#if 0
ISR(TIMER0_COMP_VECT)
{
	/* To avoid ISR execution before setting callback */
 	if(Timer0_CallBack[TIMER0_COMP_MATCH_INT_ID] != NULL)
	{
		static uint32 counter = 0;
		counter++;
		if(counter == Timer0_NumOfCm)
		{
			Timer0_CallBack[TIMER0_COMP_MATCH_INT_ID]();
			counter=0;
			TCNT0 = 256 - Timer0_RemTicks;
		}
	}
}
#endif
