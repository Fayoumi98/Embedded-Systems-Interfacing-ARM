/*
 * headers.h
 *
 *  Created on: Jun 14, 2024
 *      Author: Dell
 */

#ifndef INCLUDE_HEADERS_H_
#define INCLUDE_HEADERS_H_

#include "stm32f4xx.h"

// Helping macros
#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

#endif /* INCLUDE_HEADERS_H_ */
