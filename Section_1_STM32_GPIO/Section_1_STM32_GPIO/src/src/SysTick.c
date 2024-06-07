#include "include/SysTick.h"

volatile uint32_t SysTickCounter = 0;



/*****************************************************************************
* Function Name: SysTick_IncrementTicks_cb
* Purpose      : Increment SysTick counter callback
* Parameters   : void
* Return value : void
*****************************************************************************/
void SysTick_IncrementTicks_cb(void)
{
  ++SysTickCounter;
}



/*****************************************************************************
* Function Name: SysTick_GetCurrentTick
* Purpose      : SysTick will be update with IRQ callback
* Parameters   : void
* Return value : uint32_t SysTickCounter
*****************************************************************************/
uint32_t SysTick_GetCurrentTick(void)
{
  return(SysTickCounter);
}


/*****************************************************************************
* Function Name: SysTick_Delay
* Purpose      : SysTick will be update with IRQ callback
* Parameters   : uint32_t wait_time_ms
* Return value : void
*****************************************************************************/
void SysTick_Delay(uint32_t wait_time_ms)
{
  /* Store start tick */
  uint32_t startTick = SysTickCounter;

  /* Loop until timeout */
  while((SysTickCounter - startTick) < wait_time_ms)
  {

  }
}



/*****************************************************************************
* Function Name: SysTick_Init
* Purpose      : SysTick initial configuration
* Parameters   : void
* Return value : void
*****************************************************************************/
void SysTick_Init(void)
{
  /* Update clock configuration */
  SystemCoreClockUpdate();

  /* Configure SysTick to generate an interrupt every millisecond */
  SysTick_Config(SystemCoreClock / 1000);
}
