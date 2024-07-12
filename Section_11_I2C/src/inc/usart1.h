/* Define to prevent recursive inclusion */
#ifndef __INC_USART1_H_
#define __INC_USART1_H_

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
 * @addtogroup usart1
 * @{
 */

/**
 * @defgroup usart1_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup usart1_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup usart1_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup usart1_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup usart1_exported_functions
 * @{
 */

/**
 * @brief   Configure GPIO with AF7, USART1 connected to APB2 with 90MHz clock
 * @note    PA9 -> USART1_TX, PA10 -> USART1_RX
 * @param   None
 * @retval  None
 */
void USART1_GPIO_Config(void);

/**
 * @brief   Configure DMA for USART TX
 * @note    USART1_TX -> DMA2_Stream7 (Channel 4)
 * @param   None
 * @retval  None
 */
void USART1_TX_DMA_Config(void);

/**
 * @brief   Configure DMA for USART RX
 * @note    USART1_RX -> DMA2_Stream5 (Channel 4)
 * @param   None
 * @retval  None
 */
void USART1_RX_DMA_Config(void);

/**
 * @brief   Configure USART1 for ST virtual COM port (VCP)
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Init(void);

/**
 * @brief   Enable USART1 transmitter and receiver
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Enable(void);

/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */
void USART1_IRQ_Callback(void);

/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */
void USART1_TX_DMA_IRQ_Callback(void);

/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */
void USART1_RX_DMA_IRQ_Callback(void);

/**
 * @brief   USART1 transmit and receive data
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Process(void);

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

#endif /*__INC_USART1_H_ */
