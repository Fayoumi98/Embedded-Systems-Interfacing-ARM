/* Includes */
#include "stm32f4xx.h"
#include "nvic.h"
#include "SysTick.h"
#include "timer.h"
#include "gpio.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup main
 * @brief
 * @{
 */

/**
 * @defgroup main_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_private_variables
 * @{
 */

/**
 * @brief   Variable for storing the up counter
 */
static uint16_t UpCounter = 0;

/**
 * @brief   Variable for storing the down counter
 */
static uint16_t DownCounter = 0;

/**
 * @brief   Variable for storing the up down counter
 */
static uint16_t UpDownCounter = 0;

/**
 * @}
 */

/**
 * @defgroup main_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_exported_functions
 * @{
 */

/**
 * @brief   Main function
 * @note
 * @param   none
 * @retval  none
 */
int main(void)
{
  SysTick_Init();
  NVIC_Init();
  GPIO_Init_LED(EVAL_ALL_LEDs);

  /* Clear PRIMASK, enable IRQs */
  __enable_irq();

  /* Configure Counters */
  TIM6_UpCount_Config();
  TIM3_DownCount_Config();
  TIM4_UpDownCount_Config();

  /* Infinite loop */
  while(1)
  {
    /* Read periodically counter registers */
    UpCounter = TIM6->CNT;
    DownCounter = TIM3->CNT;
    UpDownCounter = TIM4->CNT;
  }
}

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
