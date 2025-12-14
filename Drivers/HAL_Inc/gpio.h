#ifndef _GPIO_H
#define _GPIO_H

#include "stm32f401xc.h"
#include <stddef.h>
#include "af_table.h"
#include "hal_global.h"
extern volatile uint32_t lock_value;
struct GPIO_AF_FUNCTION;
typedef enum 
{
    GPIO_MODER_INPUT = 0b00,
    GPIO_MODER_OUTPUT = 0b01,
    GPIO_MODER_ALTERNATE = 0b10,
    GPIO_MODER_ANALOG = 0b11
}GPIO_MODER_VALUES;

#define OUTPUT_PUSH_PULL 0b0
#define OUTPUT_OPEN_DRAIN 0b1
typedef uint8_t GPIO_OUTPUT;

typedef enum
{
    GPIO_SPEED_LOW = 0b00,
    GPIO_SPEED_MEDIUM = 0b01,
    GPIO_SPEED_HIGH = 0b10,
    GPIO_SPEED_VERY_HIGH = 0b11
}GPIO_SPEED_VALUES;

typedef enum
{
    GPIO_NO_PULL = 0b00,
    GPIO_PULL_UP = 0b01,
    GPIO_PULL_DOWN = 0b10,
    GPIO_PULL_RESERVED = 0b11
}GPIO_PULL_VALUES;

typedef struct {
    GPIO_MODER_VALUES moder;
    GPIO_OUTPUT output;
    GPIO_SPEED_VALUES speed;
    GPIO_PULL_VALUES pull;
    GPIO_AF_FUNCTION *af;
    size_t af_size;
}GPIO_CONFIG;

typedef enum{
    GPIO_ERROR = 0,
    GPIO_OK = 1,
    GPIO_PIN_ERROR = -1
}GPIO_STATUS;

static inline GPIO_STATUS GpioSetModer(GPIO_TypeDef *gpiox, uint8_t pin, GPIO_MODER_VALUES moder) {
    if(pin>15)return GPIO_PIN_ERROR;
    gpiox->MODER &= ~(3U<<(pin*2));
    gpiox->MODER |= (moder<<(pin*2));
    return GPIO_OK;
}

static inline GPIO_STATUS GpioSetOutput(GPIO_TypeDef *gpiox, uint8_t pin, GPIO_OUTPUT output){
    if(pin>15)return GPIO_PIN_ERROR;
    gpiox->OTYPER &= ~(1U<<pin);
    gpiox->OTYPER |= (output<<pin);
    return GPIO_OK;
}

static inline GPIO_STATUS GpioSetPull(GPIO_TypeDef *gpiox, uint8_t pin, GPIO_PULL_VALUES pull){
    if(pin>15)return GPIO_PIN_ERROR;
    gpiox->PUPDR &= ~(3U<<(pin*2));
    gpiox->PUPDR |= (pull<<(pin*2));
    return GPIO_OK;
}

static inline GPIO_STATUS GpioSetSpeed(GPIO_TypeDef *gpiox, uint8_t pin, GPIO_SPEED_VALUES speed){
    if(pin>15)return GPIO_PIN_ERROR;
    gpiox->OSPEEDR &= ~(3U<<(pin*2));
    gpiox->OSPEEDR |= (speed<<(pin*2));
    return GPIO_OK;
}

static inline uint8_t GET_PIN(GPIO_TypeDef *gpiox, uint8_t pin) {
    return (pin > 15) ? 2 : ((gpiox->IDR >> pin) & 0x1);
}

static inline void SET_PIN(GPIO_TypeDef *gpiox, uint8_t pin) {
    if(pin>15)return;
    gpiox->BSRR = (1U << pin);
}

static inline void RESET_PIN(GPIO_TypeDef *gpiox, uint8_t pin) {
    if(pin>15)return;
    gpiox->BSRR = (1U << (pin + 16U));
}

static inline uint8_t LOCK_PIN(GPIO_TypeDef *gpiox, uint16_t pins){
    gpiox->LCKR = (1<<16) | pins;
    gpiox->LCKR = (pins);
    gpiox->LCKR = (1<<16) | pins;
    lock_value = gpiox->LCKR;
    if((lock_value & (1<<16))){
        return 1;
    }
    return 0;
}

static inline void GpioSetAF(const GPIO_AF_FUNCTION *af_function){
    uint8_t pin = af_function->pin;
    uint8_t af  = af_function->af;

    if(pin <= 7){
        af_function->port->AFR[0] &= ~(0xF << (pin * 4));        
        af_function->port->AFR[0] |=  (af  << (pin * 4));        
    } else {
        uint8_t shift = (pin - 8) * 4;
        af_function->port->AFR[1] &= ~(0xF << shift);
        af_function->port->AFR[1] |=  (af  << shift);
    }
}


GPIO_STATUS GPIO_INIT(GPIO_TypeDef *gpiox, uint16_t pin, GPIO_CONFIG *config);

#endif

