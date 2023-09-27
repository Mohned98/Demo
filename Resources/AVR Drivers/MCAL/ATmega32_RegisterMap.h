/*
 * ATmega32_RegisterMap.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Dell
 */

#ifndef MCAL_ATMEGA32_REGISTERMAP_H_
#define MCAL_ATMEGA32_REGISTERMAP_H_

#include "Std_Types.h"

/**********************    DIO     **********************/
#define PORTA     (*((volatile uint8* const)0x3B))
#define DDRA      (*((volatile uint8* const)0x3A))
#define PINA      (*((volatile uint8* const)0x39))

#define PORTB     (*((volatile uint8* const)0x38))
#define DDRB      (*((volatile uint8* const)0x37))
#define PINB      (*((volatile uint8* const)0x36))

#define PORTC     (*((volatile uint8* const)0x35))
#define DDRC      (*((volatile uint8* const)0x34))
#define PINC      (*((volatile uint8* const)0x33))

#define PORTD     (*((volatile uint8* const)0x32))
#define DDRD      (*((volatile uint8* const)0x31))
#define PIND      (*((volatile uint8* const)0x30))

/**********************  Interrupt  **********************/
#define SREG      (*((volatile uint8* const)0x5F)) //STATUS_REG

/* SREG BITS */
#define I_BIT     7

#define MCUCR 	  (*((volatile uint8* const)0x55)) //MCU_CONTROL_REG
#define MCUCSR    (*((volatile uint8* const)0x54)) //MCU_CONTROL_AND_STATUS_REG
#define GICR  	  (*((volatile uint8* const)0x5B)) //GENERAL_INT_CONTROL_REG

/* MCUCR BITS */ //to select the preffered event to cause the interrupt for int0 and int1
#define ISC00_BIT 0
#define ISC01_BIT 1
#define ISC10_BIT 2
#define ISC11_BIT 3

/* MCUCSR BITS */ //to select the preffered event to cause the interrupt for int2
#define ISC2_BIT  6

/* GICR BITS */  //the enabling of the INT channels
#define INT0_BIT  6
#define INT1_BIT  7
#define INT2_BIT  5

/**********************  ADC  **********************/
#define ADMUX   	(*((volatile uint8* const)0x27))  //ADC_SELECTION_REG
#define ADCSRA 		(*((volatile uint8* const)0x26))  //ADC_CONTROL_AND_STATUSE_REG
#define ADC_VAL    	(*((volatile uint16* const)0x24)) //REG_VALUE

/* ADMUX_BITS */
#define  REFS1_BIT   7 //Reference voltage config
#define  REFS0_BIT   6 //Reference voltage config
#define  ADLAR_BIT   5 //left or right config

/* ADCSRA_BITS */
#define ADEN_BIT     7
#define ADSC_BIT     6
#define ADIF_BIT     4


#endif /* MCAL_ATMEGA32_REGISTERMAP_H_ */
