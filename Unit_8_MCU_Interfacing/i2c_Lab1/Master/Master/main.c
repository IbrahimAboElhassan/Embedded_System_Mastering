/*
 * Master.c
 *
 * Created: 2/22/2024 11:47:55 AM
 * Author : Ibrahim AboElhassan
 * about  : Master transmit & Slave receive.
 */ 

#include <avr/io.h>
#include "i2c.h"


int main(void)
{
    unsigned char ch = 0;
	i2c_Init(0x48);
	
    while (1) 
    {
		_delay_ms(50);
		i2c_Start();
		i2c_Write(0b11010000+0);
		while ((TWSR) != 0x18);
		i2c_Write(ch++);
		while ((TWSR) != 0x28);
		i2c_Stop();
    }
}

