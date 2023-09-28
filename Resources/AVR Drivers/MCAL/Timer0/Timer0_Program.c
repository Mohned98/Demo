#include "Timer0_Interface.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include "GIE_Interface.h"
#include "ATmega32_RegisterMap.h"


static uint16 timer0_numoverflow = 0;
static uint8 timer0_remticks = 0;
static void (*timer_callback_arr [2])(void) = {NULL};


void Timer0_Init (void)
{
	MASK_SET( TCCR0, TIMER0_MODE_MASK, TIMER0_MODE, TIMER0_MODE_SHIFT);
}


void Timer0_Set_time (uint32 time_ms)
{
	uint16 prescaler_arr []={1, 8, 64, 256, 1024};
	uint32 freq = SYS_FREQ / prescaler_arr[TIMER0_PRESCALER - 1];

	uint64 ticks = (freq * time_ms) / 1000;
	timer0_remticks = ticks % 256;
	timer0_numoverflow = ticks / 256;

	if (timer0_remticks != 0)
	{
		TCNT0 = 256 - timer0_remticks;
		timer0_numoverflow ++ ;
	}

}

void Timer0_Start (void)
{
	MASK_SET(TCCR0, TIMER0_PRESCALER_MASK, TIMER0_PRESCALER ,TIMER0_PRESCALER_SHIFT);
}

void Timer0_Stop (void)
{
	MASK_SET(TCCR0, TIMER0_PRESCALER_MASK, TIMER0_PRESCALER_STOP ,TIMER0_PRESCALER_SHIFT);
}

void Timer0_Intterupt_Enable(void)
{
#if TIMER0_MODE == TIMER0_MODE_NORMAL
	SET_BIT( TIMSK, TOILE0_BIT);
#endif

#if TIMER0_MODE == TIMER0_MODE_CTC
	SET_BIT( TIMSK, OCIE0_BIT);
#endif

}

void Timer0_Intterupt_Disable(void)
{
#if TIMER0_MODE == TIMER0_MODE_NORMAL
	CLEAR_BIT(TIMSK, TOILE0_BIT);
#endif

#if TIMER0_MODE == TIMER0_MODE_CTC
	CLEAR_BIT(TIMSK, OCIE0_BIT);
#endif
}


void Timer0_Set_callback (void (*action)(void))
{
#if TIMER0_MODE == TIMER0_MODE_NORMAL
	timer_callback_arr[TIMER0_MODE_NORMAL] = action ;
#endif
#if TIMER0_MODE == TIMER0_MODE_CTC
	timer_callback_arr[TIMER0_MODE_CTC] = action ;
#endif
}


#if TIMER0_MODE == TIMER0_MODE_NORMAL
ISR(TIMER0_OVF_VECT)
{
	static uint32 counter = 0;
	counter++;
	if (counter == timer0_numoverflow)
	{
		timer_callback_arr[TIMER0_MODE_NORMAL]();
		counter = 0;
		TCNT0 = 256 - timer0_remticks;
	}
}

#elif
ISR(TIMER0_COMP_VECT)
{
		static uint32 counter = 0;
		counter++;
		if (counter == timer0_numoverflow)
		{
			timer_callback_arr[TIMER0_MODE_CTC]();
			counter = 0;
			TCNT0 = 256 - timer0_remticks;
		}
}

#endif


