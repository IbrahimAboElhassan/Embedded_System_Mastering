/*
 * i2c.h
 *
 * Created: 2/22/2024 11:54:07 AM
 *  Author: Ibrahim AboElhassan
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "CPU_CONFIGURATION.h"

void i2c_Init (unsigned long SCL_Clock);
void i2c_Start (void);
void i2c_Write (unsigned char cbyte);
void i2c_Stop (void);


#endif /* I2C_H_ */