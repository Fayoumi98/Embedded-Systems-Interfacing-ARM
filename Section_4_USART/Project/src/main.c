#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "include/SysTick.h"
#include "include/gpio.h"
#include "include/DMA.h"
#include "include/usart.h"


#define BUFFER_SIZE 100

int main(void)
{
	uint8_t data[] = "This is a USART1 Driver";
	uint8_t received_data[BUFFER_SIZE];

	SysTick_Init();

	USART1_GPIO_Enable();

	USART1_Init();

	USART1_Enable();

	USART1_WriteString(data);
	USART1_WriteString("\r\n");

	while (1)
	{
		if (USART1_ReceiveString(received_data, BUFFER_SIZE))
		{
			// Do something with the received string
			// For example, echo it back
			USART1_WriteString("Received: ");
			USART1_WriteString(received_data);
			USART1_WriteStrsing("\r\n");
		}
	}
}
