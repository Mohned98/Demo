
#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#include "Std_Types.h"

#define TIMER1_ICU_FALLING_TRIGG 0
#define TIMER1_ICU_RISING_TRIGG  1

void Timer1_Init(void);
void Timer1_Start(void);
void Timer1_Stop(void);

void Timer1_ICU_SetTrigger(uint8 trigger);
uint16 Timer1_ICU_InputRead(void);
void Timer1_ICU_EnableInt(void);
void Timer1_ICU_DisableInt(void);
void Timer1_ICU_SetCallBack(void (* interruptAction)(void));

void Timer1_SetPWM(uint8 dutyCycle);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
