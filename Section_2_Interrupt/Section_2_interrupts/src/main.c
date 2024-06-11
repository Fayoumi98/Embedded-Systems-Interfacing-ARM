#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "include/SysTick.h"
#include "include/gpio.h"



int main(void)
{
	SysTick_Init();


	GPIO_TYPE tp;
	tp.port = PORTA;
	tp.pin = 6;
	tp.mode = OUTPUT_PUSH_PULL;
	tp.speed = VERY_HIGH_SPEED;
	gpio_init(tp);

	GPIO_TYPE on;
	on.port = PORTC;
	on.pin = 1;
	on.mode = INPUT_MODE;
	on.pull = PULL_UP;
	gpio_init(on);


	GPIO_TYPE op;
	op.port = PORTA;
	op.pin = 5;
	op.mode = OUTPUT_PUSH_PULL;
	op.speed = VERY_HIGH_SPEED;
	gpio_init(op);

	config_gpio_interrupt(on.port,on.pin,RISING_EDGE);
	enable_gpio_interrupt(on.pin,EXTI1_IRQn);

	while (1)
	{
		gpio_toggle(tp.port,tp.pin);
	}
}


void EXTI1_IRQHandler(void)
{
	if (EXTI->PR & EXTI_PR_PR1)
	{
        PORTA->ODR ^= (1 << 5);
		clear_interrupt(1);
	}
}
