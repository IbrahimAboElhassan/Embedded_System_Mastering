#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth:Ibrahim Mohamed";
unsigned const char string_buffer2[100] = "learn-in-depth:Ibrahim Mohamed";
void main(void)
{
	Uart_Send_String(string_buffer);
}