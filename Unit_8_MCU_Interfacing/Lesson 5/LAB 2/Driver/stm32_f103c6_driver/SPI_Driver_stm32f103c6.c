/*
 * SPI_Driver_stm32f103c6.c
 *
 *  Created on: Nov 2, 2023
 *      Author: ibrahim
 */


#include <SPI_Driver_stm32f103c6.h>


/*
* ===============================================
* 					Generic Variables
* ===============================================
* */

SPI_PinConfig_t* G_SPI_config[2] = {NULL , NULL};

/*
* ===============================================
* 					Generic Macros
* ===============================================
* */

#define SPI1_Index            0
#define SPI2_Index            1

#define SPI_SR_TXE            (uint8_t)(0x02)                   // Transmit buffer empty
#define SPI_SR_RXNE           (uint8_t)(0x01)                   // Receive buffer NOT empty

/*
* ===============================================
* 					APIs Function Definitions
* ===============================================
*/

/**================================================================
 * @Fn           - MCAL_SPI_Init
 * @brief        - Initialization of SPI
 * @param [in]   - SPIx: where x is (1,2)
 * @param [in]   - SPI_config: All configuration for SPI
 * @retval       - None
 * Note          - None
 */

void MCAL_SPI_Init(SPI_REG_typedef *SPIx, SPI_PinConfig_t* SPI_config)
{
	uint16_t tmp_CR1 = 0;
	uint16_t tmp_CR2 = 0;

	if(SPIx == SPI1)
	{
		G_SPI_config[SPI1_Index] = SPI_config;
		RCC_SPI1_Clock_Enable;

	}else if (SPIx == SPI2)
	{
		G_SPI_config[SPI2_Index] = SPI_config;
		RCC_SPI2_Clock_Enable;
	}

	// Enable SPI >> Bit 6 SPE: SPI enable
	tmp_CR1 = (0x1U << 6);

	// Mode operation Master or Slave
	tmp_CR1 |= SPI_config->Device_Mode;

	// SPI communication mode
	tmp_CR1 |= SPI_config->Communication_Mode;

	// SPI frame format
	tmp_CR1 |= SPI_config->Frame_Format;

	// SPI data size
	tmp_CR1 |= SPI_config->Data_Size;

	// SPI CLK Polarity
	tmp_CR1 |= SPI_config->CLK_Polarity;

	// SPI CLK Phase
	tmp_CR1 |= SPI_config->CLK_Phase;

	// NSS
	if(SPI_config->NSS == SPI_NSS_HW_Master_ss_output_Enable )
	{
		tmp_CR2 |= SPI_config->NSS;

	}else if(SPI_config->NSS == SPI_NSS_HW_Master_ss_output_Disable)
	{
		tmp_CR2 &= SPI_config->NSS;
	}else
	{
		tmp_CR1 |= SPI_config->NSS;
	}

	//SPI_Baud rate
	tmp_CR1 |= SPI_config->SPI_Clock_Frequency;

	// Interrupt
	if(SPI_config->IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		tmp_CR2 |= SPI_config->IRQ_Enable;

		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}else if(SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}

	SPIx->CR1 = tmp_CR1;
	SPIx->CR2 = tmp_CR2;

}

/**================================================================
 * @Fn           - MCAL_SPI_Deinit
 * @brief        - Deinitialization of SPI
 * @param [in]   - SPIx: where x is (1,2)
 * @retval       - None
 * Note          - None
 */
void MCAL_SPI_Deinit(SPI_REG_typedef *SPIx)
{
	if(SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_Clock_Disable;
	}else if (SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_Clock_Disable;
	}

}

/**================================================================
 * @Fn           - MCAL_SPI_SendData
 * @brief        - Send buffer through SPI
 * @param [in]   - SPIx: where x is (1,2)
 * @param [in]   - TxBuffer
 * @param [in]   - Polling enable or not
 * @retval       - None
 * Note          - None
 */
void MCAL_SPI_SendData(SPI_REG_typedef *SPIx, uint16_t *TX_Buffer, enum Polling_Mech pollingEN)
{
	if(pollingEN == Enable)
		while(!(SPIx->SR & SPI_SR_TXE));

	SPIx->DR = *TX_Buffer;
}


/**================================================================
 * @Fn           - MCAL_SPI_ReceiveData
 * @brief        - Receive data
 * @param [in]   - SPIx: where x is (1,2)
 * @param [in]   - RxBuffer
 * @param [in]   - Polling enable or not
 * @retval       - None
 * Note          - None
 */
void MCAL_SPI_ReceiveData(SPI_REG_typedef *SPIx, uint16_t *RX_Buffer, enum Polling_Mech pollingEN)
{
	if(pollingEN == Enable)
			while(!(SPIx->SR & SPI_SR_RXNE));

	*RX_Buffer = SPIx->DR;
}


/**================================================================
 * @Fn           - MCAL_SPI_TX_RX
 * @brief        - Receive  and Transmit data
 * @param [in]   - SPIx: where x is (1,2)
 * @param [in]   - TxBuffer
 * @param [in]   - Polling enable or not
 * @retval       - None
 * Note          - None
 */
void MCAL_SPI_TX_RX(SPI_REG_typedef *SPIx, uint16_t *TX_Buffer, enum Polling_Mech pollingEN)
{
	if(pollingEN == Enable)
		while(!(SPIx->SR & SPI_SR_TXE));
	SPIx->DR = *TX_Buffer;

	if(pollingEN == Enable)
		while(!(SPIx->SR & SPI_SR_RXNE));
	*TX_Buffer = SPIx->DR;
}


/**================================================================
 * @Fn           - MCAL_SPI_GPIO_SET_PINs
 * @brief        - Initialization GPIO pins
 * @param [in]   - SPIx: where x is (1,2)
 * Note          - None
 */
void MCAL_SPI_GPIO_SET_PINs(SPI_REG_typedef *SPIx)
{
	GPIO_PinConfig_t PinCFG;

	if(SPIx == SPI1)
	{
		//   For SPI1
		// PA4 <<>> NSS
		// PA5 <<>> SCK
		// PA6 <<>> MISO
		// PA7 <<>> MOSI

		if(G_SPI_config[SPI1_Index]->Device_Mode == SPI_Device_Mode_Master)
		{
			// PA4 <<>> NSS
			switch(G_SPI_config[SPI1_Index]->NSS)
			{
			case SPI_NSS_HW_Master_ss_output_Disable:
				PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
				MCAL_GPIO_Init(GPIOA, &PinCFG);
				break;

			case SPI_NSS_HW_Master_ss_output_Enable:
				PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				PinCFG.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
				PinCFG.GPIO_Output_Speed = GPIO_Speed_10MHz;
				MCAL_GPIO_Init(GPIOA, &PinCFG);
				break;
			}

			// PA5 <<>> SCK
			PinCFG.GPIO_PinNumber = GPIO_PIN_5;
			PinCFG.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
			PinCFG.GPIO_Output_Speed = GPIO_Speed_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			// PA6 <<>> MISO >> full duplex.
			PinCFG.GPIO_PinNumber = GPIO_PIN_6;
			PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			// PA7 <<>> MOSI
			PinCFG.GPIO_PinNumber = GPIO_PIN_7;
			PinCFG.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
			PinCFG.GPIO_Output_Speed = GPIO_Speed_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinCFG);


		}else
		{
			if(G_SPI_config[SPI1_Index]->NSS == SPI_NSS_HW_Slave)
			{
				PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
				MCAL_GPIO_Init(GPIOA, &PinCFG);
			}

			//PA5 <<>> SCK
			PinCFG.GPIO_PinNumber = GPIO_PIN_5;
			PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			// PA6 <<>> MISO
			PinCFG.GPIO_PinNumber = GPIO_PIN_6;
			PinCFG.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
			PinCFG.GPIO_Output_Speed = GPIO_Speed_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			// PA7 <<>> MOSI
			PinCFG.GPIO_PinNumber = GPIO_PIN_7;
			PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
			MCAL_GPIO_Init(GPIOA, &PinCFG);


		}

	}else if (SPIx == SPI2)
	{
		//   For SPI2
		// PB12 <<>> NSS
		// PB13 <<>> SCK
		// PB14 <<>> MISO
		// PB15 <<>> MOSI

		if(G_SPI_config[SPI2_Index]->Device_Mode == SPI_Device_Mode_Master)
				{
						//PB12 <<>> NSS
					switch(G_SPI_config[SPI2_Index]->NSS)
					{
					case SPI_NSS_HW_Master_ss_output_Disable:
						PinCFG.GPIO_PinNumber = GPIO_PIN_12;
						PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
						MCAL_GPIO_Init(GPIOB, &PinCFG);
						break;

					case SPI_NSS_HW_Master_ss_output_Enable:
						PinCFG.GPIO_PinNumber = GPIO_PIN_12;
						PinCFG.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
						PinCFG.GPIO_Output_Speed = GPIO_Speed_10MHz;
						MCAL_GPIO_Init(GPIOB, &PinCFG);
						break;
					}

					// PB13 <<>> SCK
					PinCFG.GPIO_PinNumber = GPIO_PIN_13;
					PinCFG.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
					PinCFG.GPIO_Output_Speed = GPIO_Speed_10MHz;
					MCAL_GPIO_Init(GPIOB, &PinCFG);

					// PB14 <<>> MISO >> full duplex.
					PinCFG.GPIO_PinNumber = GPIO_PIN_14;
					PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
					MCAL_GPIO_Init(GPIOB, &PinCFG);

					// PB15 <<>> MOSI
					PinCFG.GPIO_PinNumber = GPIO_PIN_15;
					PinCFG.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
					PinCFG.GPIO_Output_Speed = GPIO_Speed_10MHz;
					MCAL_GPIO_Init(GPIOB, &PinCFG);


				}else
				{
					if(G_SPI_config[SPI2_Index]->NSS == SPI_NSS_HW_Slave)
					{
						PinCFG.GPIO_PinNumber = GPIO_PIN_12;
						PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
						MCAL_GPIO_Init(GPIOB, &PinCFG);
					}

					//PA5 <<>> SCK
					PinCFG.GPIO_PinNumber = GPIO_PIN_13;
					PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
					MCAL_GPIO_Init(GPIOB, &PinCFG);

					// PA6 <<>> MISO
					PinCFG.GPIO_PinNumber = GPIO_PIN_14;
					PinCFG.GPIO_Mode = GPIO_Mode_Output_Alt_Flo_PP;
					PinCFG.GPIO_Output_Speed = GPIO_Speed_10MHz;
					MCAL_GPIO_Init(GPIOB, &PinCFG);

					// PA7 <<>> MOSI
					PinCFG.GPIO_PinNumber = GPIO_PIN_15;
					PinCFG.GPIO_Mode = GPIO_Mode_Input_Floating;
					MCAL_GPIO_Init(GPIOB, &PinCFG);

	}
}



// =======================IRQ===============================

void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC irq_SCR;

	irq_SCR.TXE  = ((SPI1->SR & (1<<1)) >> 1);
	irq_SCR.RXNE = ((SPI1->SR & (1<<0)) >> 0);
	irq_SCR.ERRI = ((SPI1->SR & (1<<4)) >> 4);

	G_SPI_config[SPI1_Index]->P_IRQ_Callback(irq_SCR);
}

void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC irq_SCR;

	irq_SCR.TXE  = ((SPI2->SR & (1<<1)) >> 1);
	irq_SCR.RXNE = ((SPI2->SR & (1<<0)) >> 0);
	irq_SCR.ERRI = ((SPI2->SR & (1<<4)) >> 4);

	G_SPI_config[SPI2_Index]->P_IRQ_Callback(irq_SCR);
}
}
