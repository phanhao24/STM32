#include "OneWire.h"
#include "systick.h"

#include "string.h"
void Onewire_Enable_GPIO_Port(void)
{
  RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOC,ENABLE);
}
//onewire->PC1

void Onewire_OUT_PULL_UP(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
}

void Onewire_OUT_FLOATING(void)
{

	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void Onewire_IN_FLOATING(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
}

void Onewire_IN_PULL_UP(void)
{

	GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

}


/* Reset */
void resetOnewire(void) 
{
	Onewire_OUT_PULL_UP();
	CLR_DQ();
	delay_us(450);
	SET_DQ();
	delay_us(60);
	Onewire_IN_PULL_UP(); 
	delay_us(10);
	while(!(GET_DQ()));
	Onewire_OUT_PULL_UP();
	SET_DQ();
}
uint8_t DS18B20_Start (void){
	uint8_t Response = 0;
	Onewire_OUT_PULL_UP();
	CLR_DQ();
	delay_us(480);
	Onewire_IN_PULL_UP(); 
	delay_us(80);
	if (!GET_DQ()) Response = 1; 
	else Response = -1;
	delay_us(400);
	return Response;

	}
/* Read */
uint8_t rOnewire(void)
{
    uint8_t data=0;
		int i;
		Onewire_IN_PULL_UP();
		
    for(i=0;i<8;i++)
    {
			Onewire_OUT_PULL_UP();
			CLR_DQ();
			delay_us(2);
			Onewire_IN_PULL_UP();
			
			if(GET_DQ()){
				data|=1<<i;
			}
			delay_us(60);
	}
    return(data);
}
/* Write */
void wOnewire(uint8_t data)
{
	int i;
	Onewire_OUT_PULL_UP();
   for( i=0;i<8;i++){
		if((data & (1<<i))!=0)
		{
				Onewire_OUT_PULL_UP();
				CLR_DQ();
				delay_us(1);
				Onewire_IN_PULL_UP();
				delay_us(50);
		}
   	 	else
   	 	{
				Onewire_OUT_PULL_UP();
				CLR_DQ();
				delay_us(50);
				Onewire_IN_PULL_UP();	
    	}  	
  }
}


