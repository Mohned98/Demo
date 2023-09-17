
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
#define SREG      (*((volatile uint8* const)0x5F))

/* SREG BITS */
#define I_BIT     7

#define MCUCR 	  (*((volatile uint8* const)0x55))
#define MCUCSR    (*((volatile uint8* const)0x54))
#define GICR  	  (*((volatile uint8* const)0x5B))

/* MCUCR BITS */
#define ISC00_BIT 0
#define ISC01_BIT 1
#define ISC10_BIT 2
#define ISC11_BIT 3

/* MCUCSR BITS */
#define ISC2_BIT  6

/* GICR BITS */
#define INT0_BIT  6
#define INT1_BIT  7
#define INT2_BIT  5

#endif /* MCAL_ATMEGA32_REGISTERMAP_H_ */
