/*
 * IGIE_Private.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Dell
 */

#ifndef MCAL_GIE_GIE_PRIVATE_H_
#define MCAL_GIE_GIE_PRIVATE_H_

#define INT0_VECT     __vector_1
#define INT1_VECT     __vector_2
#define INT2_VECT     __vector_3



#define ISR(VECT) void VECT(void)__attribute__((signal));\
				  void VECT(void)



#endif /* MCAL_GIE_GIE_PRIVATE_H_ */
