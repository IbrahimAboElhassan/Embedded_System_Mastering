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

#define NVIC_Base_Address                               0xE000E100UL
#define NVIC_ISER0                                      *(volatile uint32_t*)(NVIC_Base_Address + 0x0 )
#define NVIC_ISER1                                      *(volatile uint32_t*)(NVIC_Base_Address + 0x4 )
#define NVIC_ISER2                                      *(volatile uint32_t*)(NVIC_Base_Address + 0x8 )
#define NVIC_ICER0                                      *(volatile uint32_t*)(NVIC_Base_Address + 0x80)
#define NVIC_ICER1                                      *(volatile uint32_t*)(NVIC_Base_Address + 0x84)
#define NVIC_ICER2                                      *(volatile uint32_t*)(NVIC_Base_Address + 0x88)


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
	volatile uint32_t EVCR     ;
	volatile uint32_t MAPR     ;
	volatile uint32_t EXTICR[4];
	uint32_t RESERVED_0        ;//0x18
	volatile uint32_t MAPR2    ;
}AFIO_REG_typedef              ;

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



//==============***========================***========================***==============
//-*-*-*-*-*-*-*-*-*-*-*-
//Interrupt Vector Table.
//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI
#define EXTI0_IRQ     6
#define EXTI1_IRQ     7
#define EXTI2_IRQ     8
#define EXTI3_IRQ     9
#define EXTI4_IRQ     10
#define EXTI5_IRQ     23
#define EXTI6_IRQ     23
#define EXTI7_IRQ     23
#define EXTI8_IRQ     23
#define EXTI9_IRQ     23
#define EXTI10_IRQ    40
#define EXTI11_IRQ    40
#define EXTI12_IRQ    40
#define EXTI13_IRQ    40
#define EXTI14_IRQ    40
#define EXTI15_IRQ    40


//==============***========================***========================***==============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Enable & Disable NVIC IRQ Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Enable
#define NVIC_IRQ6_EXTI0_Enable             			 (NVIC_ISER0 |= 1 << 6 )
#define NVIC_IRQ7_EXTI1_Enable             		     (NVIC_ISER0 |= 1 << 7 )
#define NVIC_IRQ8_EXTI2_Enable             			 (NVIC_ISER0 |= 1 << 8 )
#define NVIC_IRQ9_EXTI3_Enable            	   		 (NVIC_ISER0 |= 1 << 9 )
#define NVIC_IRQ10_EXTI4_Enable                		 (NVIC_ISER0 |= 1 << 10)
#define NVIC_IRQ23_EXTI5_9_Enable              		 (NVIC_ISER0 |= 1 << 23)
#define NVIC_IRQ40_EXTI10_15_Enable            		 (NVIC_ISER1 |= 1 << 8 )      // (40 - 32 = 8)

//Disable
#define NVIC_IRQ6_EXTI0_Disable             		 (NVIC_ICER0 |= 1 << 6 )
#define NVIC_IRQ7_EXTI1_Disable             		 (NVIC_ICER0 |= 1 << 7 )
#define NVIC_IRQ8_EXTI2_Disable             		 (NVIC_ICER0 |= 1 << 8 )
#define NVIC_IRQ9_EXTI3_Disable            	         (NVIC_ICER0 |= 1 << 9 )
#define NVIC_IRQ10_EXTI4_Disable                     (NVIC_ICER0 |= 1 << 10)
#define NVIC_IRQ23_EXTI5_9_Disable                   (NVIC_ICER0 |= 1 << 23)
#define NVIC_IRQ40_EXTI10_15_Disable                 (NVIC_ICER1 |= 1 << 8 )      // (40 - 32 = 8)


#endif /* INC_STM32F103X6_H_ */
