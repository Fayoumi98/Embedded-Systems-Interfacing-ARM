#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "include/SysTick.h"
#include "include/gpio.h"
#include "include/DMA.h"

// define buffer size 500 word = 500 * 32bit
#define BUFFER_SIZE ((uint32_t) 500)

// Source and destination buffers
static uint32_t srcBuffer[BUFFER_SIZE];
static uint32_t dstBuffer[BUFFER_SIZE];

int main(void)
{
	SysTick_Init();


	GPIO_TYPE R_LED;
	R_LED.port = PORTA;
	R_LED.pin = 6;
	R_LED.mode = OUTPUT_PUSH_PULL;
	R_LED.speed = VERY_HIGH_SPEED;
	gpio_init(R_LED);

	GPIO_TYPE G_LED;
	G_LED.port = PORTA;
	G_LED.pin = 5;
	G_LED.mode = OUTPUT_PUSH_PULL;
	G_LED.speed = VERY_HIGH_SPEED;
	gpio_init(G_LED);


	// create software triggered interrupt EXTI2_IRQn EXTI3_IRQn
	NVIC_SetPriority(EXTI2_IRQn,3);
	NVIC_SetPriority(EXTI3_IRQn,4);

	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);

	// set priority & enable DMA2 Stream 0 interrupt
	NVIC_SetPriority(DMA2_Stream0_IRQn,2);
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);

	gpio_write(PORTA,6,1);

	SysTick_Delay(5000);



	DMA2_Stream_Init();
	DMA2_Stream_SetAdresses(srcBuffer , dstBuffer , BUFFER_SIZE);



	// initialize source buffer
	for(int idx = 0 ; idx < BUFFER_SIZE ; idx++)
	{
		srcBuffer[idx] = idx * idx;
	}

	gpio_write(PORTA,6,0);

	DMA2_Stream_Enable();



	while (1)
	{
	}
}
