#include <util/delay.h>
#include "Led_Interface.h"
#include "Timer1_Interface.h"
#include "DIO_Interface.h"

int main(void)
{
	Dio_SetPinDirection(DIO_PORTD, PIN4, OUTPUT);


	Timer1_Init();

	Timer1_Start();
	while(1)
	{
		Timer1_SetPWM(5);
		_delay_ms(3000);
		Timer1_SetPWM(24);
		_delay_ms(3000);
	}

	return 0;

}
