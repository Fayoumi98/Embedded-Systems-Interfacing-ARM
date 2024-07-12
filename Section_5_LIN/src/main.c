#include "nvic.h"
#include "SysTick.h"
#include "gpio.h"
#include "LIN_Slave.h"



int main(void)
{
  SysTick_Init();
  GPIO_Init_LED(EVAL_ALL_LEDs);
  NVIC_Init();

  LIN_Slave_GPIO_Init();
  LIN_Slave_UART5_Init();
  LIN_Slave_TX_DMA_Init();
  LIN_Slave_RX_DMA_Init();

  /* Clear PRIMASK, enable IRQs */
  __enable_irq();

  LIN_Slave_Enable();

  /* Infinite loop */
  while(1)
  {
    LIN_Slave_Process();
  }
}