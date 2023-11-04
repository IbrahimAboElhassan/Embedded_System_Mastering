/*
 * USART_Driver_stm32f103c6.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Ibrahim Abo Elhassan
 */

#include "USART_Driver_stm32f103c6.h"
#include "GPIO_Driver_stm32f103c6.h"



/*
* ===============================================
* 					Generic Variables
* ===============================================
* */


USART_PinConfig_t* Global_USART_config = NULL;


/*
* ===============================================
* 					APIs Function Definitions
* ===============================================
*/

/**================================================================
 * @Fn           - MCAL_USART_Init
 * @brief        - Initialization of USART
 * @param [in]   - USARTx: where x is (1,2,3..)
 * @param [in]   - P_Cfg: All configuration for USART
 * @retval       - None
 * Note          - None
 */
void MCAL_USART_Init(USART_REG_typedef* USARTx ,USART_PinConfig_t* P_Cfg)
{
	Global_USART_config = P_Cfg;
	uint32_t pclk , BRR;

    // Enable USART peripherals clock.
	if (USARTx == USART1)
		RCC_USART1_Clock_Enable;

	else if (USARTx == USART2)
		RCC_USART2_Clock_Enable;

	else if (USARTx == USART3)
		RCC_USART3_Clock_Enable;

	// Enable USART Module (Bit 13 UE: USART enable)
	USARTx->CR1 |= (1 << 13);
	// Enable TX,RX
	USARTx->CR1 |= P_Cfg->USART_Mode;
	// Data length
	USARTx->CR1 |= P_Cfg->Data_Length;
	// Configuration of parity bit.
	USARTx->CR1 |= P_Cfg->Parity_Check;
	// Stop bit
	USARTx->CR2 |= P_Cfg->StopBit;
	// Flow control
	USARTx->CR3 |= P_Cfg->HwFlowControl;
	// Configuration of BRR
	// PCLK 1 <<>> USART 2,3
	// PCLK 2 <<>> USART 1

	if (USARTx == USART1)
	{
		pclk = MCAL_RCC_Get_PCLK2_Freq();
	}
	else
	{
		pclk = MCAL_RCC_Get_PCLK1_Freq();
	}

	BRR = USART_BRR_REG(pclk , P_Cfg->BaudRate);
	USARTx->BRR = BRR;

	if(P_Cfg->IRQ_Enable != USART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |=  P_Cfg->IRQ_Enable;
	
	   if(USARTx == USART1)
			NVIC_IRQ37_USART1_Enable;
	   else if (USARTx == USART2)
			NVIC_IRQ38_USART2_Enable;
	   else if (USARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}
}


/**================================================================
 * @Fn           - MCAL_USART_DeInit
 * @brief        - De-Initialization of USART
 * @param [in]   - USARTx: where x is (1,2,3..)
 * @retval       - None
 * Note          - None
 */
void MCAL_USART_DeInit(USART_REG_typedef* USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_Clock_Disable;
		NVIC_IRQ37_USART1_Disable;
	}
	else if(USARTx == USART2)
	{
		RCC_USART2_Clock_Disable;
		NVIC_IRQ38_USART2_Disable;
	}
	else if(USARTx == USART3)
	{
		RCC_USART3_Clock_Disable;
		NVIC_IRQ39_USART3_Disable;
	}

}



/**================================================================
 * @Fn           - MCAL_USART_SendData
 * @brief        - Send buffer on USART
 * @param [in]   - USARTx: where x is (1,2,3..)
 * @param [in]   - PTxBuffer
 * @param [in]   - Polling enable or not
 * @retval       - None
 * Note          - None
 */
void MCAL_USART_SendData(USART_REG_typedef* USARTx , uint16_t* PTxBuffer , enum Polling_mechansim pollingEn)
{
	if(pollingEn == enable)
		while(!((USARTx->SR) & (1 << 7)));

	if(Global_USART_config->Data_Length == USART_Data_Length_9B)
	{
		USARTx->DR = (*PTxBuffer & (uint16_t)0x01FF);
	}else
	{
		USARTx->DR = (*PTxBuffer & (uint8_t)0xFF);
	}
}




/**================================================================
 * @Fn           - MCAL_USART_Wait_TC
 * @brief        - checking that transmit complete
 * @param [in]   - USARTx: where x is (1,2,3..)
 * @retval       - None
 * Note          - None
 */
void MCAL_USART_Wait_TC(USART_REG_typedef* USARTx )
{
	while(!((USARTx->SR) & (1 << 6)));
}




/**================================================================
 * @Fn           - MCAL_USART_ReceiveData
 * @brief        - Receive data
 * @param [in]   - USARTx: where x is (1,2,3..)
 * @param [in]   - PRxBuffer
 * @param [in]   - Polling enable or not
 * @retval       - None
 * Note          - None
 */
void MCAL_USART_ReceiveData(USART_REG_typedef* USARTx , uint16_t* PRxBuffer , enum Polling_mechansim pollingEn)
{
	if(pollingEn == enable)
		while(!((USARTx->SR) & (1 << 5)));

	if(Global_USART_config->Data_Length == USART_Data_Length_9B)
	{
			if(Global_USART_config->Parity_Check == USART_Parity_Check_NONE)
			{
				*((uint16_t*)PRxBuffer) = USARTx->DR;
			}
			else
			{
				*((uint16_t*)PRxBuffer) = (USARTx->DR & (uint8_t)0xFF);
			}
	}else
	{
		if(Global_USART_config->Parity_Check == USART_Parity_Check_NONE)
		{
			*((uint16_t*)PRxBuffer) = (USARTx->DR & (uint8_t)0xFF);
		}
		else
		{
			*((uint16_t*)PRxBuffer) = (USARTx->DR & (uint8_t)0x7F);
		}

	}

}


/**================================================================
 * @Fn           - MCAL_USART_GPIO_SET_PIN
 * @brief        - Initialization GPIO pins
 * @param [in]   - USARTx: where x is (1,2,3..)
 * Note          - None
 */
void MCAL_USART_GPIO_SET_PIN(USART_REG_typedef* USARTx)
{
	GPIO_PinConfig_t Pconfig;

	if(USARTx == USART1)
	{
		Pconfig.GPIO_PinNumber = GPIO_PIN_9;
		Pconfig.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
		Pconfig.GPIO_Output_Speed = GPIO_Speed_10MHz;
		MCAL_GPIO_Init(GPIOA, &Pconfig);

		Pconfig.GPIO_PinNumber = GPIO_PIN_10;
		Pconfig.GPIO_Mode = GPIO_Mode_Input_Floating;
		MCAL_GPIO_Init(GPIOA, &Pconfig);

		if(Global_USART_config->HwFlowControl == USART_HwFlowControl_CTS || Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS_CTS)
		{
			Pconfig.GPIO_PinNumber = GPIO_PIN_11;
			Pconfig.GPIO_Mode = GPIO_Mode_Input_Floating;
			MCAL_GPIO_Init(GPIOA, &Pconfig);

		}

		if(Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS || Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS_CTS)
		{
			Pconfig.GPIO_PinNumber = GPIO_PIN_12;
			Pconfig.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
			Pconfig.GPIO_Output_Speed = GPIO_Speed_10MHz;
			MCAL_GPIO_Init(GPIOA, &Pconfig);
		}

	}

	else if (USARTx == USART2)
	{
		Pconfig.GPIO_PinNumber = GPIO_PIN_2;
		Pconfig.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
		Pconfig.GPIO_Output_Speed = GPIO_Speed_10MHz;
		MCAL_GPIO_Init(GPIOA, &Pconfig);

		Pconfig.GPIO_PinNumber = GPIO_PIN_3;
		Pconfig.GPIO_Mode = GPIO_Mode_ALT_FLO_Input;
		MCAL_GPIO_Init(GPIOA, &Pconfig);

		if(Global_USART_config->HwFlowControl == USART_HwFlowControl_CTS || Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS_CTS)
		{
			Pconfig.GPIO_PinNumber = GPIO_PIN_0;
			Pconfig.GPIO_Mode = GPIO_Mode_Input_Floating;
			MCAL_GPIO_Init(GPIOA, &Pconfig);

		}

		if(Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS || Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS_CTS)
		{
			Pconfig.GPIO_PinNumber = GPIO_PIN_1;
			Pconfig.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
			Pconfig.GPIO_Output_Speed = GPIO_Speed_10MHz;
			MCAL_GPIO_Init(GPIOA, &Pconfig);
		}

	}

	else if (USARTx == USART3)
	{
		Pconfig.GPIO_PinNumber = GPIO_PIN_10;
		Pconfig.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
		Pconfig.GPIO_Output_Speed = GPIO_Speed_10MHz;
		MCAL_GPIO_Init(GPIOB, &Pconfig);

		Pconfig.GPIO_PinNumber = GPIO_PIN_11;
		Pconfig.GPIO_Mode = GPIO_Mode_Input_Floating;
		MCAL_GPIO_Init(GPIOB, &Pconfig);


		if(Global_USART_config->HwFlowControl == USART_HwFlowControl_CTS || Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS_CTS)
		{
			Pconfig.GPIO_PinNumber = GPIO_PIN_13;
			Pconfig.GPIO_Mode = GPIO_Mode_Input_Floating;
			MCAL_GPIO_Init(GPIOB, &Pconfig);

		}

		if(Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS || Global_USART_config->HwFlowControl == USART_HwFlowControl_RTS_CTS)
		{
			Pconfig.GPIO_PinNumber = GPIO_PIN_14;
			Pconfig.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
			Pconfig.GPIO_Output_Speed = GPIO_Speed_10MHz;
			MCAL_GPIO_Init(GPIOB, &Pconfig);
		}

	}


}



void USART1_IRQHandler(void)
{
	Global_USART_config->P_IRQ_Callback();
}
void USART2_IRQHandler(void)
{
	Global_USART_config->P_IRQ_Callback();
}
void USART3_IRQHandler(void)
{
	Global_USART_config->P_IRQ_Callback();
}

