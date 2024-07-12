/* Define to prevent recursive inclusion */
#ifndef __INC_ITM_H_
#define __INC_ITM_H_

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
 * @addtogroup itm
 * @{
 */

/**
 * @defgroup itm_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup itm_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup itm_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup itm_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup itm_exported_functions
 * @{
 */
/**
 * @brief   ITM_Printf
 * @note
 * @param   str, length
 * @retval  None
 */
void ITM_Printf(char *str, int length);

/**
 * @brief   SendChar
 * @note
 * @param   port, ch
 * @retval
 */
void ITM_SendChar_Port(uint8_t port, uint8_t ch);

/**
 * @brief   ITM_Printf_Port
 * @note
 * @param   port, str, length
 * @retval  None
 */
void ITM_Printf_Port(uint8_t port, char *str, int length);

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

#endif /*__INC_ITM_H_ */
