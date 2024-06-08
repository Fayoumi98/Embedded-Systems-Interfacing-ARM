#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "include/SysTick.h"
#include "include/gpio.h"



int main(void)
{
	SysTick_Init();

	GPIO_TYPE p;
	p.port = PORTA;
	p.pin = 5;
	p.mode = OUTPUT_PUSH_PULL;
	p.speed = VERY_HIGH_SPEED;

	gpio_init(p);

	while (1)
	{
		gpio_toggle(p.port,p.pin);
	}
}
