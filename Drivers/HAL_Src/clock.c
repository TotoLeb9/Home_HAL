#include "clock.h"

int RCC_PLL_CONFIG(Init_Pll *pll){
    uint32_t clock_source;
    uint32_t vco_clock;
    uint32_t pll_general_clock;
    uint32_t usb_clock_output;
    
    if(pll->source==HSI_SRC){
        PreInitHSI();
        clock_source = 16000000;
    }
    else if(pll->source==HSE_SRC){
        PreInitHSE();
        clock_source = 25000000;
    } else {
        return HAL_PLL_PARAM; 
    }

   
    FLASH->ACR = (1<<FLASH_ACR_DCEN_Pos) | (1<<FLASH_ACR_ICEN_Pos) | (FLASH_ACR_LATENCY_3WS<<FLASH_ACR_LATENCY_Pos) | ((1<<FLASH_ACR_PRFTEN_Pos));
    
    RCC->CR &= ~(1<<RCC_CR_PLLON_Pos);
    while (RCC->CR & RCC_CR_PLLRDY) {}
    
    vco_clock = (clock_source / pll->PLL_M) * pll->PLL_N;
    if((vco_clock < 192000000) || (vco_clock > 432000000)) return HAL_PLL_PARAM;
    
    if((pll->PLL_Q >15) || (pll->PLL_Q == 0) || (pll->PLL_Q == 1)) return HAL_PLL_PARAM;
    
    pll_general_clock = vco_clock / pll->PLL_P;
    if(pll_general_clock>84000000){
        return HAL_PLL_HIGH;
    }

    usb_clock_output = vco_clock / pll->PLL_Q;
    if(usb_clock_output>48050000 || usb_clock_output<47900000){
        return HAL_PLL_USB;
    }
    
    RCC->PLLCFGR = 
    (pll->PLL_M << RCC_PLLCFGR_PLLM_Pos) | 
    (pll->PLL_N << RCC_PLLCFGR_PLLN_Pos) |
    ( (pll->PLL_P / 2 - 1) << RCC_PLLCFGR_PLLP_Pos) | 
    (pll->PLL_Q << RCC_PLLCFGR_PLLQ_Pos) |
    (pll->source << RCC_PLLCFGR_PLLSRC_Pos);
    
    RCC->CR |= RCC_CR_PLLON; 
    while (!(RCC->CR & RCC_CR_PLLRDY));
    
    RCC->CFGR =   
    (RCC_CFGR_PPRE2_DIV1 << RCC_CFGR_PPRE2_Pos) | 
    (RCC_CFGR_PPRE1_DIV2 << RCC_CFGR_PPRE1_Pos) |  
    (RCC_CFGR_HPRE_DIV1 << RCC_CFGR_HPRE_Pos) |    
    (RCC_CFGR_SW_PLL);                           
    
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
    
    PreInitPLL();
    return HAL_OK;
}