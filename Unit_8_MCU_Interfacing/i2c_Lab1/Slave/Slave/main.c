/*
 * Slave.c
 *
 * Created: 2/22/2024 1:06:43 PM
 * Author : ibrahim
 */ 

#include <avr/io.h>
#include "i2c.h"


int main(void)
{
	DDRA = 0xFF;
	i2c_Set_Address(0b11010000);
	
    while (1) 
    {
		PORTA = i2c_Read(1);
    }
	return 0;
}

