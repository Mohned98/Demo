
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

/**********************  ADC  **********************/
#define ADMUX			(*((volatile uint8* const)0x27))
#define ADCSRA			(*((volatile uint8* const)0x26))
#define ADC_VALUE		(*((volatile uint16* const)0x24))

/* ADMUX BITS */
#define REFS1_BIT			7
#define REFS0_BIT			6
#define ADLAR_BIT			5

/* ADSRA bits */
#define ADEN_BIT			7
#define ADSC_BIT			6
#define ADIF_BIT			4

/**********************  Timer0  **********************/
#define TCCR0     (*((volatile uint8* const)0x53))
#define TIMSK     (*((volatile uint8* const)0x59))
#define TCNT0     (*((volatile uint8* const)0x52))

/* TCCR0 BITS */
#define WGM00_BIT          6
#define WGM01_BIT          3
#define CS02_BIT           2
#define CS01_BIT           1
#define CS00_BIT           0

/* TIMSK BITS */
#define OCIE0_BIT          1
#define TOIE0_BIT          0


#endif /* MCAL_ATMEGA32_REGISTERMAP_H_ */
