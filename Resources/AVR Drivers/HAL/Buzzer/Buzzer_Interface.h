
#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

#include "Buzzer_Config.h"

void Buzzer_Init(void);
void Buzzer_On(void);
void Buzzer_Off(void);
Dio_PinStateType Buzzer_Toggle(void);


#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
