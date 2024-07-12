/* Define to prevent recursive inclusion */
#ifndef __INC_LIN_SLAVE_H_
#define __INC_LIN_SLAVE_H_

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
 * @addtogroup LIN_Slave
 * @{
 */

/**
 * @defgroup LIN_Slave_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup LIN_Slave_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup LIN_Slave_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup LIN_Slave_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup LIN_Slave_exported_functions
 * @{
 */

void LIN_Slave_GPIO_Init(void);
void LIN_Slave_UART5_Init(void);
void LIN_Slave_TX_DMA_Init(void);
void LIN_Slave_RX_DMA_Init(void);
void LIN_Slave_Enable(void);
void LIN_Slave_RX_DMA_IRQ_Callback(void);
void LIN_Slave_TX_DMA_IRQ_Callback(void);
void LIN_Slave_UART5_IRQ_Callback(void);
void LIN_Slave_Process(void);


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

#endif /*__INC_LIN_SLAVE_H_ */
