/*
 * DMA.c
 *      Author: Fayoumi
 */


#include "include/DMA.h"




void DMA2_Stream_Init(void)
{
	///////// Step 1 : enable clock for DMA2
	SETBIT(RCC->AHB1ENR,22);

	///////// Step 2 : Make sure that DMA stream X is disabled
	if(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream0->CR))
	{
		// DMA2 stream 0 is enabled, must be disabled first
		DMA2_Stream0->CR &= ~DMA_SxCR_EN;

		// wait until enable bit is cleared
		while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream0->CR))
		{
			// do nothing until enable bit is cleared
		}
	}
	else
	{
		// do nothing enable bit is already cleared
	}

	///////// Step 3 : Select DMA channel CHSEL[2:0] in DMA_SxCR in case (Preph <=> Mem)
	// not needed in the case of Memory <=> Memory

	///////// Step 4 : Select stream Priority level (very high)
	DMA2_Stream0->CR |= DMA_SxCR_PL;

	///////// Step 5 : Select data direction Memory <=> Memory
	DMA2_Stream0->CR |= DMA_SxCR_DIR_1;

	///////// Step 6 : Select Memory and Peripheral Sizes (1/2/4 bytes)
	DMA2_Stream0->CR |= DMA_SxCR_MSIZE_1;
	DMA2_Stream0->CR |= DMA_SxCR_PSIZE_1;

	///////// Step 7 : Select FIFO Mode, it will also be set by the hardware when the stream is enabled
	// DMDIS: Direct mode disable
	DMA2_Stream0->FCR |= DMA_SxFCR_DMDIS;

	///////// Step 8 : Select FIFO Threshold, 1/2 full FIFO
	DMA2_Stream0->FCR |= DMA_SxFCR_FTH_0;

	///////// Step 9 : Select Memory and Peripheral incremental mode
	DMA2_Stream0->CR |= DMA_SxCR_PINC;
	DMA2_Stream0->CR |= DMA_SxCR_MINC;

	///////// Step 10 : Enable Transfer complete interrupt
	DMA2_Stream0->CR |= DMA_SxCR_TCIE;
}



void DMA2_Stream_SetAdresses(const uint32_t * src, uint32_t * dst,uint32_t size)
{
	///////// Step 11 : Set DMA stream x peripheral address register to source address
	DMA2_Stream0->PAR = (uint32_t) src;

	///////// Step 12 : Set DMA stream x memory 0 address register (DMA_SxM0AR) to destination address
	DMA2_Stream0->M0AR = (uint32_t) dst;

	///////// Step 13 : Set number of data items (number of transfers)
	// DMA stream x number of data register (DMA_SxNDTR) (x = 0..7)
	DMA2_Stream0->NDTR = size;
}




void DMA2_Stream_Enable(void)
{
	///////// Step 14 : clear all interrupt flags
	// DMA low interrupt flag clear register (DMA_LIFCR)
	DMA2->LIFCR = (DMA_LIFCR_CTCIF0 | DMA_LIFCR_CHTIF0 | DMA_LIFCR_CTEIF0
				| DMA_LIFCR_CDMEIF0 | DMA_LIFCR_CFEIF0);

	// Enable DMA2 stream 0
	DMA2_Stream0->CR |=	DMA_SxCR_EN;
}
