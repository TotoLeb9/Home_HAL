#ifndef _HAL_GLOBAL_H
#define _HAL_GLOBAL_H
#include "delay.h"
#include "stm32f401xc.h"
#include "af_table.h"
#include "gpio.h"
#include <string.h>
#include "clock.h"
typedef int8_t Error_t;

typedef enum{
    HAL_OK = 0,
    HAL_ERROR = -1,
    HAL_PLL_PARAM = -2,
    HAL_PLL_HIGH = -3,
    HAL_PLL_USB = -4

}HAL_DEBUG;

#endif