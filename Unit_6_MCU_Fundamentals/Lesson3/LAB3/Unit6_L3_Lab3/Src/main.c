/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ibrahim Abo ELhassan
 * @brief          : control speed of buses in stm32f103c6    > APB1 Bus frequency 16MHZ
 *                                                            > APB2 Bus frequency 8MHZ
 *                                                            > AHB frequency 32 MHZ
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
#define GPIOA_BASE     0x40010800
#define GPIOA_CRH      *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR      *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE       0x40021000
#define RCC_APB2ENR    *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR       *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR         *(volatile uint32_t *)(RCC_BASE + 0x00)

int main(void)
{
	// PLL input clock x 8
	RCC_CFGR |= (0b0110 << 18);

	// Enable PLL
	RCC_CR |= 1<<24;

	// PLL selected as system clock
	RCC_CFGR |= (0b10 << 0);

	// Enable 101 to make internal speed of stm divided on 4 to make speed in APB2 Bus= 2MHZ.
	RCC_CFGR |= (0b101 << 11);

	// Enable 100 to make internal speed of stm divided on 2 to make speed in APB1 Bus= 4MHZ.
	RCC_CFGR |= (0b100 << 8);


	//Init GPIOA
	RCC_APB2ENR |= 1<<2 ;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
