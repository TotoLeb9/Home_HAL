#ifndef _AF_TABLE_H
#define _AF_TABLE_H
#include "stm32f401xc.h"
#include <stddef.h>
typedef enum
{
    AF0 = 0b0000,
    AF1 = 0b0001,
    AF2 = 0b0010,
    AF3 = 0b0011,
    AF4 = 0b0100,
    AF5 = 0b0101,
    AF6 = 0b0110,
    AF7 = 0b0111,
    AF8 = 0b1000,
    AF9 = 0b1001,
    AF10 = 0b1010,
    AF11 = 0b1011,
    AF12 = 0b1100,
    AF13 = 0b1101,
    AF14 = 0b1110,
    AF15 = 0b1111
}ALTERNATE_VALUES_ENUM;

typedef struct{
    GPIO_TypeDef *port;
    uint8_t pin;
    ALTERNATE_VALUES_ENUM af;
}GPIO_AF_FUNCTION;

extern int PinAvailable[5][16];

extern const GPIO_AF_FUNCTION SYS_AF[];
extern const GPIO_AF_FUNCTION TIM3_CH1[];
extern uint8_t TIM3_CH1_SIZE;
extern const GPIO_AF_FUNCTION TIM3_CH2[];
extern uint8_t TIM3_CH2_SIZE;
extern const GPIO_AF_FUNCTION TIM5_CH1[];
extern uint8_t TIM5_CH1_SIZE;
extern const GPIO_AF_FUNCTION TIM5_CH2[];
extern uint8_t TIM5_CH2_SIZE;
extern const GPIO_AF_FUNCTION TIM5_CH3[];
extern uint8_t TIM5_CH3_SIZE;
extern const GPIO_AF_FUNCTION TIM5_CH4[];
extern uint8_t TIM5_CH4_SIZE;
extern const GPIO_AF_FUNCTION TIM2_CH1_ETR[];
extern uint8_t TIM2_CH1_ETR_SIZE;
extern const GPIO_AF_FUNCTION TIM2_CH2[];
extern uint8_t TIM2_CH2_SIZE;
extern const GPIO_AF_FUNCTION TIM2_CH3[];
extern uint8_t TIM2_CH3_SIZE;
extern const GPIO_AF_FUNCTION TIM2_CH4[];
extern uint8_t TIM2_CH4_SIZE;
extern const GPIO_AF_FUNCTION TIM1_BKIN[];
extern const GPIO_AF_FUNCTION TIM1_CH1N[];
extern const GPIO_AF_FUNCTION TIM1_CH1[];
extern const GPIO_AF_FUNCTION TIM1_CH2[];
extern const GPIO_AF_FUNCTION TIM1_CH3[];
extern const GPIO_AF_FUNCTION TIM1_CH4[];
extern const GPIO_AF_FUNCTION TIM1_ETR[];
extern const GPIO_AF_FUNCTION TIM1_CH2N[];
extern const GPIO_AF_FUNCTION TIM3_CH3[];
extern const GPIO_AF_FUNCTION TIM3_CH4[];
extern const GPIO_AF_FUNCTION TIM3_ETR[];
extern const GPIO_AF_FUNCTION TIM4_CH1[];
extern const GPIO_AF_FUNCTION TIM4_CH2[];
extern const GPIO_AF_FUNCTION TIM4_CH3[];
extern const GPIO_AF_FUNCTION TIM4_CH4[];
extern const GPIO_AF_FUNCTION TIM4_ETR[];
extern const GPIO_AF_FUNCTION TIM9_CH1[];
extern const GPIO_AF_FUNCTION TIM9_CH2[];
extern const GPIO_AF_FUNCTION TIM10_CH1[];
extern const GPIO_AF_FUNCTION TIM11_CH1[];
extern const GPIO_AF_FUNCTION I2C3_SCL[];
extern const GPIO_AF_FUNCTION I2C3_SMBA[];
extern const GPIO_AF_FUNCTION I2C1_SMBA[];
extern const GPIO_AF_FUNCTION I2C1_SCL[];
extern const GPIO_AF_FUNCTION I2C1_SDA[];
extern const GPIO_AF_FUNCTION TIM11_CH1[];

GPIO_AF_FUNCTION GetAF(const GPIO_AF_FUNCTION table[], size_t size);
int IsAFValidForPin(GPIO_TypeDef *gpiox, uint8_t pin, const GPIO_AF_FUNCTION table[], size_t size);

#endif 