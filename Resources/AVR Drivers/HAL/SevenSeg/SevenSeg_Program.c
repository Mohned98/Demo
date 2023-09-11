#include "DIO_Interface.h"
#include "SevenSeg_Config.h"
#include "SevenSeg_Interface.h"
#include "util/delay.h"

void SevenSeg_Init(void)
{
	Dio_SetPortDirection(SEVENSEG_DISPLAY_PORT, 0xF << SEVENSEG_DISPLAY_SHIFT);
	Dio_SetPinDirection(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, OUTPUT);
	Dio_SetPinDirection(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, OUTPUT);
}

void SevenSeg_Display(uint8 num)
{
	uint8 units = num % 10;
	uint8 tens = num / 10;
	uint16 counter;
	Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, LOW);
	Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, LOW);
	for(counter =0; counter<500; counter++)
	{
		Dio_WritePort(SEVENSEG_DISPLAY_PORT, units << SEVENSEG_DISPLAY_SHIFT);
		Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, HIGH);
		_delay_ms(1);
		Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, LOW);

		Dio_WritePort(SEVENSEG_DISPLAY_PORT, tens << SEVENSEG_DISPLAY_SHIFT);
		Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, HIGH);
		_delay_ms(1);
		Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, LOW);
	}

}
