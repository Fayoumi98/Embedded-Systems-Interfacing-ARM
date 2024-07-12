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

  /* Configure Timer 1 */
  TIM1_Measure_PWM_Config();

  /* Infinite loop */
  while(1)
  {
    /* Calculates the duty cycle and frequency */
    TIM1_Measure_PWM_Main();
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
