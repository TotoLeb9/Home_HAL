#ifndef _CLOCK_H_
#define _CLOCK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "stm32f401xc.h"
#include "hal_global.h"   // si tu utilises des codes d'erreur HAL_xxx

/* Timeout loop iterations (tunable) */
#ifndef CLK_WAIT_TIMEOUT
#define CLK_WAIT_TIMEOUT  1000000U
#endif

typedef enum {
    HSI_SRC = 0,
    HSE_SRC = 1
} CLOCK_SOURCE;

typedef enum {
    PLL_P2 = 0,
    PLL_P4 = 1,
    PLL_P6 = 2,
    PLL_P8 = 3
} PLL_P_S;

typedef struct {
    CLOCK_SOURCE source;   
    uint8_t PLL_Q;          
    PLL_P_S PLL_P;      
    uint16_t PLL_N;        
    uint8_t PLL_M;         
} Init_Pll;

enum {
    CLK_OK = 0,
    CLK_ERR_TIMEOUT = -1,
    CLK_ERR_PARAM = -2
};



static inline int PreInitHSE(void)
{
    uint32_t t = CLK_WAIT_TIMEOUT;
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY)) {
        if (--t == 0) return CLK_ERR_TIMEOUT;
    }
    return CLK_OK;
}

static inline int PreInitHSI(void)
{
    uint32_t t = CLK_WAIT_TIMEOUT;
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY)) {
        if (--t == 0) return CLK_ERR_TIMEOUT;
    }
    return CLK_OK;
}

static inline int PreInitPLL(void)
{
    uint32_t t = CLK_WAIT_TIMEOUT;
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY)) {
        if (--t == 0) return CLK_ERR_TIMEOUT;
    }
    return CLK_OK;
}

static inline int PreInitI2SPLL(void)
{
    uint32_t t = CLK_WAIT_TIMEOUT;
    RCC->CR |= RCC_CR_PLLI2SON;
    while (!(RCC->CR & RCC_CR_PLLI2SRDY)) {
        if (--t == 0) return CLK_ERR_TIMEOUT;
    }
    return CLK_OK;
}

static inline void EnableClockSecurity(void)
{
    RCC->CR |= RCC_CR_CSSON;
}

int RCC_PLL_CONFIG(Init_Pll *pll);

#ifdef __cplusplus
}
#endif

#endif /* _CLOCK_H_ */
