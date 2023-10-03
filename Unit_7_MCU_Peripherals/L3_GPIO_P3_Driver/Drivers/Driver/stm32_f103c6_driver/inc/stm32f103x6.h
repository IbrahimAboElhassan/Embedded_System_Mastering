/*
 * stm32f103x6.h
 *
 *  Created on: Oct 2, 2023
 *      Author: Ibrahim Abo Elhassan
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include <stdint.h>
#include <stdlib.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define SRAM_Base_Address                               0x20000000UL
#define FLASH_Memory_Base_Address                       0x08000000UL
#define System_Memory_Base_Address                      0x1FFFF000UL

#define Peripherals_Base_Address                        0x40000000UL
#define Cortex_M3_Intrenal_Peripheral_Base_Address      0xE0000000UL

//-----------------------------
//Base addresses for AHB BUS Peripherals
//-----------------------------

//RCC
#define RCC_Base_Address                                0x40021000UL

//-----------------------------
//Base addresses for APB2 BUS Peripherals
//-----------------------------

//GPIO
// A,B fully included in LQFP48 Package.
#define GPIOA_Base_Address                               0x40010800UL
#define GPIOB_Base_Address                               0x40010C00UL

// C,D partial included in LQFP48 Package.
#define GPIOC_Base_Address                               0x40011000UL
#define GPIOD_Base_Address                               0x40011400UL

// E NOT included in LQFP48 Package.
#define GPIOE_Base_Address                               0x40011800UL
//------------------------------------

//EXTI
#define EXTI_Base_Address                                0x40010400UL

//AFIO
#define AFIO_Base_Address                                0x40010000UL


//==============***========================***========================***==============
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register.
//-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_REG_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_REG_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_REG_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESERVED_0;//0x18
	volatile uint32_t MAPR2;
}AFIO_REG_typedef;

//==============***========================***========================***==============
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-
//GPIO
#define GPIOA         ((GPIO_REG_typedef *)GPIOA_Base_Address)
#define GPIOB         ((GPIO_REG_typedef *)GPIOB_Base_Address)
#define GPIOC         ((GPIO_REG_typedef *)GPIOC_Base_Address)
#define GPIOD         ((GPIO_REG_typedef *)GPIOD_Base_Address)
#define GPIOE         ((GPIO_REG_typedef *)GPIOE_Base_Address)
//RCC
#define RCC           ((RCC_REG_typedef *)RCC_Base_Address)
//EXTI
#define EXTI          ((EXTI_REG_typedef *)EXTI_Base_Address)
//AFIO
#define AFIO          ((AFIO_REG_typedef *)AFIO_Base_Address)


//==============***========================***========================***==============
//-*-*-*-*-*-*-*-*-*-*-*-
//Clock Enable Macros.
//-*-*-*-*-*-*-*-*-*-*-*-
//GPIO
#define RCC_GPIOA_Clock_Enable           (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_Clock_Enable           (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_Clock_Enable           (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_Clock_Enable           (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_Clock_Enable           (RCC->APB2ENR |= 1<<6)

//AFIO
#define RCC_AFIO_Clock_Enable           (RCC->APB2ENR |= 1<<0)



#endif /* INC_STM32F103X6_H_ */
