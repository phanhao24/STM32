#ifndef _ONEWIRE_H
#define _ONEWIRE_H

#include "stm32f4xx.h"
#include "stdio.h"
#define SET_DQ() 		GPIO_SetBits(GPIOC,GPIO_Pin_1)
#define CLR_DQ() 		GPIO_ResetBits(GPIOC,GPIO_Pin_1)

#define GET_DQ() 		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)

void Onewire_Enable_GPIO_Port(void);
void Onewire_OUT_PULL_UP(void);
void Onewire_OUT_FLOATING(void);
void Onewire_IN_FLOATING(void);
void Onewire_IN_PULL_UP(void);
void startOnewire(void);
void _delay_us(u8 us);
void resetOnewire(void) ;
uint8_t DS18B20_Start (void);
uint8_t rOnewire(void);
void wOnewire(uint8_t data);

#endif /*_ONEWIRE_H*/
