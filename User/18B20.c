#include "18B20.h"
#include "systick.h"

void convertDs18b20(void) 
{ 
    resetOnewire(); 
    wOnewire(0xcc); 
    wOnewire(0x44); 
}


u8* readID(void) 
{ 
	u8 ID[8],i,*p;
	resetOnewire(); 
	wOnewire(0x33);
	for(i=0;i<8;i++)
	{ID[i]=rOnewire();}
	p=ID;
	return p;
}


float readTemp(void) 
{ 
	uint8_t Presence  = 0;
	u8 temp1,temp2;
	u16 temp;
   DS18B20_Start();
	Presence = DS18B20_Start ();
	delay_us(1);
	wOnewire(0xCC); 
	wOnewire(0x44);
	delay_us(800);
	Presence = DS18B20_Start ();
	delay_us(1);
	wOnewire(0xCC); 
	wOnewire(0xBE); 	
	temp1=rOnewire(); 
	temp2=rOnewire(); 
	temp=((temp2<<8)|temp1);
	temp=(float)temp/16*100;
	return temp;
}

