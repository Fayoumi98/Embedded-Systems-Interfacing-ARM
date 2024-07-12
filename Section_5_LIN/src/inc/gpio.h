/* Define to prevent recursive inclusion */
#ifndef __INC_GPIO_H_
#define __INC_GPIO_H_

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
 * @addtogroup gpio
 * @{
 */

/**
 * @defgroup gpio_exported_typedefs
 * @{
 */

/**
 * @brief   On-board LEDs
 */
typedef enum
{
  EVAL_GREEN_LED,
  EVAL_GREEN_LED_BITBAND,
  EVAL_RED_LED,
  EVAL_ALL_LEDs
} Led_Type;


/**
 * @}
 */

/**
 * @defgroup gpio_exported_defines
 * @{
 */

/**
 * @brief   Define base address of peripheral bit-band
 */
#define BITBAND_PERI_BASE 0x40000000

/**
 * @brief   Define base address of peripheral alias band
 */
#define ALIAS_PERI_BASE 0x42000000

/**
 * @brief   Define address of GPIOG
 */
#define GPIOG_ODR 0x40021814

/**
 * @brief   Convert PERI address to alias region
 */
#define BITBAND_PERI(reg_address, bit_number) ((ALIAS_PERI_BASE + \
                (reg_address - BITBAND_PERI_BASE) * 32 + (bit_number * 4)))

/**
 * @brief   Green LED connected to GPIOG bit 13
 */
#define GREEN_LED_BITBAND *((volatile uint32_t *)(BITBAND_PERI(GPIOG_ODR, 13)))

/**
 * @}
 */

/**
 * @defgroup gpio_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_exported_functions
 * @{
 */

/**
 * @brief   On-board LEDs initialization function
 * @note    EVAL_GREEN_LED -> PG13
 * @param   Led_Type led
 * @retval  None
 */
void GPIO_Init_LED(Led_Type led);

/**
 * @brief   Push button initialization function
 * @note    On-board push button connected to PA0
 * @param   None
 * @retval  None
 */
void GPIO_Init_PB();

/**
 * @brief   Turns on-board LED on
 * @note    EVAL_GREEN_LED -> PG13
 * @param   Led_Type led
 * @retval  None
 */
void GPIO_TurnON_LED(Led_Type led);

/**
 * @brief   Turns on-board LED off
 * @note    EVAL_GREEN_LED -> PG13
 * @param   Led_Type led
 * @retval  None
 */
void GPIO_TurnOFF_LED(Led_Type led);

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

#endif /*__INC_GPIO_H_ */
