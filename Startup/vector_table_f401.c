#include <stdint.h>
#include <stddef.h>
#include "clock.h"
#define SRAM_START 0x20000000U
#define SRAM_SIZE (64U * 1024U)
#define SRAM_END ((SRAM_START)+(SRAM_SIZE))
#define STACK_START SRAM_END

extern uint32_t end_of_text, _s_data, _e_data, _s_bss, _e_bss, flash_data;
extern void __libc_init_array(void);
extern int main(void);

void Reset_Handler(void);
void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SVCall_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMonitor_Handler(void)  __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI6_PVD_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI21_TAMP_STAMP_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI22_RTC_WKUP_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI1_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI3_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream0_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream1_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream2_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream3_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream4_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream5_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream6_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM4_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI2_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void USART1_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); 
void USART2_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI17_RTC_Alarm_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI18_OTG_FS_WKUP_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void USART6_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI4_Handler(void) __attribute__ ((weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    STACK_START,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0,  // Reserved
    0,  // Reserved
    0,  // Reserved
    0,  // Reserved
    (uint32_t)&SVCall_Handler,
    (uint32_t)&DebugMonitor_Handler,
    0,  // Reserved
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,
    (uint32_t)&WWDG_Handler,
    (uint32_t)&EXTI6_PVD_Handler,  
    (uint32_t)&EXTI21_TAMP_STAMP_Handler,
    (uint32_t)&EXTI22_RTC_WKUP_Handler,
    (uint32_t)&FLASH_Handler,
    (uint32_t)&RCC_Handler,
    (uint32_t)&EXTI0_Handler,
    (uint32_t)&EXTI1_Handler,
    (uint32_t)&EXTI2_Handler,
    (uint32_t)&EXTI3_Handler,
    (uint32_t)&EXTI4_Handler,
    (uint32_t)&DMA1_Stream0_Handler,
    (uint32_t)&DMA1_Stream1_Handler,
    (uint32_t)&DMA1_Stream2_Handler,
    (uint32_t)&DMA1_Stream3_Handler,
    (uint32_t)&DMA1_Stream4_Handler,
    (uint32_t)&DMA1_Stream5_Handler,
    (uint32_t)&DMA1_Stream6_Handler,
    (uint32_t)&ADC_Handler,
    0, 0, 0, 0,  // Reserved
    (uint32_t)&EXTI9_5_Handler,
    (uint32_t)&TIM1_BRK_TIM9_Handler,
    (uint32_t)&TIM1_UP_TIM10_Handler,
    (uint32_t)&TIM1_TRG_COM_TIM11_Handler,
    (uint32_t)&TIM1_CC_Handler,
    (uint32_t)&TIM2_Handler,
    (uint32_t)&TIM3_Handler,
    (uint32_t)&TIM4_Handler,
    (uint32_t)&I2C1_EV_Handler,
    (uint32_t)&I2C1_ER_Handler,
    (uint32_t)&I2C2_EV_Handler,
    (uint32_t)&I2C2_ER_Handler,
    (uint32_t)&SPI1_Handler,
    (uint32_t)&SPI2_Handler,
    (uint32_t)&USART1_Handler,
    (uint32_t)&USART2_Handler,
    0,  // Reserved
    (uint32_t)&EXTI15_10_Handler,
    (uint32_t)&EXTI17_RTC_Alarm_Handler,
    (uint32_t)&EXTI18_OTG_FS_WKUP_Handler,
    0, 0, 0, 0,  // Reserved
    (uint32_t)&DMA1_Stream7_Handler,
    0,  // Reserved
    (uint32_t)&SDIO_Handler,
    (uint32_t)&TIM5_Handler,
    (uint32_t)&SPI3_Handler,
    0, 0, 0, 0,  // Reserved
    (uint32_t)&DMA2_Stream0_Handler,
    (uint32_t)&DMA2_Stream1_Handler,
    (uint32_t)&DMA2_Stream2_Handler,
    (uint32_t)&DMA2_Stream3_Handler,
    (uint32_t)&DMA2_Stream4_Handler,
    0, 0,  // Reserved
    0,  // CAN2_TX
    0,  // CAN2_RX0
    0,  // CAN2_RX1
    0,  // CAN2_SCE
    (uint32_t)&OTG_FS_Handler,
    (uint32_t)&DMA2_Stream5_Handler,
    (uint32_t)&DMA2_Stream6_Handler,
    (uint32_t)&DMA2_Stream7_Handler,
    (uint32_t)&USART6_Handler,
    (uint32_t)&I2C3_EV_Handler,
    (uint32_t)&I2C3_ER_Handler,
    0, 0, 0, 0, 0, 0,  // Reserved
    (uint32_t)&FPU_Handler,
    0, 0,  // Reserved
    (uint32_t)&SPI4_Handler,
};

void Default_Handler(void){
    while(1);
}

void _init(void) {}

void Reset_Handler(void){
    uint32_t *pSrc = (uint32_t*)&flash_data;
    uint32_t *pDst = (uint32_t*)&_s_data;
    
    while(pDst < (uint32_t*)&_e_data) {
        *pDst++ = *pSrc++;
    }


    pDst = (uint32_t*)&_s_bss;
    while(pDst < (uint32_t*)&_e_bss) {
        *pDst++ = 0;
    }
    
    //__libc_init_array();
    Init_Pll pll_config = {
        .PLL_M = 25,
        .PLL_N = 336,
        .PLL_P = 4, 
        .PLL_Q = 7,
        .source = HSE_SRC
    };
    RCC_PLL_CONFIG(&pll_config);
    main();
    
    while(1);
}