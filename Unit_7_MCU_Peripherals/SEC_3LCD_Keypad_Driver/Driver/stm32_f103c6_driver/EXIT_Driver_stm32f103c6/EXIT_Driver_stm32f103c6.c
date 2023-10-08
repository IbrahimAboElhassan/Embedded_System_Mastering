/*
 * EXIT_Driver_stm32f103c6.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Ibrahim Abo Elhassan
 */


#include <EXTI_Driver_stm32f103c6.h>
#include "GPIO_Driver_stm32f103c6.h"

/*
* ===============================================
* 					Generic Macros
* ===============================================
*/
#define AFIO_GPIO_EXTI_Mapping(x)     ( (x == GPIOA)?0:\
									    (x == GPIOB)?1:\
									    (x == GPIOC)?2:\
									    (x == GPIOD)?3:0 )




/*
* ===============================================
* 					Generic Variables
* ===============================================
* */

	void (* GP_IRQ_CallBack[15])(void);    //to recode all handling.




/*
* ===============================================
* 					Generic Functions
* ===============================================
*/

void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;
	}

}


void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;
	}

}



void Update_EXTI(EXIT_PinConfig_t *EXTI_PConfig)
{
	// 1-Configure GPIO to be AFIO Input <<>> Floating Input.
	GPIO_PinConfig_t PINcfg;
	// Update the GPIO pin to Input floating.
	PINcfg.GPIO_PinNumber = EXTI_PConfig->EXTI_PIN.EXTI_Pin;
	PINcfg.GPIO_Mode      = GPIO_Mode_Input_Floating;
	MCAL_GPIO_Init(EXTI_PConfig->EXTI_PIN.GPIO_Port, &PINcfg);

	//===================================================================
	// 2-Update AFIO pin to be route between port A,B,C and D and with EXTI Line.

	uint8_t AFIO_EXTICR_Index    = EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber / 4 ;

	uint8_t AFIO_EXTICR_Position = (EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber % 4) * 4 ;

	//Clear four bits first.
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_PConfig->EXTI_PIN.GPIO_Port) & 0xF) << AFIO_EXTICR_Position);

	//===================================================================
	// 3- Update Rising and falling trigger.

	//Clear them first because may be use them in update during run time.
	EXTI->RTSR &= ~(1 << EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &= ~(1 << EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);

	// Check which case of trigger edge.
	if(EXTI_PConfig->Trigger_Case == EXTI_Trigger_Rising)
	{
		EXTI->RTSR |= (1 << EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_PConfig->Trigger_Case == EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1 << EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_PConfig->Trigger_Case == EXTI_Trigger_RFBoth)
	{
		EXTI->RTSR |= (1 << EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1 << EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);
	}

	//===================================================================
	// 4-Update IRQ handling callback.

	GP_IRQ_CallBack[EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber] = EXTI_PConfig->P_IRQ_CallBack;



	//===================================================================
	// 5-Enable & Disable IRQ EXTI & NVIC.

	if(EXTI_PConfig->IRQ_Enable == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1 << EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);
		Enable_NVIC(EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);

	}else
	{
		EXTI->IMR &= ~(1 << EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);
		Disable_NVIC(EXTI_PConfig->EXTI_PIN.EXTI_InputLineNumber);
	}

}


/*
* ===============================================
* 					APIs Function Definitions
* ===============================================
*/

/**================================================================
 * @Fn           - MCAL_EXTI_GPIO_DeInit
 * @brief        - Reset EXTI registers and NVIC corresponding to IRQ mask.
 * @param [in]   - None
 * @retval       - None
 * Note          - None
 */
void MCAL_EXTI_GPIO_DeInit(void)
{
	//Disable EXTI Registers.
	EXTI->IMR    = 0x00000000;
	EXTI->EMR    = 0x00000000;
	EXTI->RTSR   = 0x00000000;
	EXTI->FTSR   = 0x00000000;
	EXTI->SWIER  = 0x00000000;
	EXTI->PR     = 0xFFFFFFFF;             // Write 1 to clear it according to TRM.

	//Disable EXTI IRQ from NVIC.
	 NVIC_IRQ6_EXTI0_Disable        ;
	 NVIC_IRQ7_EXTI1_Disable        ;
	 NVIC_IRQ8_EXTI2_Disable        ;
	 NVIC_IRQ9_EXTI3_Disable        ;
	 NVIC_IRQ10_EXTI4_Disable       ;
	 NVIC_IRQ23_EXTI5_9_Disable     ;
	 NVIC_IRQ40_EXTI10_15_Disable   ;
}



/**================================================================
 * @Fn           - MCAL_EXTI_GPIO_Init
 * @brief        - This is used to initialize EXTI from specific GPIO pin and specify the mask, Trigger and IRQ callback.
 * @param [in]   - EXTI_PConfig: Set by @ref EXTI_define, EXIT_Trigger_define and EXIT_IRQ_define.
 * @retval       - None
 * Note          - None
 */
void MCAL_EXTI_GPIO_Init(EXIT_PinConfig_t *EXTI_PConfig)
{
	Update_EXTI(EXTI_PConfig);
}



/**================================================================
 * @Fn           - MCAL_EXTI_GPIO_Update
 * @brief        - This is used to initialize EXTI from specific GPIO pin and specify the mask, Trigger and IRQ callback.
 * @param [in]   - EXTI_PConfig: Set by @ref EXTI_define, EXIT_Trigger_define and EXIT_IRQ_define.
 * @retval       - None
 * Note          - None
 */
void MCAL_EXTI_GPIO_Update(EXIT_PinConfig_t *EXTI_PConfig)
{
	Update_EXTI(EXTI_PConfig);
}







/*
* ===============================================
* 					ISR Functions
* ===============================================
* */

void EXTI0_IRQHandler(void)
{
	//Clear pending register EXTI_PR by writing 1.
	EXTI->PR |= (1 << 0);

	//Call IRQ.
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void)
{
	//Clear pending register EXTI_PR by writing 1.
	EXTI->PR |= (1 << 1);

	//Call IRQ.
	GP_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler(void)
{
	//Clear pending register EXTI_PR by writing 1.
	EXTI->PR |= (1 << 2);

	//Call IRQ.
	GP_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler(void)
{
	//Clear pending register EXTI_PR by writing 1.
	EXTI->PR |= (1 << 3);

	//Call IRQ.
	GP_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler(void)
{
	//Clear pending register EXTI_PR by writing 1.
	EXTI->PR |= (1 << 4);

	//Call IRQ.
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & 1<<5) { EXTI->PR |= (1 << 5) ; GP_IRQ_CallBack[5](); }
	if(EXTI->PR & 1<<6) { EXTI->PR |= (1 << 6) ; GP_IRQ_CallBack[6](); }
	if(EXTI->PR & 1<<7) { EXTI->PR |= (1 << 7) ; GP_IRQ_CallBack[7](); }
	if(EXTI->PR & 1<<8) { EXTI->PR |= (1 << 8) ; GP_IRQ_CallBack[8](); }
	if(EXTI->PR & 1<<9) { EXTI->PR |= (1 << 9) ; GP_IRQ_CallBack[9](); }
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & 1<<10) { EXTI->PR |= (1 << 10) ; GP_IRQ_CallBack[10](); }
	if(EXTI->PR & 1<<11) { EXTI->PR |= (1 << 11) ; GP_IRQ_CallBack[11](); }
	if(EXTI->PR & 1<<12) { EXTI->PR |= (1 << 12) ; GP_IRQ_CallBack[12](); }
	if(EXTI->PR & 1<<13) { EXTI->PR |= (1 << 13) ; GP_IRQ_CallBack[13](); }
	if(EXTI->PR & 1<<14) { EXTI->PR |= (1 << 14) ; GP_IRQ_CallBack[14](); }
	if(EXTI->PR & 1<<15) { EXTI->PR |= (1 << 15) ; GP_IRQ_CallBack[15](); }
}








