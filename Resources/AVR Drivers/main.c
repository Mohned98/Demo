#include <util/delay.h>
#include "Led_Interface.h"
#include "Timer1_Interface.h"
#include "Timer0_Interface.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"

static uint16 ICU_Reading[3] = {0};
static uint8  StateCounter = 0;

static void ICU_Handler(void);

int main(void)
{
	uint32 ONTicks = 0;
	uint32 periodTicks = 0;
	uint8 dutyCycle;

	Led_Init(LED0);

	Timer1_Init();
	Timer1_Start();
	Timer1_ICU_SetTrigger(TIMER1_ICU_RISING_TRIGG);
	Timer1_ICU_SetCallBack(ICU_Handler);
	Timer1_ICU_EnableInt();
	Dio_SetPinDirection(DIO_PORTD, PIN6, INPUT);


	Timer0_Init();
	Timer0_SetPWM(70);
	Dio_SetPinDirection(DIO_PORTB, PIN3, OUTPUT);
	Timer0_Start();

	GIE_Enable();

	while (StateCounter != 3); /* busy waiting */
	 periodTicks = ICU_Reading[1] - ICU_Reading[0] ;
	 ONTicks     = ICU_Reading[2] - ICU_Reading[1] ;
	 dutyCycle   =(uint8)((ONTicks * 100)/periodTicks);

	 if(dutyCycle >= 69 && dutyCycle <= 71)
	 {
		 Led_On(LED0);
	 }
	while(1)
	{

	}

	return 0;
}

static void ICU_Handler(void)
{
	if (StateCounter == 0)
	{
		ICU_Reading[0] = Timer1_ICU_InputRead();
	}
	else if (StateCounter == 1)
	{
		Timer1_ICU_SetTrigger(TIMER1_ICU_FALLING_TRIGG);
		ICU_Reading[1] = Timer1_ICU_InputRead();
	}
	else if (StateCounter == 2)
	{
		ICU_Reading[2] = Timer1_ICU_InputRead();
		Timer1_ICU_DisableInt();
		Timer1_Stop();
	}
	StateCounter++;
}
