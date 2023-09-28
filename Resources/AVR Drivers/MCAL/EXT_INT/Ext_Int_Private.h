/*
 * EXT_INT_Private.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Dell
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_EXT_INT_PRIVATE_H_


#define FALLING_EDGE	 0b10
#define RISING_EDGE		 0b11
#define LOW_LEVEL        0b00
#define LOGICAL_CHANGE   0b01

#define EXT_INT1_SHIFT   2
#define EXT_INT2_SHIFT   6

#define EXT_INT0_MASK    0b11111100
#define EXT_INT1_MASK    0b11110011
#define EXT_INT2_MASK    0b11011111
#endif /* MCAL_EXT_INT_EXT_INT_PRIVATE_H_ */
