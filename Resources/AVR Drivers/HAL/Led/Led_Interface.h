
#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "Led_Config.h"


typedef enum
{
	LED0,
	LED1,
	LED2
}LedType;

void Led_Init(LedType led);
void Led_On(LedType led);
void Led_Off(LedType led);
void Led_Toggle(LedType led);


#endif /* HAL_LED_LED_INTERFACE_H_ */
