
#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#include "Lcd_Config.h"

#define MODE_4_BIT 							       0
#define MODE_8_BIT 							       1

#define LCD_8_BIT_MODE_COMMAND 					0x38

#if LCD_MODE == MODE_4_BIT
	#define LCD_4_BIT_MODE_COMMAND_1            0x33
	#define LCD_4_BIT_MODE_COMMAND_2            0x32
	#define LCD_4_BIT_MODE_COMMAND_3            0x28
#endif

#define LCD_DISPLAY_ON_COMMAND 					0x0C
#define LCD_CLEAR_COMMAND						0x01

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
