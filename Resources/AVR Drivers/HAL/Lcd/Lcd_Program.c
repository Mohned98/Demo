#include "Lcd_Interface.h"
#include "Lcd_Private.h"
#include "util/delay.h"

static void Lcd_SendCommand(uint8 command)
{
	Dio_WritePin(LCD_RS_PORT, LCD_RS_PIN, LOW);
#if LCD_MODE == MODE_8_BIT
	Dio_WritePort(LCD_DISPLAY_PORT, command);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(5);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, LOW);
#else
	Dio_WritePort(LCD_DISPLAY_PORT, command & 0xF0);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(5);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, LOW);

	Dio_WritePort(LCD_DISPLAY_PORT, command << LCD_DISPLAY_SHIFT);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(5);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, LOW);
#endif
}

static void Lcd_SendCharacter(uint8 data)
{
	Dio_WritePin(LCD_RS_PORT, LCD_RS_PIN, HIGH);
#if LCD_MODE == MODE_8_BIT
	Dio_WritePort(LCD_DISPLAY_PORT, data);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(5);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, LOW);
#else
	Dio_WritePort(LCD_DISPLAY_PORT, data & 0xF0);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(5);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, LOW);

	Dio_WritePort(LCD_DISPLAY_PORT, data << LCD_DISPLAY_SHIFT);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(5);
	Dio_WritePin(LCD_EN_PORT, LCD_EN_PIN, LOW);
#endif

}

void Lcd_Init(void)
{
	Dio_SetPinDirection(LCD_RS_PORT, LCD_RS_PIN, OUTPUT);
	Dio_SetPinDirection(LCD_RW_PORT, LCD_RW_PIN, OUTPUT);
	Dio_SetPinDirection(LCD_EN_PORT, LCD_EN_PIN, OUTPUT);
	Dio_WritePin(LCD_RW_PORT, LCD_RW_PIN, LOW);
#if LCD_MODE == MODE_8_BIT
	Dio_SetPortDirection(LCD_DISPLAY_PORT, 0xFF);
	_delay_ms(1000);
	Lcd_SendCommand(LCD_8_BIT_MODE_COMMAND);
#else
	Dio_SetPortDirection(LCD_DISPLAY_PORT, 0xF << LCD_DISPLAY_SHIFT);
	_delay_ms(1000);
	Lcd_SendCommand(LCD_4_BIT_MODE_COMMAND_1);
	Lcd_SendCommand(LCD_4_BIT_MODE_COMMAND_2);
	Lcd_SendCommand(LCD_4_BIT_MODE_COMMAND_3);
#endif
	Lcd_SendCommand(LCD_CLEAR_COMMAND);
	Lcd_SendCommand(LCD_DISPLAY_ON_COMMAND);
}
void Lcd_DisplayString(uint8* string)
{
	uint8 counter=0;
	while(string[counter]!='\0')
	{
		Lcd_SendCharacter(string[counter]);
		counter++;
	}
}

void Lcd_Clear(void)
{
	Lcd_SendCommand(LCD_CLEAR_COMMAND);
}
