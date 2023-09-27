/*
 * Bit_Math.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Dell
 */

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_

#define SET_BIT(REG,BIT)         REG |=(1 << BIT)
#define CLEAR_BIT(REG,BIT)       REG &= ~(1 << BIT)
#define TOGGLE_BIT(REG,BIT)      REG ^=(1<<BIT)
#define IS_BIT_SET(REG,BIT)      REG & (1 << BIT)
#define IS_BIT_CLEARED(REG,BIT)  !(REG & (1 << BIT))
#define GET_BIT(REG,BIT)         1 & (REG >> BIT)
#define MASK_SET(REG , MASK, VAL, SHIFT)  REG=(REG & MASK)|(VAL<<SHIFT)

#endif /* COMMON_BIT_MATH_H_ */
