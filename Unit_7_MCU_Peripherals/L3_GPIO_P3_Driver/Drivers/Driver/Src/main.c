/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ibrahim Abo Elhassan
 * @brief          : Toggle LEDs by using GPIO driver
 ******************************************************************************
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "GPIO_Driver_stm32f103c6.h"

void GPIO_init()
{
	//PORTA Highz
	GPIO_PinConfig_t PinCfg;
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Mode      = GPIO_Mode_Input_Floating;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//PA13 is input floating
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_Mode      = GPIO_Mode_Input_Floating;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//PB1 is output push pull
	PinCfg.GPIO_PinNumber    = GPIO_PIN_1;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB13 is output push pull
	PinCfg.GPIO_PinNumber    = GPIO_PIN_13;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}

void CLOCK_init()
{
	//Enable GPIOA clock
	RCC_GPIOA_Clock_Enable;
	//Enable GPIOB clock
	RCC_GPIOB_Clock_Enable;
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

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)           //press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);             //toggle LED
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);   //single press
		}

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)          //Multi press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}

		WAIT(1);

	}
}
