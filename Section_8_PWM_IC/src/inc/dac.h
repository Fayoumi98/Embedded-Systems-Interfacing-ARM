/* Define to prevent recursive inclusion */
#ifndef __INC_DAC_H_
#define __INC_DAC_H_

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
 * @addtogroup dac
 * @{
 */

/**
 * @defgroup dac_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dac_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dac_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dac_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dac_exported_functions
 * @{
 */
void DAC_Config(void);
void DAC_PB_Callback(void);

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

#endif /*__INC_DAC_H_ */
