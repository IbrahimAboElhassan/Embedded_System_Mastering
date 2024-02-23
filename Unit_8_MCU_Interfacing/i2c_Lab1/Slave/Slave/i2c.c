/*
 * i2c.c
 *
 * Created: 2/22/2024 1:07:46 PM
 *  Author: ibrahim
 */ 

#include "i2c.h"

void i2c_Set_Address (unsigned char address)
{
	TWAR = address;	
}
unsigned char i2c_Read (unsigned char ack)
{
	unsigned char x = 0;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & 1<<7) == 0);
	while ((TWSR) != 0x60) x = TWSR;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & 1<<7) == 0);
	while ((TWSR) != 0x80) x = TWSR; 
	return TWDR;
	
}