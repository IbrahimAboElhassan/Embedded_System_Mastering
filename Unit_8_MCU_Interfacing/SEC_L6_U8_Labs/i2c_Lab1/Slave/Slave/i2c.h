/*
 * i2c.h
 *
 * Created: 2/22/2024 1:07:58 PM
 *  Author: ibrahim
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "CPU_CONFIGURATION.h"

void i2c_Set_Address (unsigned char address);
unsigned char i2c_Read (unsigned char ack);


#endif /* I2C_H_ */