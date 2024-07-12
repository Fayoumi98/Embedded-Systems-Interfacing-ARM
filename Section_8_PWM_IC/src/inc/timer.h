/* Define to prevent recursive inclusion */
#ifndef __INC_TIMER_H_
#define __INC_TIMER_H_

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
 * @addtogroup timer
 * @{
 */

/**
 * @defgroup timer_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_functions
 * @{
 */
/**
 * @brief   Timer6 as up counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM6_UpCount_Config(void);

/**
 * @brief   Timer3 as down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM3_DownCount_Config(void);

/**
 * @brief   Timer4 as up down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM4_UpDownCount_Config(void);

/**
 * @brief   Timer4 IRQ callback function
 * @note
 * @param
 * @retval
 */
void TIM4_IRQ_Callback(void);

/**
 * @brief   TIM8 configuration function
 * @note    Configure TIM8 external clock mode 1 and 2 using external trigger
 *          input (TIM8_ETR) mapped to PA0 using AF3
 * @param
 * @retval
 */
void TIM8_ETR_Config(void);

/**
 * @brief   Timer8 IRQ callback function
 * @note
 * @param
 * @retval
 */
void TIM8_IRQ_Callback(void);

/**
 * @brief   TIM1 configuration function
 * @note    Configure TIM1 to measure the PWM duty cycle and frequency of an
 *          input signal
 *          input (TIM1_CH1) mapped to PE9 using AF1
 * @param
 * @retval
 */
void TIM1_Measure_PWM_Config(void);

/**
 * @brief   TIM1 measure PWM main function
 * @note    calculates the duty cycle and frequency.
 * @param
 * @retval
 */
void TIM1_Measure_PWM_Main(void);

/**
 * @brief   TIM1 configuration function
 * @note    Configure TIM1 to generate PWM with configurable duty cycle
 *          and frequency. (TIM1_CH1) mapped to PE9 using AF1
 * @param
 * @retval
 */
void TIM1_Generate_PWM_Config(void);

/**
 * @brief   PWM update function
 * @note
 * @param
 * @retval
 */
void TIM1_Update_PWM(void);

/**
 * @brief   TIM8 configuration function
 * @note    Configure TIM8 to generate one pulse after five output cycles
 *          from timer 1, using timer synchronization.
 * @param
 * @retval
 */
void TIM8_Generate_OnePulse_Config(void);
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

#endif /*__INC_TIMER_H_ */
