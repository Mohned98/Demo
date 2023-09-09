#include "Buzzer_Interface.h"
#include "DIO_Interface.h"

void Buzzer_Init(void)
{
	Dio_SetPinDirection(BUZZER_PORT, BUZZER_PIN, OUTPUT);
}

void Buzzer_On(void)
{
	Dio_WritePin(BUZZER_PORT, BUZZER_PIN, HIGH);
}

void Buzzer_Off(void)
{
	Dio_WritePin(BUZZER_PORT, BUZZER_PIN, LOW);
}

Dio_PinStateType Buzzer_Toggle(void)
{
	return Dio_TogglePin(BUZZER_PORT, BUZZER_PIN);
}
