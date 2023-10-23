/*
 * UART_ATmega32.c
 *
 * Created: 10/23/2023 10:54:31 AM
 * Author : ibrahim
 */ 

#include "ATmega32_GPIO_Driver.h"
#include "ATmega32_USART_Driver.h"
#include "HAL/LCD.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


uint8_t data = 0;


int main(void)
{
	
	LCD_INIT();
	MCAL_USART_Init();
	LCD_WRITE_STRING("Hello UART");

	MCAL_USART_Send('H');
	MCAL_USART_Send('I');
	MCAL_USART_Send('M');
	MCAL_USART_Send('A');
	
	while (1)
	{
		LCD_GOTOXY(1,0);
		
		data = MCAL_USART_Receive();
		LCD_WRITE_CHAR(data);

	}
	
	return 0;
}













