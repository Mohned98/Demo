
#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "Std_Types.h"

#define TIMER0_OVERFLOW_INT_ID     0
#define TIMER0_COMP_MATCH_INT_ID   1

void Timer0_Init(void);
void Timer0_SetTime(uint32 timeInMS);
void Timer0_Start(void);
void Timer0_Stop(void);
void Timer0_EnableInt(uint8 intId);
void Timer0_DisableInt(uint8 intId);
void Timer0_SetCallBack(uint8 intId, void (* interruptAction)(void));
void Timer0_SetPWM(uint8 dutyCycle);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
