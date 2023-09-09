
#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "Std_Types.h"

void Lcd_Init(void);
void Lcd_DisplayString(uint8* string);
void Lcd_Clear(void);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
