#include "Led_Interface.h"
#include "DIO_Interface.h"

void Led_Init(LedType led)
{
	switch(led)
	{
		case LED0:
			Dio_SetPinDirection(LED0_PORT, LED0_PIN, OUTPUT);
			break;
		case LED1:
			Dio_SetPinDirection(LED1_PORT, LED1_PIN, OUTPUT);
			break;
		case LED2:
			Dio_SetPinDirection(LED2_PORT, LED2_PIN, OUTPUT);
			break;
	}
}

void Led_On(LedType led)
{
	switch(led)
	{
		case LED0:
			Dio_WritePin(LED0_PORT, LED0_PIN, HIGH);
			break;
		case LED1:
			Dio_WritePin(LED1_PORT, LED1_PIN, HIGH);
			break;
		case LED2:
			Dio_WritePin(LED2_PORT, LED2_PIN, HIGH);
			break;
		default:
			break;
	}
}

void Led_Off(LedType led)
{
	switch(led)
	{
		case LED0:
			Dio_WritePin(LED0_PORT, LED0_PIN, LOW);
			break;
		case LED1:
			Dio_WritePin(LED1_PORT, LED1_PIN, LOW);
			break;
		case LED2:
			Dio_WritePin(LED2_PORT, LED2_PIN, LOW);
			break;
		default:
			break;
	}
}

Dio_PinStateType Led_Toggle(LedType led)
{
	switch(led)
	{
		case LED0:
			return Dio_TogglePin(LED0_PORT, LED0_PIN);
		case LED1:
			return Dio_TogglePin(LED1_PORT, LED1_PIN);
		case LED2:
			return Dio_TogglePin(LED2_PORT, LED2_PIN);
		default:
			return 0;
	}
}
