/* Includes */
#include "nvic.h"
#include "SysTick.h"
#include "gpio.h"
#include "exti.h"
#include "rcc.h"


int main(void)
{
  SysTick_Init();
  NVIC_Init();

  GPIO_Init_LED(EVAL_ALL_LEDs);
  GPIO_Init_PB();
  EXTI_Init_PB();
  RCC_ClockOut_Setup();

  /* Clear PRIMASK, enable IRQs */
  __enable_irq();

  /* Detect reset source */
  RCC_DetectResetSource();

  /* Infinite loop */
  while(1)
  {
    RCC_ProcessReset();
  }
}
