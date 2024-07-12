/* Includes */
#include <stddef.h>
#include "memcpy.h"


/**
 * @brief   Copy data between two memory buffers
 * @note
 * @param   src, dst, size
 * @retval  RETURN_STATUS_OK, RETURN_STATUS_NOT_OK
 */
ReturnStatus_Type memcpy32(const uint32_t * src,
    uint32_t * dst, const uint32_t size)
{
  /* Return status */
  ReturnStatus_Type returnStatus = RETURN_STATUS_NOT_OK;

  /* Check for null pointer */
  if((NULL != src) && (NULL != dst))
  {
//    /* Pointers are OK, start copying */
//    for (uint32_t idx = 0; idx < size; idx++)
//    {
//      dst[idx] = src[idx];
//    }

    /* Get array length */
    uint32_t arrayLength = size;

    while (arrayLength > 0)
    {
      /* Copy one word then increment the pointers */
      *dst++ = *src++;

      /* Decrement array length */
      arrayLength--;
    }

    /* Return OK */
    returnStatus = RETURN_STATUS_OK;
  }
  else
  {
    /* Null pointer, Return status is not OK */
    returnStatus = RETURN_STATUS_NOT_OK;
  }

  /* Return status */
  return returnStatus;
}


/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
