/*
 * usart.h
 *      Author: Fayoumi
 */

#ifndef INCLUDE_USART_H_
#define INCLUDE_USART_H_


#include "stm32f4xx.h"
#include "headers.h"
#include "gpio.h"



/*****************************************************************************
* Function Name: USART1_GPIO_Enable
* Purpose      : Enable USART1 pins PA9 Transmitter PA10 Receiver connected to
* 				 APB2 with 90MHZ max clock frequency
* Parameters   : void
* Return value : void
*****************************************************************************/
void USART1_GPIO_Enable(void);


/*****************************************************************************
* Function Name: USART1_Init
* Purpose      : Sets Parity + Baud Rate + over-sampling + number of bits
* Parameters   : void
* Return value : void
*****************************************************************************/
void USART1_Init(void);


/*****************************************************************************
* Function Name: USART1_Enable
* Purpose      : Enable USART1 transmitter / receiver and interrupts
* Parameters   : void
* Return value : void
*****************************************************************************/
void USART1_Enable(void);


/*****************************************************************************
* Function Name: USART1_send
* Purpose      : Transmits data
* Parameters   : uint8_t *data
* Return value : void
*****************************************************************************/
void USART1_SendData(uint8_t data);


/*****************************************************************************
* Function Name: USART1_recieve
* Purpose      : Receives data
* Parameters   : void
* Return value : uint8_t
*****************************************************************************/
uint8_t USART1_ReceiveData(void);


/*****************************************************************************
* Function Name: USART1_WriteString
* Purpose      : Write string data
* Parameters   : uint8_t *str
* Return value : void
*****************************************************************************/
void USART1_WriteString(uint8_t *str);



/*****************************************************************************
* Function Name: USART1_ReceiveString
* Purpose      : Receives String data
* Parameters   : char *buffer
* 				 uint8_t buffer_size
* Return value : uint8_t
*****************************************************************************/
uint8_t USART1_ReceiveString(uint8_t *buffer, uint8_t buffer_size);


#endif /* INCLUDE_USART_H_ */
