/*
 * ADC_Config.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

#include "ADC_Private.h"

/*choose from ADC_PRESCALER_2 ---> ADC_PRESCALER_128*/
#define ADC_PRESCALER_FACTOR   ADC_PRESCALER_128

/* choose from 					ADC_REF_AVCC
 	 	 	 					ADC_REF_2v56
 	 	 	 					ADC_REF_SHIFT  */
#define ADC_REF    				ADC_REF_AVCC

/*choose from ADC_CHANNEL0 -> ADC_CHANNEL7 */
#define ADC_CHANNEL             ADC_CHANNEL1



#endif /* MCAL_ADC_ADC_CONFIG_H_ */
