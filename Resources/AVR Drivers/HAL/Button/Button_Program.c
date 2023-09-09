#include "Button_Interface.h"
#include <util/delay.h>

void Button_Init(uint8 btn)
{
	switch (btn)
	{
		case BTN0:
			Dio_SetPinDirection(BTN0_PORT, BTN0_PIN, INPUT);
			break;
		case BTN1:
			Dio_SetPinDirection(BTN1_PORT, BTN1_PIN, INPUT);
			break;
		case BTN2:
			Dio_SetPinDirection(BTN2_PORT, BTN2_PIN, INPUT);
			break;
	}
}

Dio_PinStateType Button_GetState(uint8 btn)
{
	uint8 btnState = RELEASED;
	switch (btn)
	{
		case BTN0:
			if (Dio_ReadPin(BTN0_PORT, BTN0_PIN) == PRESSED)
			{
				_delay_ms(30);
				if (Dio_ReadPin(BTN0_PORT, BTN0_PIN) == PRESSED)
				{
					btnState = PRESSED;
				}
			}
			break;
		case BTN1:
			if (Dio_ReadPin(BTN1_PORT, BTN1_PIN) == PRESSED)
			{
				_delay_ms(30);
				if (Dio_ReadPin(BTN1_PORT, BTN1_PIN) == PRESSED)
				{
					btnState = PRESSED;
				}
			}
			break;
		case BTN2:
			if (Dio_ReadPin(BTN2_PORT, BTN1_PIN) == PRESSED)
			{
				_delay_ms(30);
				if (Dio_ReadPin(BTN2_PORT, BTN1_PIN) == PRESSED)
				{
					btnState = PRESSED;
				}
			}
			break;
	}
	return btnState;
}
