/* Define to prevent recursive inclusion */
#ifndef __INC_EXTI_H_
#define __INC_EXTI_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup exti
 * @{
 */

/**
 * @defgroup exti_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_constants
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
void EXTI_Init_PB();

/**
* @brief   Callback function
* @note    Called when PB is pressed
* @param   None
* @retval  None
*/
void EXTI0_PB_IRQ_Callback();

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_EXTI_H_ */
