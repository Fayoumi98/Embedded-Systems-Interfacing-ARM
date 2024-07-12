/* Define to prevent recursive inclusion */
#ifndef __INC_L3GD20_H_
#define __INC_L3GD20_H_

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
 * @addtogroup L3GD20
 * @{
 */

/**
 * @defgroup L3GD20_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup L3GD20_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup L3GD20_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup L3GD20_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup L3GD20_exported_functions
 * @{
 */

/**
 * @brief   L3GD20 Init function
 * @note
 * @param   None
 * @retval  None
 */
void L3GD20_Init(void);

/**
 * @brief   L3GD20 main function
 * @note
 * @param   None
 * @retval  None
 */
void L3GD20_Main(void);

/**
 * @brief   Callback function
 * @note    Called when MEMS_INT1
 * @param   None
 * @retval  None
 */
void EXTI1_MEMS_INT1_Callback();

/**
 * @brief   Callback function
 * @note    Called when MEMS_INT2
 * @param   None
 * @retval  None
 */
void EXTI2_MEMS_INT2_Callback();

/**
 * @brief   IRQ callback function
 * @note    SPI5_TX -> DMA2_Stream4 (Channel 2)
 * @param   None
 * @retval  None
 */
void SPI5_TX_DMA_IRQ_Callback(void);

/**
 * @brief   IRQ callback function
 * @note    SPI5_RX -> DMA2_Stream3 (Channel 2)
 * @param   None
 * @retval  None
 */
void SPI5_RX_DMA_IRQ_Callback(void);

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

#endif /*__INC_L3GD20_H_ */
