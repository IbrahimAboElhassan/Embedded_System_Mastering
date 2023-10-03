/*
 * MemoryMap.h
 *
 * Created: 9/25/2023 3:32:36 PM
 *  Author: ibrahim
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

//GPIOA
#define DDRA   (*(volatile unsigned char *)0x3A)
#define PORTA  (*(volatile unsigned char *)0x3B)
#define PINA   (*(volatile unsigned char *)0x39)

//GPIOC
#define DDRC   (*(volatile unsigned char *)0x34)
#define PORTC  (*(volatile unsigned char *)0x35)
#define PINC   (*(volatile unsigned char *)0x33)






#endif /* MEMORYMAP_H_ */