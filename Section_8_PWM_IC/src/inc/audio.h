/* Define to prevent recursive inclusion */
#ifndef __INC_AUDIO_H_
#define __INC_AUDIO_H_

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
 * @addtogroup audio
 * @{
 */

/**
 * @defgroup audio_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup audio_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup audio_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup audio_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup audio_exported_functions
 * @{
 */
void AUDIO_ADC_Config(void);
void AUDIO_DAC_Config(void);
void AUDIO_Timer_Config(void);
void AUDIO_Main(void);
void AUDIO_PB_Callback(void);
void AUDIO_DMA2_Stream0_Callback(void);
void AUDIO_DMA1_Stream6_Callback(void);

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

#endif /*__INC_AUDIO_H_ */
