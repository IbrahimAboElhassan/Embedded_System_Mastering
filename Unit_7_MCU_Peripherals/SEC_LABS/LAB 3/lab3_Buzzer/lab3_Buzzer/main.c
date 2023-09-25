/*
 * lab3_Buzzer.c
 *
 * Created: 9/25/2023 10:12:42 PM
 * Author : ibrahim
 */ 

#define F_CPU 8000000UL
#include "MemoryMap.h"
#include <util/delay.h>
#include "Utils.h"


int main(void)
{
	//Set PORTD4 as an output
	SetBit(DDRD, 4);
	//Enable pull-up resistor for PORTD0
	SetBit(SFIOR, 2);
	//Set PORTD0 as an input
	ClearBit(DDRD, 0); 
	while (1)
	{
		if (ReadBit(PIND, 0) == 1) //Check if the button is pressed
		{
			SetBit(PORTD, 4); // Turn ON buzzer
			_delay_ms(100);
			ClearBit(PORTD, 4); //Turn OFF buzzer
		}
	}
}

