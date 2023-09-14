/*********************************************************************************************************
*
* File                : main.c
* Hardware Environment: 
* Build Environment   : RealView MDK-ARM  Version: 4.20
* Version             : V1.0
* By                  : 
*
*                                  (c) Copyright 2005-2011, WaveShare
*                                       http://www.waveshare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "LCD28/LCD_Driver.h"
#include "LCD28/LCD_lib.h"
#include "OneWire.h"
#include "18B20.h"
#include <stdio.h>
#include "User_systick.h"
#include "systick.h"
/*******************************************************************************
* Function Name  : Delay
* Description    : Delay Time
* Input          : - nCount: Delay Time
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void  Delay (uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}


/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
int main(void)
{
	//uint8_t i=0;
	char text_1[50];
	float i1=0;
	float tmp=0;
	lcd_init();
	lcd_display_string( 60,60,(uint8_t* )"CPU:STM32F405RGT6          ", FONT_1206, RED );
  lcd_display_string( 60,80,(uint8_t* )"NHOM 4 HTN K19", FONT_1608 , BLACK );
   delay_init();
   Onewire_Enable_GPIO_Port();
 	while (1)
  	{
		if(tmp != i1)
				{
					
					tmp=i1;
					sprintf(text_1,"nhietdo:%2.2f ",i1);
					lcd_clear_Rect(WHITE,120,100,180,120);
					lcd_display_string( 60,100,(uint8_t* )text_1, FONT_1608, RED );
					
					
				}  	
				i1 = readTemp()/100;
				delay_us(100);
   	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

