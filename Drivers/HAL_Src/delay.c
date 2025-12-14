#include "delay.h"

volatile uint32_t stick;

void SysTick_Handler(void){
    stick++;
}

void delay(uint32_t ms)
{
    uint32_t start = stick;
    while ((stick - start) < ms);
}