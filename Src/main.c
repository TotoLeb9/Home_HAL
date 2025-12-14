#include "stm32f4xx.h"
#include "hal_global.h"
int main(void){
    SysTick_Config(84000-1);
    GPIO_CONFIG cfg = {
        .moder = GPIO_MODER_OUTPUT,
        .output = OUTPUT_PUSH_PULL,
        .speed = GPIO_SPEED_HIGH,
        .pull = GPIO_PULL_UP
    };
    
    GPIO_INIT(GPIOC,13,&cfg);
    for(;;){
       
        RESET_PIN(GPIOC, 13);
        delay(1000);
        SET_PIN(GPIOC,13);
        delay(1000);
    }
    return 0;
}