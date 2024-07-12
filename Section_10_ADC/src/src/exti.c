/* Includes */
#include "exti.h"
#include "gpio.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup exti
 * @brief
 * @{
 */

/**
 * @defgroup exti_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_functions
 * @{
 */

/**
 * @brief   Push button EXTI initialization function
 * @note    On-board push button connected to PA0,
 *          so it can use only EXTI0
 * @param   None
 * @retval  None
 */
void EXTI_Init_PB()
{
  /* Enable SYSCFG clock */
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

  /* Map PA0 to EXT0 */
  SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;

  /* Enable rising edge trigger */
  EXTI->RTSR |= EXTI_RTSR_TR0;

  /* Disable falling edge trigger */
  EXTI->FTSR &= ~(EXTI_FTSR_TR0);

  /* Enable interrupt line */
  EXTI->IMR |= EXTI_IMR_MR0;

  /* Enable event line */
  EXTI->EMR |= EXTI_EMR_MR0;
}

/**
 * @brief   Callback function
 * @note    Called when PB is pressed
 * @param   None
 * @retval  None
 */
void EXTI0_PB_IRQ_Callback()
{
  GPIO_Toggle_LED(EVAL_RED_LED);

  /* Clear pending bit */
  EXTI->PR |= EXTI_PR_PR0;
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
