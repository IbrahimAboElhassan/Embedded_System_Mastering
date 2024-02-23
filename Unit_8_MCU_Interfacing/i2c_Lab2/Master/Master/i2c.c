/*
 * i2c.c
 *
 * Created: 2/22/2024 11:53:47 AM
 *  Author: Ibrahim AboElhassan
 */ 

#include "i2c.h"
#define prescaler 1

void i2c_Init (unsigned long SCL_Clock)
{
	TWBR = (unsigned char) (((F_CPU / SCL_Clock) - 16) / (2*prescaler));
	if (prescaler == 0)
	TWSR = 0;
	else if (prescaler == 4)
	TWSR = 1;
	else if (prescaler == 16)
	TWSR = 2;
	else if (prescaler == 64)
	TWSR = 3;
	
}

void i2c_Start (void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (TWCR & (1<<7) == 0);
	while ((TWSR) != 0x08);
}

void i2c_Write (unsigned char data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & 0x80) == 0);  
	
}

unsigned char i2c_Read (unsigned char ack)
{
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	while ((TWCR & 0x80)==0);
	return TWDR;
}

void i2c_Stop (void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);	
}