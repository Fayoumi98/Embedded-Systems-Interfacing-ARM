/*
 * usart.c
 *      Author: Fayoumi
 */

#include "include/usart.h"



// Buffer for received data
#define BUFFER_SIZE 100
volatile char rx_buffer[BUFFER_SIZE];
volatile uint8_t rx_index = 0;
volatile uint8_t rx_complete = 0;



void USART1_GPIO_Enable(void)
{
	GPIO_TYPE TX;
	TX.port = PORTA;
	TX.pin = 9;
	TX.mode = ALT_FUNC_MODE;
	TX.speed = MEDIUM_SPEED;

	GPIO_TYPE RX;
	RX.port = PORTA;
	RX.pin = 10;
	RX.mode = ALT_FUNC_MODE;


	// initialize clock for port A
	gpio_init(TX);

	// select alternate function mode
	pin_config(TX.port , TX.pin , TX.mode , 99);
	pin_config(RX.port , RX.pin , RX.mode , 99);

	// set PA9 push-pull
	TX.port->OTYPER &= ~(GPIO_OTYPER_OT_9);

	// Set output speed of PA9 to medium
	pin_speed_config(PORTA,9,MEDIUM_SPEED);

	// Select pull up
	TX.port->PUPDR &= ~GPIO_PUPDR_PUPDR9;
	RX.port->PUPDR &= ~GPIO_PUPDR_PUPDR10;
	TX.port->PUPDR |= ~GPIO_PUPDR_PUPDR9_0;
	RX.port->PUPDR |= ~GPIO_PUPDR_PUPDR10_0;


	// Select Alternate function 7
	TX.port->AFR[1] &= ~(0xF0);
	RX.port->AFR[1] &= ~(0xF00);
	TX.port->AFR[1] |= 0x70;
	RX.port->AFR[1] |= 0x700;

}





void USART1_Init(void)
{
	// Enable clock for USART1
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

	// Select over-sampling by 16 mode
	USART1->CR1 &= ~(USART_CR1_OVER8);

	// Select one sample bit method
	USART1->CR3 |= USART_CR3_ONEBIT;

	// Select 1 start bit , 9 data bits , n stop bits (8 data + 1 parity)
	USART1->CR1 |= USART_CR1_M;

	// Select 1 stop bit
	USART1->CR2 &= ~USART_CR2_STOP;

	// Enable Parity control
	USART1->CR1 |= USART_CR1_PCE;

	// Select Odd Parity
	USART1->CR1 |= USART_CR1_PS;

	/* Set Baud Rate 115200
	 * 				   Fclk
	 * USARTDIV = ----------------
	 * 				16 * BaudRate
	 *
	 * 			= 90,000,000 / (16*115200)
	 *			= 48.82
	 *
	 * DIV_Fraction = 16 * 0.82 = 13.12 = 13 = 0xD
	 * DIV_Mantissa = 48 = 0x30
	 * */
	// baud-rate 9600
	USART1->BRR = 0x0683;

}




void USART1_Enable(void)
{
	// Enable USART1
	USART1->CR1 |= USART_CR1_UE;

	// Enable Transmitter
	USART1->CR1 |= USART_CR1_TE;

	// Enable Receiver
	USART1->CR1 |= USART_CR1_RE;

	// Enable parity error interrupt
	USART1->CR1 |= USART_CR1_PEIE;

    // Enable the USART1 interrupt in the NVIC
    NVIC_EnableIRQ(USART1_IRQn);

 	// Enable reception buffer not empty flag interrupt
    USART1->CR1 |= USART_CR1_RXNEIE;
}




void USART1_SendData(uint8_t data)
{
	// Wait until TXE (Transmit Data Register Empty) is set
    while (!(USART1->SR & USART_SR_TXE));

    // Transmit data
    USART1->DR = (uint32_t) data;
}


void USART1_WriteString(uint8_t *str)
{
    while (*str)
    {
    	USART1_SendData(*str++);
    }
}


uint8_t USART1_ReceiveData(void)
{
	// Wait until RXNE (Read Data Register Not Empty) is set
	while (!(USART1->SR & USART_SR_RXNE));

	// Read data
	return (uint8_t)(USART1->DR);
}


uint8_t USART1_ReceiveString(uint8_t *buffer, uint8_t buffer_size)
{
    if (rx_complete)
    {
        uint8_t length = rx_index < buffer_size ? rx_index : buffer_size - 1;
        for (uint8_t i = 0; i < length; i++)
        {
            buffer[i] = rx_buffer[i];
        }
        buffer[length] = '\0';
        rx_index = 0;
        rx_complete = 0;
        return 1;
    }
    return 0;
}



void USART1_IRQHandler(void)
{

	if (USART1->SR & USART_SR_RXNE)
	{
		char data = (char)(USART1->DR);
		if (data == '\r' || data == '\n')
		{
			rx_complete = 1;
		}
		else
		{
			if (rx_index < BUFFER_SIZE - 1)
			{
				rx_buffer[rx_index++] = data;
			}
		}
	}

    if (USART1->SR & USART_SR_PE)
    {
        // Handle parity error
        USART1->SR &= ~USART_SR_PE; // Clear parity error flag
    }

    if (USART1->SR & USART_SR_FE)
    {
        // Handle framing error
        USART1->SR &= ~USART_SR_FE; // Clear framing error flag
    }

    if (USART1->SR & USART_SR_NE)
    {
        // Handle noise error
        USART1->SR &= ~USART_SR_NE; // Clear noise error flag
    }

    if (USART1->SR & USART_SR_ORE)
    {
        // Handle overrun error
        USART1->SR &= ~USART_SR_ORE; // Clear overrun error flag
    }
}
