/*
 * Master.c
 *
 * Created: 2/23/2024 2:22:09 PM
 * Author : Ibrahim AboElhassan
 */ 

#include <avr/io.h>
#include "i2c.h"

int main(void)
{
	unsigned char ch;
	DDRA=0xFF;                                   
	i2c_Init(0x48);                           
	while (1)
	{
		_delay_ms(50);
		i2c_Start();                       
		i2c_Write(0b11010000+1);          
		ch=i2c_Read(0);                  
		i2c_Stop();
		PORTA=ch;
	}
	return 0;
}

