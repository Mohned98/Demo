/*
 * ADC_Private.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADC_PRESCALER_2       0b000
#define ADC_PRESCALER_4       0b010
#define ADC_PRESCALER_8       0b011
#define ADC_PRESCALER_16      0b100
#define ADC_PRESCALER_32      0b101
#define ADC_PRESCALER_64      0b110
#define ADC_PRESCALER_128     0b111
#define ADC_PRESCALER_MASK    0b11111000
#define ADC_PRESCALER_SHIFT   0

#define ADC_CHANNEL0                  0b00000
#define ADC_CHANNEL1                  0b00001
#define ADC_CHANNEL2                  0b00010
#define ADC_CHANNEL3                  0b00011
#define ADC_CHANNEL4                  0b00100
#define ADC_CHANNEL5                  0b00101
#define ADC_CHANNEL6                  0b00110
#define ADC_CHANNEL7                  0b00111
#define ADC_CHANNEL_MASK      		  0b11100000
#define ADC_CHANNEL_SHIFT     		  0

#define ADC_REF_OFF           0b00
#define ADC_REF_AVCC          0b01
#define ADC_REF_2v56          0b11
#define ADC_REF_MASK          0b00111111
#define ADC_REF_SHIFT         6
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
