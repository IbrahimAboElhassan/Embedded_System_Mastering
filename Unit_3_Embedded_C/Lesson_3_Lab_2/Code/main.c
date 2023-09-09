/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ibrahim Abo Elhassan
 * @brief          : Toggle LED
 ******************************************************************************
 * 
 *
*/

#include "stdint.h"

typedef volatile unsigned int vuint32_t ;

#define RCC_BASE  0x40021000
#define GPIO_BASE 0x40010800

#define RCC_APB2ENR *(volatile uint32_t *) (RCC_BASE  + 0x18)
#define GPIO_CRH    *(volatile uint32_t *) (GPIO_BASE + 0X04)
#define GPIO_ODR    *(volatile uint32_t *) (GPIO_BASE + 0x0c)

#define RCC_IOPAEN 		(1<<2)

typedef union
{
	vuint32_t all_fields;
	struct
	{
		vuint32_t reserved:13;
		vuint32_t p_13:1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR=(volatile R_ODR_t*) (GPIO_BASE + 0x0c) ;
unsigned char G_var [3] = {1 ,2 ,3};
unsigned char const const_var [3] = {1 ,2 ,3};

int main(void)
{
    RCC_APB2ENR |= RCC_IOPAEN;
    GPIO_CRH &=0xff0fffff;
    GPIO_CRH |=0x00200000;

    while(1)
    {
     	//GPIO_ODR |=1<<13;
    	R_ODR->Pin.p_13=1;
    	for(int i=0;i<5000;i++);
    	//GPIO_ODR &=~(1<<13);
    	R_ODR->Pin.p_13=0;
    	for(int i=0;i<5000;i++);

    }
}
