/* Define to prevent recursive inclusion */
#ifndef __INC_DMA_H_
#define __INC_DMA_H_

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
 * @addtogroup dma
 * @{
 */

/**
 * @defgroup dma_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup dma_exported_functions
 * @{
 */

/**
 * @brief   DMA2 Stream0 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA2_Stream0_Init();

/**
 * @brief   DMA2 Stream0 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream0_Set_Addresses(const uint32_t * src,
    uint32_t * dst, const uint32_t size);

/**
 * @brief   DMA2 Stream0 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream0_Enable();

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

#endif /*__INC_DMA_H_ */
