/*
 * MemoryMap.h
 *
 * Created: 9/25/2023 10:13:05 PM
 *  Author: ibrahim
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

//GPIOD
#define PORTD *(volatile unsigned int *)(0x32)
#define DDRD  *(volatile unsigned int *)(0x31)
#define PIND  *(volatile unsigned int *)(0x30)

//Special Function IO Register
#define SFIOR  *(volatile unsigned int *)(0x50)


#endif /* MEMORYMAP_H_ */