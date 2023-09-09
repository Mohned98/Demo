#include "Lcd_Interface.h"
#include "Lcd_Private.h"
#include "util/delay.h"
#include "Dio_Interface.h"

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


}
