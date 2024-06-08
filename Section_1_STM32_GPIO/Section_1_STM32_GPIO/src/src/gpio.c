/*
 * gpio.c
 *      Author: Fayoumi
 */

#include "include/gpio.h"
#include "include/SysTick.h"




static void pin_config(GPIO_TypeDef *port,uint32_t pin, uint32_t pinMode)
{
	switch(pinMode)
	{
		case INPUT_MODE:
			CLRBIT(port->MODER,(pin*2));
			CLRBIT(port->MODER,((pin*2)+1));
			break;
		case OUTPUT_PUSH_PULL:
			SETBIT(port->MODER,(pin*2));
			CLRBIT(port->MODER,((pin*2)+1));
			CLRBIT(port->OTYPER,pin);
			break;
		case OUTPUT_OPEN_DRAIN:
			SETBIT(port->MODER,(pin*2));
			CLRBIT(port->MODER,((pin*2)+1));
			SETBIT(port->OTYPER,pin);
			break;
		case ALT_FUNC_MODE:
			CLRBIT(port->MODER,(pin*2));
			SETBIT(port->MODER,((pin*2)+1));
			break;
		case ANALOG_MODE:
			SETBIT(port->MODER,(pin*2));
			SETBIT(port->MODER,((pin*2)+1));
			break;
	}
}





static void pin_speed_config(GPIO_TypeDef *port,uint32_t pin, uint32_t speed)
{
	switch(speed)
	{
		case LOW_SPEED:
			CLRBIT(port->OSPEEDR,(pin*2));
			CLRBIT(port->OSPEEDR,((pin*2)+1));
			break;
		case MEDIUM_SPEED:
			CLRBIT(port->OSPEEDR,(pin*2));
			SETBIT(port->OSPEEDR,((pin*2)+1));
			break;
		case HIGH_SPEED:
			SETBIT(port->OSPEEDR,(pin*2));
			CLRBIT(port->OSPEEDR,((pin*2)+1));
			break;
		case VERY_HIGH_SPEED:
			SETBIT(port->OSPEEDR,(pin*2));
			SETBIT(port->OSPEEDR,((pin*2)+1));
			break;
	}
}



void gpio_write(GPIO_TypeDef *port, uint32_t pin, uint8_t state)
{
	if(state == 1)
	{
		SETBIT(port->BSRRL,pin);
	}
	else
	{
		SETBIT(port->BSRRH,pin);
	}
}


void gpio_toggle(GPIO_TypeDef *port, uint32_t pin)
{
	SETBIT(port->BSRRL,pin);
	SysTick_Delay(1000);
	SETBIT(port->BSRRH,pin);
	SysTick_Delay(1000);
}


void gpio_init(GPIO_TYPE gpio)
{
	if(gpio.port == PORTA)
	{
		PORTA_CLOCK_EN;
	}
	if(gpio.port == PORTB)
	{
	PORTB_CLOCK_EN;
	}
	if(gpio.port == PORTC)
	{
	PORTC_CLOCK_EN;
	}
	if(gpio.port == PORTD)
	{
	PORTD_CLOCK_EN;
	}
	if(gpio.port == PORTE)
	{
	PORTE_CLOCK_EN;
	}

	pin_config(gpio.port,gpio.pin,gpio.mode);
	pin_speed_config(gpio.port,gpio.pin,gpio.speed);
}


