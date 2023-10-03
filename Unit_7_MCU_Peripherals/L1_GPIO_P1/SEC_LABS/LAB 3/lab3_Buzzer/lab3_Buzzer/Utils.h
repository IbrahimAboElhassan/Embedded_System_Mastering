/*
 * Utils.h
 *
 * Created: 9/25/2023 10:13:18 PM
 *  Author: ibrahim
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit)     reg |= (1 << bit)

#define ClearBit(reg,bit)   reg &= ~(1 << bit)

#define ToggleBit(reg,bit)  reg ^= (1 << bit)

#define ReadBit(reg,bit)    ((reg >> bit) &1)



#endif /* UTILS_H_ */