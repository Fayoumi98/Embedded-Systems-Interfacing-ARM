

/* Define to prevent recursive inclusion */
#ifndef __INC_ADC_H_
#define __INC_ADC_H_

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
 * @addtogroup adc
 * @{
 */

/**
 * @defgroup adc_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup adc_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup adc_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup adc_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup adc_exported_functions
 * @{
 */

void ADC1_Config(void);
void ADC1_Main(void);
void ADC_IRQ_Callback(void);

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

#endif /*__INC_ADC_H_ */
