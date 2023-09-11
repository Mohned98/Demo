#include "Keypad_Config.h"
#include "Keypad_Interface.h"
#include "DIO_Interface.h"
#include "util/delay.h"

void Keypad_Init(void)
{
	Dio_SetPinDirection(KEYPAD_PORT, KEYPAD_R0_PIN, OUTPUT);
	Dio_SetPinDirection(KEYPAD_PORT, KEYPAD_R1_PIN, OUTPUT);
	Dio_SetPinDirection(KEYPAD_PORT, KEYPAD_R2_PIN, OUTPUT);
	Dio_SetPinDirection(KEYPAD_PORT, KEYPAD_R3_PIN, OUTPUT);

	Dio_WritePin(KEYPAD_PORT, KEYPAD_R0_PIN, HIGH);
	Dio_WritePin(KEYPAD_PORT, KEYPAD_R1_PIN, HIGH);
	Dio_WritePin(KEYPAD_PORT, KEYPAD_R2_PIN, HIGH);
	Dio_WritePin(KEYPAD_PORT, KEYPAD_R3_PIN, HIGH);

	Dio_SetPinDirection(KEYPAD_PORT, KEYPAD_C0_PIN, INPUT);
	Dio_SetPinDirection(KEYPAD_PORT, KEYPAD_C1_PIN, INPUT);
	Dio_SetPinDirection(KEYPAD_PORT, KEYPAD_C2_PIN, INPUT);
	Dio_SetPinDirection(KEYPAD_PORT, KEYPAD_C3_PIN, INPUT);
}

uint8 Keypad_Read(void)
{
	uint8 reading = 0;
	uint8 row = 0;
	uint8 col = 0;
	uint8 keypad[4][4] = { { '1', '2', '3', 'A' },
			               { '4', '5', '6', 'B' },
			               { '7', '8', '9', 'C' },
						   { '*', '0', '#', 'D' }
	                     };

	for (row = KEYPAD_R0_PIN; row <= KEYPAD_R3_PIN; row++)
	{
		Dio_WritePin(KEYPAD_PORT, row, LOW);

		for (col = KEYPAD_C0_PIN; col <= KEYPAD_C3_PIN; col++)
		{
			if (Dio_ReadPin(KEYPAD_PORT, col) == LOW)
			{
				_delay_ms(100);
				if (Dio_ReadPin(KEYPAD_PORT, col) == LOW)
				{
					reading = keypad[row - KEYPAD_R0_PIN][col - KEYPAD_C0_PIN];
					while (Dio_ReadPin(KEYPAD_PORT, col) == LOW);
				}
			}
		}
		Dio_WritePin(KEYPAD_PORT, row, HIGH);
	}
	return reading;
}
