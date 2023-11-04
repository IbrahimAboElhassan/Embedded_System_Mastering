/*
 * SPI_Driver_stm32f103c6.h
 *
 *  Created on: Nov 2, 2023
 *      Author: ibrahim
 */

#ifndef INC_SPI_DRIVER_STM32F103C6_H_
#define INC_SPI_DRIVER_STM32F103C6_H_

//-----------------------------
//Includes
//-----------------------------

#include <stm32f103x6.h>
#include "GPIO_Driver_stm32f103c6.h"


//-----------------------------
//User type definitions (Structure configuration)
//-----------------------------

struct S_IRQ_SRC
{
	uint8_t TXE     :1 ; // TX buffer EMPTY Interrupt.
	uint8_t RXNE    :1 ; // RX buffer NOT EMPTY Interrupt.
	uint8_t ERRI    :1 ; // Error Interrupt.
	uint8_t Reseved :5 ;

};



typedef struct
{
	uint16_t Device_Mode            ;    // Specify SPI operation mode it is master or slave.
	                                     // @ref SPI_Device_Mode.

	uint16_t Communication_Mode     ;    // Define SPI direction mode state
	                                     // @ref SPI_Communication_Mode.

	uint16_t Frame_Format           ;    // Specify MSB or LSB
										 // @ref SPI_Frame_Format.

	uint16_t Data_Size              ;    // @ref SPI_Data_Size.


	uint16_t CLK_Polarity           ;    // @ref SPI_CLK_Polarity.


	uint16_t CLK_Phase              ;    // @ref SPI_CLK_Phase.


	uint16_t NSS                    ;    // Specify if NSS signal is managed by H.W (NSS pin) or S.W (SSI bit Enable or Disable)
										 // @ref SPI_NSS.

	uint16_t SPI_Clock_Frequency    ;    // Specify the baud rate prescaler value which configure transmit or receive SCK clock
	                                     // @ref SPI_Clock_Frequency.

	uint16_t IRQ_Enable             ;    // if you want enable interrupt. @ref SPI_IRQ_Enable


	void(* P_IRQ_Callback)(struct S_IRQ_SRC irq_SCR)    ;    // This function will call once IRQ happen


}SPI_PinConfig_t;


//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref SPI_Device_Mode
#define SPI_Device_Mode_Slave                     (0x00000000U)           //CR1.MSTR <<>> Slave configuration
#define SPI_Device_Mode_Master                    (0x1U<<2)               //CR1.MSTR <<>> Master configuration

//@ref SPI_Communication_Mode
#define SPI_Direction_2Lines                      (0x00000000U)
#define SPI_Direction_2Lines_RX_Only              (0x1U<<10)              // Bit 10 RXONLY: Receive only
#define SPI_Direction_1Lines_RX_Only              (0x1U<<15)              // Bit 15 BIDIMODE: Bidirectional data mode enable
#define SPI_Direction_1Lines_TX_Only              (0x1U<<15) | (0x1U<<14) // Bit 15 BIDIMODE: Bidirectional data mode enable & Bit 14 BIDIOE: Output enable in bidirectional mode.

//@ref SPI_Frame_Format
#define SPI_Frame_Format_MSB_transmitted_first    (0x00000000U)
#define SPI_Frame_Format_LSB_transmitted_first    (0x1U<<7)               // Bit 7.1 >>LSB_transmitted_first

// @ref SPI_Data_Size
#define SPI_Data_Size_8bits                       (0x00000000U)
#define SPI_Data_Size_16bits                      (0x1U<<11)              // Bit 11.1 >>16-bit data frame format is selected for transmission/reception

// @ref SPI_CLK_Polarity
#define SPI_CLK_Polarity_Idle_Low                 (0x00000000U)
#define SPI_CLK_Polarity_Idle_High                (0x1U<<1)               // Bit1 >> CK to 1 when idle

// @ref SPI_CLK_Phase
#define SPI_CLK_Phase_first_clock_transition      (0x00000000U)
#define SPI_CLK_Phase_second_clock_transition     (0x1U<<0)               // Bit 0 >> The second clock transition is the first data capture edge

//@ref SPI_NSS
#define SPI_NSS_HW_Slave                          (0x00000000U)
#define SPI_NSS_HW_Master_ss_output_Enable        (0x1U<<2)
#define SPI_NSS_HW_Master_ss_output_Disable       ~(0x1U<<2)

#define SPI_NSS_SW_Set_SSI                        (0x1U<<9) | (0x1U<<8)
#define SPI_NSS_SW_Reset_SSI                      (0x1U<<9)

//@ref SPI_Clock_Frequency
#define SPI_Clock_Frequency_2                     (0x00000000U)
#define SPI_Clock_Frequency_4                     (0b001U<<3)
#define SPI_Clock_Frequency_8                     (0b010U<<3)
#define SPI_Clock_Frequency_16                    (0b011U<<3)
#define SPI_Clock_Frequency_32                    (0b100U<<3)
#define SPI_Clock_Frequency_64                    (0b101U<<3)
#define SPI_Clock_Frequency_128                   (0b110U<<3)
#define SPI_Clock_Frequency_256                   (0b111U<<3)

//@ref SPI_IRQ_Enable
#define SPI_IRQ_Enable_NONE                        (uint32_t)(0)
#define SPI_IRQ_Enable_TXEIE                       (uint32_t)(1<<7)     // Tx buffer empty interrupt enable
#define SPI_IRQ_Enable_RXNEIE                      (uint32_t)(1<<6)     // RX buffer not empty interrupt enable
#define SPI_IRQ_Enable_ERRIE                       (uint32_t)(1<<5)     // Error interrupt enable


enum Polling_Mech
{
	Enable,
	Disable
};

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/


void MCAL_SPI_Init(SPI_REG_typedef *SPIx, SPI_PinConfig_t* SPI_config);
void MCAL_SPI_Deinit(SPI_REG_typedef *SPIx);

void MCAL_SPI_GPIO_SET_PINs(SPI_REG_typedef *SPIx);

void MCAL_SPI_SendData(SPI_REG_typedef *SPIx, uint16_t *TX_Buffer, enum Polling_Mech pollingEN);
void MCAL_SPI_ReceiveData(SPI_REG_typedef *SPIx, uint16_t *RX_Buffer, enum Polling_Mech pollingEN);

void MCAL_SPI_TX_RX(SPI_REG_typedef *SPIx, uint16_t *TX_Buffer, enum Polling_Mech pollingEN);





#endif /* INC_SPI_DRIVER_STM32F103C6_H_ */
