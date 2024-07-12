/* Define to prevent recursive inclusion */
#ifndef __INC_IKS01A2_H_
#define __INC_IKS01A2_H_

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
 * @addtogroup IKS01A2
 * @{
 */

/**
 * @defgroup IKS01A2_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup IKS01A2_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup IKS01A2_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup IKS01A2_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup IKS01A2_exported_functions
 * @{
 */
void IKS01A2_Init(void);
void IKS01A2_Main(void);
void I2C3_TX_DMA_IRQ_Callback(void);
void I2C3_RX_DMA_IRQ_Callback(void);

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

#endif /*__INC_IKS01A2_H_ */
