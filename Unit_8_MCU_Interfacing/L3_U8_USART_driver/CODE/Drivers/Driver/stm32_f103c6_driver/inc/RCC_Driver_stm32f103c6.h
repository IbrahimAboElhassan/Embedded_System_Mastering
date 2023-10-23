/*
 * RCC_Driver_stm32f103c6.h
 *
 *  Created on: Oct 6, 2023
 *      Author: Ibrahim Abo Elhassan
 */

#ifndef INC_RCC_DRIVER_STM32F103C6_H_
#define INC_RCC_DRIVER_STM32F103C6_H_

//-----------------------------
//Includes
//-----------------------------

#include <stm32f103x6.h>
#include "GPIO_Driver_stm32f103c6.h"

#define HSI_system_clock   (uint32_t)8000000
#define HSE_system_clock   (uint32_t)16000000


//APIs
uint32_t MCAL_RCC_Get_System_CLK_Freq(void);
uint32_t MCAL_RCC_Get_HCLK_Freq(void);
uint32_t MCAL_RCC_Get_PCLK1_Freq(void);
uint32_t MCAL_RCC_Get_PCLK2_Freq(void);

#endif /* INC_RCC_DRIVER_STM32F103C6_H_ */
