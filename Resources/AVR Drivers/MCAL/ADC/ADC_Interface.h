/*
 * ADC_Interface.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_Config.h"
#include "STD_Types.h"

void ADC_Enable (void);
void ADC_Disable (void);
void ADC_Init (void);
uint16 ADC_Read (void);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
