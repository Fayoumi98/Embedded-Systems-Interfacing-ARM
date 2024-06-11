/*
 * gpio.c
 *      Author: Fayoumi
 */

#include "include/gpio.h"
#include "include/SysTick.h"




static void pin_config(GPIO_TypeDef *port,uint32_t pin, uint32_t pinMode, uint32_t pull)
{
	switch(pinMode)
	{
		case INPUT_MODE:
			CLRBIT(port->MODER,(pin*2));
			CLRBIT(port->MODER,((pin*2)+1));
			if(pull == PULL_UP)
			{
				SETBIT(port->PUPDR,(pin*2));
				CLRBIT(port->PUPDR,((pin*2)+1));
			}
			else if(pull == PULL_DOWN)
			{
				CLRBIT(port->PUPDR,(pin*2));
				SETBIT(port->PUPDR,((pin*2)+1));
			}
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
	else if(state == 0)
	{
		CLRBIT(port->BSRRL,pin);
		SETBIT(port->BSRRH,pin);
	}
}


uint32_t gpio_read(GPIO_TypeDef *port, uint32_t pinNumber)
{
	return READBIT(port->IDR,pinNumber);
}


void gpio_toggle(GPIO_TypeDef *port, uint32_t pin)
{
	SETBIT(port->BSRRL,pin);
	SysTick_Delay(100);
	SETBIT(port->BSRRH,pin);
	SysTick_Delay(100);
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

	pin_config(gpio.port,gpio.pin,gpio.mode,gpio.pull);
	pin_speed_config(gpio.port,gpio.pin,gpio.speed);
}



void config_gpio_interrupt(GPIO_TypeDef *port, uint32_t pinNumber, edge_select edge)
{
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	if(port == PORTA)
	{
		PORTA_CLOCK_EN;

		switch(pinNumber)
		{
			case 0:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI0_PA;
				break;
			case 1:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI1_PA;
				break;
			case 2:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI2_PA;
				break;
			case 3:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI3_PA;
				break;
			case 4:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI0_PA;
				break;
			case 5:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI1_PA;
				break;
			case 6:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI2_PA;
				break;
			case 7:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI3_PA;
				break;
			case 8:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI0_PA;
				break;
			case 9:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI1_PA;
				break;
			case 10:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI2_PA;
				break;
			case 11:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI3_PA;
				break;
			case 12:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI0_PA;
				break;
			case 13:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI1_PA;
				break;
			case 14:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI2_PA;
				break;
			case 15:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI3_PA;
				break;
		}
	}
	else if(port == PORTB)
	{
		switch(pinNumber)
		{
		PORTB_CLOCK_EN;

			case 0:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI0_PB;
				break;
			case 1:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI1_PB;
				break;
			case 2:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI2_PB;
				break;
			case 3:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI3_PB;
				break;
			case 4:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI0_PB;
				break;
			case 5:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI1_PB;
				break;
			case 6:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI2_PB;
				break;
			case 7:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI3_PB;
				break;
			case 8:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI0_PB;
				break;
			case 9:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI1_PB;
				break;
			case 10:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI2_PB;
				break;
			case 11:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI3_PB;
				break;
			case 12:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI0_PB;
				break;
			case 13:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI1_PB;
				break;
			case 14:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI2_PB;
				break;
			case 15:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI3_PB;
				break;
		}
	}
	else if(port == PORTC)
	{
		PORTC_CLOCK_EN;

		switch(pinNumber)
		{
			case 0:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI0_PC;
				break;
			case 1:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI1_PC;
				break;
			case 2:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI2_PC;
				break;
			case 3:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI3_PC;
				break;
			case 4:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI0_PC;
				break;
			case 5:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI1_PC;
				break;
			case 6:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI2_PC;
				break;
			case 7:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI3_PC;
				break;
			case 8:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI0_PC;
				break;
			case 9:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI1_PC;
				break;
			case 10:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI2_PC;
				break;
			case 11:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI3_PC;
				break;
			case 12:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI0_PC;
				break;
			case 13:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI1_PC;
				break;
			case 14:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI2_PC;
				break;
			case 15:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI3_PC;
				break;
		}
	}
	else if(port == PORTD)
	{
		PORTD_CLOCK_EN;

		switch(pinNumber)
		{
			case 0:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI0_PD;
				break;
			case 1:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI1_PD;
				break;
			case 2:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI2_PD;
				break;
			case 3:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI3_PD;
				break;
			case 4:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI0_PD;
				break;
			case 5:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI1_PD;
				break;
			case 6:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI2_PD;
				break;
			case 7:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI3_PD;
				break;
			case 8:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI0_PD;
				break;
			case 9:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI1_PD;
				break;
			case 10:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI2_PD;
				break;
			case 11:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI3_PD;
				break;
			case 12:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI0_PD;
				break;
			case 13:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI1_PD;
				break;
			case 14:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI2_PD;
				break;
			case 15:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI3_PD;
				break;
		}
	}
	else if(port == PORTE)
	{
		PORTE_CLOCK_EN;

		switch(pinNumber)
		{
			case 0:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI0_PE;
				break;
			case 1:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI1_PE;
				break;
			case 2:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI2_PE;
				break;
			case 3:
				SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI3_PE;
				break;
			case 4:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI0_PE;
				break;
			case 5:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI1_PE;
				break;
			case 6:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI2_PE;
				break;
			case 7:
				SYSCFG->EXTICR[1] = SYSCFG_EXTICR1_EXTI3_PE;
				break;
			case 8:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI0_PE;
				break;
			case 9:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI1_PE;
				break;
			case 10:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI2_PE;
				break;
			case 11:
				SYSCFG->EXTICR[2] = SYSCFG_EXTICR1_EXTI3_PE;
				break;
			case 12:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI0_PE;
				break;
			case 13:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI1_PE;
				break;
			case 14:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI2_PE;
				break;
			case 15:
				SYSCFG->EXTICR[3] = SYSCFG_EXTICR1_EXTI3_PE;
				break;
		}
	}

	if(edge == RISING_EDGE)
	{
		SETBIT(EXTI->RTSR,pinNumber);
	}
	else if(edge == FALLING_EDGE)
	{
		SETBIT(EXTI->FTSR,pinNumber);
	}
	else if(edge == RISING_FALLING_EDGE)
	{
		SETBIT(EXTI->RTSR,pinNumber);
		SETBIT(EXTI->FTSR,pinNumber);
	}
}



void enable_gpio_interrupt(uint32_t pinNumber, IRQn_Type irq_number)
{
	// enable interrupt in EXTI
	SETBIT(EXTI->IMR,pinNumber);
	// enable interrupt in NVIC
	NVIC_EnableIRQ(irq_number);
}



void clear_interrupt(uint32_t pinNumber)
{
	// write 1 to clear bit
	SETBIT(EXTI->PR,pinNumber);
}
