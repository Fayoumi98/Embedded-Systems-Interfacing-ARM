/*
 * gpio.h
 *      Author: Fayoumi
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

#include "stm32f4xx.h"

// Helping macros
#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

// Port macros
#define PORTA	GPIOA
#define PORTB	GPIOB
#define PORTC	GPIOC
#define PORTD	GPIOD
#define PORTE	GPIOE

// Mode macros
#define INPUT_MODE 			((uint32_t) 0x00)
#define OUTPUT_PUSH_PULL 	((uint32_t) 0x01)
#define OUTPUT_OPEN_DRAIN 	((uint32_t) 0x02)
#define ALT_FUNC_MODE		((uint32_t) 0x03)
#define ANALOG_MODE 		((uint32_t) 0x04)


// Speed macros
#define LOW_SPEED 			((uint32_t) 0x00)
#define MEDIUM_SPEED 		((uint32_t) 0x01)
#define HIGH_SPEED			((uint32_t) 0x02)
#define VERY_HIGH_SPEED 	((uint32_t) 0x03)

// Clock Enable macros
#define PORTA_CLOCK_EN	RCC->AHB1ENR |= (1<<0)
#define PORTB_CLOCK_EN	RCC->AHB1ENR |= (1<<1)
#define PORTC_CLOCK_EN	RCC->AHB1ENR |= (1<<2)
#define PORTD_CLOCK_EN	RCC->AHB1ENR |= (1<<3)
#define PORTE_CLOCK_EN	RCC->AHB1ENR |= (1<<4)


typedef struct
{

	GPIO_TypeDef *port;

	uint32_t	pin;

	uint32_t	mode;

	uint32_t 	pull;

	uint32_t 	speed;

	uint32_t 	alt_func;

} GPIO_TYPE;


/*****************************************************************************
* Function Name: gpio_init
* Purpose      : initialize gpio
* Parameters   : GPIO_TYPE gpio
* Return value : void
*****************************************************************************/
void gpio_init(GPIO_TYPE gpio);






/*****************************************************************************
* Function Name: pin_config
* Purpose      : configures pin mode
* Parameters   : GPIO_TypeDef *port
* 				 uint32_t pin
* 				 uint32_t pinMode
* Return value : void
*****************************************************************************/
static void pin_config(GPIO_TypeDef *port,uint32_t pinNumber, uint32_t pinMode);





/*****************************************************************************
* Function Name: pin_speed_config
* Purpose      : configures pin I/O speed
* Parameters   : GPIO_TypeDef *port
* 				 uint32_t pin
* 				 uint32_t pinMode
* 				 uint32_t speed
* Return value : void
*****************************************************************************/
static void pin_speed_config(GPIO_TypeDef *port,uint32_t pinNumber, uint32_t speed);





/*****************************************************************************
* Function Name: gpio_write
* Purpose      : write on pin 0/1 LOW/HIGH
* Parameters   : GPIO_TypeDef *port
* 				 uint32_t pin
* 				 uint8_t state
* Return value : void
*****************************************************************************/
void gpio_write(GPIO_TypeDef *port, uint32_t pinNumber, uint8_t state);



/*****************************************************************************
* Function Name: gpio_toggle
* Purpose      : pin toggle mode
* Parameters   : GPIO_TypeDef *port
* 				 uint32_t pin
* Return value : void
*****************************************************************************/
void gpio_toggle(GPIO_TypeDef *port, uint32_t pinNumber);





#endif /* INCLUDE_GPIO_H_ */
