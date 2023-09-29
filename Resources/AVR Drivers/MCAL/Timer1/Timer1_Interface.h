
#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#include "Std_Types.h"

void Timer1_Init(void);
void Timer1_Start(void);
void Timer1_Stop(void);
void Timer1_SetPWM(uint8 dutyCycle);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
