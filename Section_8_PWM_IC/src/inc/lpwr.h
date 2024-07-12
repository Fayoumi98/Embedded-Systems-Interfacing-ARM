/* Define to prevent recursive inclusion */
#ifndef __INC_LPWR_H_
#define __INC_LPWR_H_

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
 * @addtogroup lpwr
 * @{
 */

/**
 * @defgroup lpwr_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup lpwr_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup lpwr_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup lpwr_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup lpwr_exported_functions
 * @{
 */

void LPWR_Main(void);
void LPWR_PB_IRQ_Callback(void);

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

#endif /*__INC_LPWR_H_ */
