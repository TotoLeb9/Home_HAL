#include "af_table.h"

uint8_t GetValueFromGPIO(GPIO_TypeDef *gpiox){
    if(gpiox==GPIOA)return 0;
    else if (gpiox==GPIOB)return 1;
    else if (gpiox==GPIOC)return 2;
    else if (gpiox==GPIOD)return 3;
    else if (gpiox==GPIOE)return 4;
    return 8;
}

int PinAvailable[5][16];

void FillMatrix(){
    for(int i =0; i<5; i++){
        for(int j = 0; j<16; j++){
            PinAvailable[i][j] = 1;
        }
    }
}

const GPIO_AF_FUNCTION SYS_AF[] = {
    {}
};

const GPIO_AF_FUNCTION TIM3_CH1[] = {
    {GPIOA, 6, AF2},
    {GPIOB, 4, AF2},
    {GPIOC, 6, AF2}
};

const GPIO_AF_FUNCTION TIM3_CH2[] = {
    {GPIOA, 7, AF2},
    {GPIOB, 5, AF2},
    {GPIOC, 7, AF2}
};

const GPIO_AF_FUNCTION TIM5_CH1[] = {
    {GPIOA, 0, AF2}    
};

const GPIO_AF_FUNCTION TIM5_CH2[] = {
    {GPIOA, 1, AF2}
};

const GPIO_AF_FUNCTION TIM5_CH3[] = {
    {GPIOA, 2, AF2}
};

const GPIO_AF_FUNCTION TIM5_CH4[] = {
    {GPIOA, 3, AF2}
};

const GPIO_AF_FUNCTION TIM4_CH1[] = {
    {GPIOB, 6, AF2},
    {GPIOD, 12, AF2}
};

const GPIO_AF_FUNCTION TIM4_CH2[] = {
    {GPIOB, 7, AF2},
    {GPIOD, 13, AF2}
};

const GPIO_AF_FUNCTION TIM4_CH3[] = {
    {GPIOB, 8, AF2},
    {GPIOD, 14, AF2}
};

const GPIO_AF_FUNCTION TIM4_CH4[] = {
    {GPIOB, 9, AF2},
    {GPIOD, 15, AF2}
};

const GPIO_AF_FUNCTION TIM2_CH1_ETR[] = {
    {GPIOA, 0, AF1},
    {GPIOA, 5, AF1},
    {GPIOA, 15, AF1}
};

const GPIO_AF_FUNCTION TIM2_CH2[] = {
    {GPIOA, 1, AF1},
    {GPIOB, 3, AF1}
};

const GPIO_AF_FUNCTION TIM2_CH3[] = {
    {GPIOA, 2, AF1},
    {GPIOB, 10, AF1}
};

const GPIO_AF_FUNCTION TIM2_CH4[] = {
    {GPIOA, 3, AF1},
    {GPIOB, 11, AF1}
};

const GPIO_AF_FUNCTION TIM1_BKIN[] = {
    {GPIOA, 6, AF1},
    {GPIOB, 12, AF1},
    {GPIOE, 15, AF1}
};

const GPIO_AF_FUNCTION TIM1_CH1N[] = {
    {GPIOA, 7, AF1},
    {GPIOB, 13, AF1},
    {GPIOE, 8, AF1}
};

const GPIO_AF_FUNCTION TIM1_CH1[] = {
    {GPIOA, 8, AF1},
    {GPIOE, 9, AF1}
};

const GPIO_AF_FUNCTION TIM1_CH2[] = {
    {GPIOA, 9, AF1},
    {GPIOE, 11, AF1}
};

const GPIO_AF_FUNCTION TIM1_CH3[] = {
    {GPIOA, 10, AF1},
    {GPIOE, 13, AF1}
};

const GPIO_AF_FUNCTION TIM1_CH4[] = {
    {GPIOA, 11, AF1},
    {GPIOE, 14, AF1}
};

const GPIO_AF_FUNCTION TIM1_ETR[] = {
    {GPIOA, 12, AF1},
    {GPIOE, 7, AF1}
};

const GPIO_AF_FUNCTION TIM1_CH2N[] = {
    {GPIOB, 0, AF1},
    {GPIOE, 10, AF1}
};

const GPIO_AF_FUNCTION TIM3_CH3[] = {
    {GPIOB, 0, AF2},
    {GPIOC, 8, AF2}
};

const GPIO_AF_FUNCTION TIM3_CH4[] = {
    {GPIOB, 1, AF2},
    {GPIOC, 9, AF2}
};

const GPIO_AF_FUNCTION TIM3_ETR[] = {
    {GPIOD, 2, AF2}
};

const GPIO_AF_FUNCTION TIM4_ETR[] = {
    {GPIOE, 0, AF2}
};

const GPIO_AF_FUNCTION TIM9_CH1[] = {
    {GPIOA, 2, AF3},
    {GPIOE, 5, AF3}
};

const GPIO_AF_FUNCTION TIM9_CH2[] = {
    {GPIOA, 3, AF3},
    {GPIOE, 6, AF3}
};

const GPIO_AF_FUNCTION TIM10_CH1[] = {
    {GPIOB, 8, AF3}
};

const GPIO_AF_FUNCTION TIM11_CH1[] = {
    {GPIOB, 9, AF3}
};

const GPIO_AF_FUNCTION I2C3_SCL[] = {
    {GPIOA, 8, AF4}
};

const GPIO_AF_FUNCTION I2C3_SMBA[] = {
    {GPIOA, 9, AF4}
};

const GPIO_AF_FUNCTION I2C1_SMBA[] = {
    {GPIOB, 5, AF4}
};

const GPIO_AF_FUNCTION I2C1_SCL[] = {
    {GPIOB, 6, AF4},
    {GPIOB, 8, AF4}
};

const GPIO_AF_FUNCTION I2C1_SDA[] = {
    {GPIOB, 7, AF4},
    {GPIOB, 9, AF4}
};

uint8_t TIM3_CH1_SIZE = sizeof(TIM3_CH1)/sizeof(TIM3_CH1[0]);
uint8_t TIM3_CH2_SIZE = sizeof(TIM3_CH2)/sizeof(TIM3_CH2[0]);
uint8_t TIM5_CH1_SIZE = sizeof(TIM5_CH1)/sizeof(TIM3_CH1[0]);
uint8_t TIM5_CH2_SIZE = sizeof(TIM5_CH2)/sizeof(TIM5_CH2[0]);
uint8_t TIM5_CH3_SIZE = sizeof(TIM5_CH3)/sizeof(TIM5_CH3[0]);
uint8_t TIM5_CH4_SIZE = sizeof(TIM5_CH4)/sizeof(TIM5_CH4[0]);
uint8_t TIM2_CH1_ETR_SIZE = sizeof(TIM2_CH1_ETR)/sizeof(TIM2_CH1_ETR[0]);
uint8_t TIM2_CH2_SIZE = sizeof(TIM2_CH2)/sizeof(TIM2_CH2[0]);
uint8_t TIM2_CH3_SIZE = sizeof(TIM2_CH3)/sizeof(TIM2_CH3[0]);
uint8_t TIM2_CH4_SIZE = sizeof(TIM2_CH4)/sizeof(TIM2_CH4[0]);

int IsAFValidForPin(GPIO_TypeDef *gpiox, uint8_t pin, const GPIO_AF_FUNCTION table[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (table[i].port == gpiox && table[i].pin == pin) {
            return 1;
        }
    }
    return 0;
}


