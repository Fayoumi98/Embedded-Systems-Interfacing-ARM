#ifndef __INC_SYSTICK_H_
#define __INC_SYSTICK_H_

#include "stm32f4xx.h"


/**
 * @brief   Increment SysTick counter callback
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_IncrementTicks_cb(void);

/**
 * @brief   Return current SysTick counter
 * @note
 * @param   None
 * @retval  SysTickCounter
 */
uint32_t SysTick_GetCurrentTick(void);

/**
 * @brief   Delay function based on SysTick
 * @note    SysTick will be update with IRQ callback
 * @param   Waiting time in milliseconds
 * @retval  None
 */
void SysTick_Delay(uint32_t wait_time_ms);

/**
 * @brief   SysTick initial configuration
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_Init(void);


#endif /*__INC_SYSTICK_H_ */
