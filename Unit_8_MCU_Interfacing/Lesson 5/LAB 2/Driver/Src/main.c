/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ibrahim Abo Elhassan
 * @brief          :
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//#define MCU_Act_As_Master
#define MCU_Act_As_Slave

#include "stm32f103x6.h"
#include "GPIO_Driver_stm32f103c6.h"
#include "USART_Driver_stm32f103c6.h"
#include "RCC_Driver_stm32f103c6.h"
#include "SPI_Driver_stm32f103c6.h"

//#include "lcd.h"
//#include "keypad.h"
//#include "EXTI_Driver_stm32f103c6.h"

//unsigned int IRQ_Flag = 0;
unsigned char ch;
GPIO_PinConfig_t PinCfg;

// 7_SEGMENT
/*
#define ZERO  0x01
#define ONE   0x79
#define TWO   0x24
#define THREE 0x30
#define FOUR  0x4C
#define FIVE  0x12
#define SIX   0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE  0x10
*/

void GPIO_init()
{
	//PORTA Highz
	//GPIO_PinConfig_t PinCfg;
	/*
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
	MCAL_GPIO_Init(GPIOB, &PinCfg);*/

	//==========================================================
	/*PinCfg.GPIO_PinNumber 	 = GPIO_PIN_9;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber    = GPIO_PIN_10;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber    = GPIO_PIN_11;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber    = GPIO_PIN_12;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber    = GPIO_PIN_13;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber    = GPIO_PIN_14;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber    = GPIO_PIN_15;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);*/
	//==========================================================



}

void CLOCK_init()
{
	//Enable GPIOA clock
	RCC_GPIOA_Clock_Enable;
	//Enable GPIOB clock
	RCC_GPIOB_Clock_Enable;
	//Enable AFIO clock
	RCC_AFIO_Clock_Enable;
}


void SPI_IRQ_callback(struct S_IRQ_SRC irq_SCR)
{
#ifdef MCU_Act_As_Slave
	if(irq_SCR.RXNE)
	{
		ch = 0xF;
		MCAL_SPI_TX_RX(SPI1, &ch, Disable);
		MCAL_USART_SendData(USART1, &ch, enable);
	}
#endif
}


void IRQ_callback()
{
#ifdef MCU_Act_As_Master
	MCAL_USART_ReceiveData(USART1, &ch, disable);
	MCAL_USART_SendData(USART1, &ch, enable);

	// send to SPI
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	MCAL_SPI_TX_RX(SPI1, &ch, Enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

#endif
}

/*void WAIT(uint32_t time)
{
	uint32_t counter1 , counter2;
	for(counter1 = 0 ; counter1 < time ; counter1++)
		for(counter2 = 0 ; counter2 < 255 ; counter2++);
}*/

/*void EXTI9_Callback(void)
{
	IRQ_Flag = 1;

	LCD_WRITE_STRING("IRQ EXTI9 is happened _|-");
	WAIT(1000);

}*/





int main(void)
{
	//=====================L5_U8_SPI//=====================//

	// UART INIT

	USART_PinConfig_t U_CFG;
	CLOCK_init();
	U_CFG.BaudRate = USART_BaudRate_115200;
	U_CFG.HwFlowControl = USART_HwFlowControl_NONE;
	U_CFG.IRQ_Enable = USART_IRQ_Enable_RXNEIE;
	U_CFG.P_IRQ_Callback = IRQ_callback;
	U_CFG.Parity_Check = USART_Parity_Check_NONE;
	U_CFG.Data_Length = USART_Data_Length_8B;
	U_CFG.StopBit = USART_StopBit_1;
	U_CFG.USART_Mode = USART_Mode_TX_RX;

	MCAL_USART_Init(USART1, &U_CFG);
	MCAL_USART_GPIO_SET_PIN(USART1);

	// SPI INIT

	// Common Configuration
	SPI_PinConfig_t SPI_PinCFG;
	SPI_PinCFG.CLK_Phase = SPI_CLK_Phase_second_clock_transition;
	SPI_PinCFG.CLK_Polarity = SPI_CLK_Polarity_Idle_High;
	SPI_PinCFG.Data_Size = SPI_Data_Size_8bits;
	SPI_PinCFG.Frame_Format = SPI_Frame_Format_MSB_transmitted_first;
	// Assume it is default pclk2 = 8MHz
	SPI_PinCFG.SPI_Clock_Frequency = SPI_Clock_Frequency_8;
	SPI_PinCFG.Communication_Mode = SPI_Direction_2Lines;

#ifdef MCU_Act_As_Master
	SPI_PinCFG.Device_Mode = SPI_Device_Mode_Master;
	SPI_PinCFG.IRQ_Enable = SPI_IRQ_Enable_NONE;
	SPI_PinCFG.NSS = SPI_NSS_SW_Set_SSI;
	SPI_PinCFG.P_IRQ_Callback = NULL;

	PinCfg.GPIO_PinNumber    = GPIO_PIN_4;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOA, &PinCfg);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
#endif

#ifdef MCU_Act_As_Slave
	SPI_PinCFG.Device_Mode = SPI_Device_Mode_Slave;
	SPI_PinCFG.IRQ_Enable = SPI_IRQ_Enable_RXNEIE;
	SPI_PinCFG.NSS = SPI_NSS_HW_Slave;
	SPI_PinCFG.P_IRQ_Callback = SPI_IRQ_callback;

#endif
	MCAL_SPI_Init(SPI1, &SPI_PinCFG);
	MCAL_SPI_GPIO_SET_PINs(SPI1);

/*	PinCfg.GPIO_PinNumber    = GPIO_PIN_4;
	PinCfg.GPIO_Mode         = GPIO_Mode_Output_Push_Pull;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOA, &PinCfg);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);*/



 //====================================================================//

	/*LCD_INIT();
	unsigned char key_pressed;
	LCD_WRITE_STRING("Hi, Iam Hima");
	WAIT(30);
	LCD_clear_screen();
	GPIO_init();
	unsigned char LCD_Display [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char SEG_Display [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};

	for (unsigned char i = 0; i < 11; i++)
	{
		LCD_WRITE_CHAR(LCD_Display[i]);
		MCAL_GPIO_WritePort(GPIOB, SEG_Display[i] << 9); // write data on to the LED port
		// wait for 1 second
		WAIT(100);
	}

	LCD_clear_screen();
	Keypad_init();
	LCD_WRITE_STRING("Keypad is ready");
	WAIT(30);
	LCD_clear_screen();


	//===============================L4_Unit7===================================
	//Enable clock
	RCC_GPIOA_Clock_Enable;
	RCC_GPIOB_Clock_Enable;
	RCC_AFIO_Clock_Enable ;

	LCD_INIT();
	LCD_clear_screen();

	EXIT_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN       = EXTI9PB9;
	EXTI_CFG.Trigger_Case   = EXTI_Trigger_Rising;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_Callback;
	EXTI_CFG.IRQ_Enable     = EXTI_IRQ_Enable;

	MCAL_EXTI_GPIO_Init(&EXTI_CFG);

	IRQ_Flag = 1;*/


	while(1)
	{
		//=====================L5_U8_SPI//=====================//









		//=========================L3_Unit8===========================
		MCAL_USART_ReceiveData(USART1, &ch,enable);		MCAL_USART_SendData(USART1, &ch, enable);




		/*key_pressed = Keypad_getkey();
		switch (key_pressed) {
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);
			break;
		}

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)           //press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);             //toggle LED
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);   //single press
		}

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)          //Multi press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}

		WAIT(1);*/

		//=========================L4_Unit7===========================
/*
		if(IRQ_Flag)
		{
			LCD_clear_screen();
			IRQ_Flag = 0;
		}
*/




	}
}