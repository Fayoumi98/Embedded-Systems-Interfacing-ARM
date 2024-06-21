/*
 * DMA.h
 *      Author: Fayoumi
 */

#ifndef INCLUDE_DMA_H_
#define INCLUDE_DMA_H_

#include "stm32f4xx.h"
#include "headers.h"


/*
 	DMA1: Peripheral => Memory
 		  Memory => Peripheral

 	DMA2: Memory <=> Memory
 */




/*****************************************************************************
* Function Name: DMA_Stream_Init
* Purpose      : initialize DMA2
* Parameters   : void
* Return value : void
*****************************************************************************/
void DMA2_Stream_Init(void);


/*****************************************************************************
* Function Name: DMA_Stream_Init
* Purpose      : initialize DMA2
* Parameters   : void
* Return value : void
*****************************************************************************/
void DMA2_Stream_SetAdresses(const uint32_t * src, uint32_t * dst,uint32_t size);


/*****************************************************************************
* Function Name: DMA_Stream_Init
* Purpose      : initialize DMA2
* Parameters   : void
* Return value : void
*****************************************************************************/
void DMA2_Stream_Enable(void);





#endif /* INCLUDE_DMA_H_ */
