/* Define to prevent recursive inclusion */
#ifndef __INC_RCC_H_
#define __INC_RCC_H_

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
 * @addtogroup rcc
 * @{
 */

/**
 * @defgroup rcc_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_functions
 * @{
 */
void RCC_SystemReset(void);
void RCC_DetectResetSource(void);
void RCC_ProcessReset(void);
void RCC_ClockOut_Setup(void);

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

#endif /*__INC_RCC_H_ */
