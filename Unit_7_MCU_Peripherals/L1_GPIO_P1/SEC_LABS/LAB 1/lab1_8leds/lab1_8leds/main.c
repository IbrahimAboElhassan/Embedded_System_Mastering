/*
 * lab1_8leds.c
 *
 * Created: 9/25/2023 3:15:44 PM
 * Author : Ibrahim Abo Elhassan
 */ 

#include "MemoryMap.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#include "Utils.h"

int main(void)
{
	// Set all PORTA pins as outputs
	DDRA = 0xFF;
	
	while (1)
	{
		//Turn ON all LEDs one by one
		for (int count = 0; count < 8; count++)
		{
			
			SetBit(PORTA,count);
			_delay_ms(100);
		}
		
		_delay_ms(500);
		
		//Turn OFF all LEDs one by one reversely
		for (int count = 7; count >= 0; count--)
		{
			
			ClearBit(PORTA,count);
			_delay_ms(100);
		}
		
		_delay_ms(500);
	}
	
	return 0;
}


