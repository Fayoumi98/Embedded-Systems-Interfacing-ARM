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

	// create External GPIO triggered interrupt EXTI1_IRQn
	config_gpio_interrupt(on.port,on.pin,RISING_EDGE);
	enable_gpio_interrupt(on.pin,EXTI1_IRQn,1);

	// create software triggered interrupt EXTI2_IRQn EXTI3_IRQn
	NVIC_SetPriority(EXTI2_IRQn,2);
	NVIC_SetPriority(EXTI3_IRQn,3);

	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);

	while (1)
	{

		NVIC_SetPendingIRQ(EXTI2_IRQn);
		SysTick_Delay(100);
		NVIC_SetPendingIRQ(EXTI3_IRQn);
		SysTick_Delay(100);

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
