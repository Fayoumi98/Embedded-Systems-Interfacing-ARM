/* Define to prevent recursive inclusion */
#ifndef __INC_DS18B20_H_
#define __INC_DS18B20_H_

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
 * @addtogroup DS18B20
 * @{
 */

/**
 * @defgroup DS18B20_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup DS18B20_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup DS18B20_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup DS18B20_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup DS18B20_exported_functions
 * @{
 */

/**
 * @brief   Configure GPIO
 * @note    UART5_TX -> PC12, UART5_RX -> PD2 (Not Used)
 *          UART5 mapped to alternate function AF8
 *          UART5 connected to APB1 with 45MHz max clock
 * @param   None
 * @retval  None
 */
void DS18B20_GPIO_Init(void);

/**
 * @brief   Configure DMA for UART TX
 * @note    UART5_TX -> DMA1_Stream7 (Channel 4)
 * @param   None
 * @retval  None
 */
void DS18B20_TX_DMA_Init(void);

/**
 * @brief   Configure DMA for UART RX
 * @note    UART5_RX -> DMA1_Stream0 (Channel 4)
 * @param   None
 * @retval  None
 */
void DS18B20_RX_DMA_Init(void);

/**
 * @brief   Configure UART5 for DS18B20
 * @note
 * @param   None
 * @retval  None
 */
void DS18B20_UART5_Init(void);

/**
 * @brief   Enable communications with DS18B20
 * @note
 * @param   None
 * @retval  None
 */
void DS18B20_UART5_Enable(void);

/**
 * @brief   DS18B20 process function
 * @note
 * @param   None
 * @retval  None
 */
void DS18B20_Process(void);

/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */
void UART5_TX_DMA_IRQ_Callback(void);

/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */
void UART5_RX_DMA_IRQ_Callback(void);

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

#endif /*__INC_DS18B20_H_ */
