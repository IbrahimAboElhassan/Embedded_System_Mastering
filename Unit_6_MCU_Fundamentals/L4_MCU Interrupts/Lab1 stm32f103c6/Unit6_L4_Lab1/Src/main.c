/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ibrahim Abo Elhassan
 * @brief          : Toggle LED
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stdint.h"

//RCC
#define RCC_BASE      0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *) (RCC_BASE + 0x18)

//GPIO
#define GPIO_BASE    0x40010800
#define GPIO_CRH    *(volatile uint32_t *) (GPIO_BASE + 0X04)
#define GPIO_CRL    *(volatile uint32_t *) (GPIO_BASE + 0X00)
#define GPIO_ODR    *(volatile uint32_t *) (GPIO_BASE + 0x0c)

//EXTI
#define EXTI_BASE    0x40010400
#define EXTI_IMR    *(volatile uint32_t *) (EXTI_BASE + 0x00)
#define EXTI_RTSR   *(volatile uint32_t *) (EXTI_BASE + 0x08)
#define EXTI_PR     *(volatile uint32_t *) (EXTI_BASE + 0x14)

//AFIO
#define AFIO_BASE         0x40010000
#define AFIO_EXTICR1     *(volatile uint32_t *) (AFIO_BASE + 0x08)

//NVIC
#define NVIC_EXTIE0     *(volatile uint32_t *) (0xE000E100)

void GPIO_init()
{
	// Pin 13 PORTA output
	GPIO_CRH &=0xff0fffff;
	GPIO_CRH |=0x00200000;

	// Floating input (reset state)
	GPIO_CRL |= (1<<2);
}

void clock_init()
{
	// Alternate Function IO clock enabled
	RCC_APB2ENR |= (1<<0);

	// Enable clock GPIOA.
	RCC_APB2ENR |= (1<<2);
}


int main(void)
{
	clock_init();
	GPIO_init();

	// EXTI x configuration (x= 0).
	AFIO_EXTICR1 = 0;

	// Enable Rising trigger selection.
	EXTI_RTSR |= (1<<0);

	// Enable EXTI line 0 (mask >> 1)
	EXTI_IMR |= (1<<0);

	// Enable NVIC IRQ 6
	NVIC_EXTIE0 |= (1<<6);

	while(1);

}

void EXTI0_IRQHandler(void)
{
	// Toggle Led pin A 13
	GPIO_ODR ^= (1<<13);

	// Clear Pending request for line 0
	EXTI_PR |= (1<<0);
}


