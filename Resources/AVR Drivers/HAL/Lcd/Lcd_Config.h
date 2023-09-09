
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#include "DIO_Interface.h"
#include "Lcd_Private.h"

#define LCD_MODE MODE_4_BIT

#define LCD_DISPLAY_PORT DIO_PORTA

#if LCD_MODE == MODE_4_BIT
	#define LCD_DISPLAY_SHIFT 4
#endif

#define LCD_RS_PORT DIO_PORTB
#define LCD_RS_PIN  PIN1

#define LCD_RW_PORT DIO_PORTB
#define LCD_RW_PIN  PIN2

#define LCD_EN_PORT DIO_PORTB
#define LCD_EN_PIN  PIN3

#endif /* HAL_LCD_LCD_CONFIG_H_ */
