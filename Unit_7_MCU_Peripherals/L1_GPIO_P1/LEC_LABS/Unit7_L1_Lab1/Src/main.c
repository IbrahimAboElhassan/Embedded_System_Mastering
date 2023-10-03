/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ibrahim Abo Elhassan
 * @brief          : Main program body
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>

// GPIO PORTA
#define GPIOA_BASE      0x40010800
#define GPIOA_CRL      *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH      *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR      *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR      *(volatile uint32_t *)(GPIOA_BASE + 0x08)

// GPIO PORTB
#define GPIOB_BASE      0x40010C00
#define GPIOB_CRL      *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH      *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR      *(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR      *(volatile uint32_t *)(GPIOB_BASE + 0x08)

//RCC
#define RCC_BASE        0x40021000
#define RCC_APB2ENR    *(volatile uint32_t *)(RCC_BASE + 0x18)

void GPIO_init()
{
	GPIOA_CRL = 0;
	GPIOA_CRH = 0;
	GPIOA_ODR = 0;
	GPIOB_CRL = 0;
	GPIOB_CRH = 0;
	GPIOB_ODR = 0;

	//PA1 is input floating
	GPIOA_CRL &= ~(0b11<<4);
	GPIOA_CRL |= (0b01<<6);

	//PA13 is input floating
	GPIOA_CRH &= ~(0b11<<20);
	GPIOA_CRH |= (0b01<<22);

	//PB1 is output push pull
	GPIOB_CRL |= (0b01<<4);
	GPIOB_CRL &= ~(0b11<<6);

	//PB13 is output push pull
	GPIOB_CRH |= (0b01 << 20);
	GPIOB_CRH &= ~(0b11 << 22);

}

void CLOCK_init()
{
	//Enable GPIOA clock
	RCC_APB2ENR |= (1<<2);
	//Enable GPIOB clock
	RCC_APB2ENR |= (1<<3);
}

void WAIT(uint32_t time)
{
	uint32_t counter1 , counter2;
	for(counter1 = 0 ; counter1 < time ; counter1++)
		for(counter2 = 0 ; counter2 < 255 ; counter2++);
}

int main(void)
{
	CLOCK_init();
	GPIO_init();

	while(1)
	{

		if(((GPIOA_IDR & (1<<1)) >> 1) == 0) //press
		{
			GPIOB_ODR ^= (1<<1); //toggle LED
			while((((GPIOA_IDR & (1<<1)) >> 1) == 0));//single press
		}

		if(((GPIOA_IDR & (1<<13)) >> 13) == 1)//Multi press
		{
			GPIOB_ODR ^= (1<<13);
		}

		WAIT(1);

	}
}
