#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "include/SysTick.h"




int main(void)
{
	SysTick_Init();

	RCC->AHB1ENR |= (1<<0);
	GPIOA->MODER |= (1<<10);
	GPIOA->OTYPER |= (1<<5);
	GPIOA->OSPEEDR |= (1<<11) | (1<<10);


	while (1)
	{
	  GPIOA->BSRRL |= (1<<5); // Set the Pin PA5
	  SysTick_Delay(1000);
	  GPIOA->BSRRH |= (1<<5); // Reset the Pin PA5
	  SysTick_Delay(1000);
	}
}
