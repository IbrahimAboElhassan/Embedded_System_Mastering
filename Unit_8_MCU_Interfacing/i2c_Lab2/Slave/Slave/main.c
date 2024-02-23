/*
 * Slave.c
 *
 * Created: 2/23/2024 2:29:55 PM
 * Author : Ibrahim AboElhassan
 */ 

#include <avr/io.h>
#include "i2c.h"


int main(void)
{
    unsigned char ch = 0;
	i2c_Set_Address(0b11010000);
    while (1) 
    {
		i2c_Read(1);
		i2c_Write(ch++);
    }
	return 0;
}

