/*
 * Timer0_Interface.h
 *
 *  Created on: Sep 28, 2023
 *      Author: amrel
 */

#ifndef NASR_60_EMBEDDED_RESOURCES_AVR_DRIVERS_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define NASR_60_EMBEDDED_RESOURCES_AVR_DRIVERS_MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "Timer0_Config.h"
#include "Std_Types.h"

void Timer0_Start (void);
void Timer0_Set_time (uint32 time_ms);
void Timer0_Stop (void);
void Timer0_Intterupt_Enable(void);
void Timer0_Intterupt_Disable(void);
void Timer0_Set_callback (void (*action)(void));



#endif /* NASR_60_EMBEDDED_RESOURCES_AVR_DRIVERS_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
