#include "gpio.h"
volatile uint32_t lock_value = 0;

static void EnableGPIOClock(GPIO_TypeDef *gpiox) {
    uint32_t *enr_reg = &RCC->AHB1ENR;
    uint32_t enable_bit = 0;
    
    if (gpiox == GPIOA) {
        enable_bit = RCC_AHB1ENR_GPIOAEN;
    }
    else if (gpiox == GPIOB) {
        enable_bit = RCC_AHB1ENR_GPIOBEN;
    }
    else if (gpiox == GPIOC) {
        enable_bit = RCC_AHB1ENR_GPIOCEN;
    } else {
        return; 
    }

    if (!(*enr_reg & enable_bit)) {
        *enr_reg |= enable_bit;

        volatile uint32_t tmpreg = *enr_reg; 
        (void)tmpreg;
    }
}

GPIO_STATUS GPIO_INIT(GPIO_TypeDef *gpiox, uint16_t pin, GPIO_CONFIG *config)
{
    if (pin > 15 || config == NULL)
        return GPIO_PIN_ERROR;

    EnableGPIOClock(gpiox);

    GpioSetModer(gpiox, pin, config->moder);
    GpioSetSpeed(gpiox, pin, config->speed);
    GpioSetOutput(gpiox, pin, config->output);
    GpioSetPull(gpiox, pin, config->pull);

    if (config->moder == GPIO_MODER_ALTERNATE && config->af != NULL && config->af_size > 0) {
    if (!IsAFValidForPin(gpiox, pin, config->af, config->af_size))
        return GPIO_ERROR;
    uint8_t afr_index = pin / 8;
    uint8_t afr_shift = (pin % 8) * 4;
    
    uint8_t af_value = 0xFF;
    for (size_t i = 0; i < config->af_size; i++) {
        if (config->af[i].port == gpiox && config->af[i].pin == pin) {
            af_value = config->af[i].af;
            break;
        }
    }
    if (af_value == 0xFF)
        return GPIO_ERROR;

    gpiox->AFR[afr_index] &= ~(0xF << afr_shift);
    gpiox->AFR[afr_index] |= (af_value << afr_shift);
    
}
return HAL_OK;
}


