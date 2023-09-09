
#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_

#include "Button_Config.h"
#include "DIO_Interface.h"
#include "Button_Private.h"

#if (BUTTON_SCHEME == ACTIVE_HIGH)

#define PRESSED HIGH
#define RELEASED LOW

#else

#define PRESSED LOW
#define RELEASED HIGH

#endif

#define BTN0 0
#define BTN1 1
#define BTN2 2

void Button_Init(uint8 btn);
Dio_PinStateType Button_GetState(uint8 btn);


#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
