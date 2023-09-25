/*
 * lab2_switchLEDs.c
 *
 * Created: 9/25/2023 3:31:06 PM
 * Author : Ibrahim Abo Elhassan
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Utils.h"

int main(void)
{
	// Set all PORTA pins as outputs
	DDRA = 0xFF;

	// Make PORTC0 as input
	ClearBit(DDRC, 0);
	SetBit(PORTC, 0);

	unsigned char count = 0;
	unsigned char prev_switch_state = 1; // In case not pressed

	while (1)
	{
		// Read the state of the switch on PINC0
		unsigned char switch_state = ReadBit(PINC, 0);

		// Check if the switch is pressed and it was not pressed in the previous loop iteration
		if (switch_state == 0 && prev_switch_state != 0)
		{
			// Turn on the LED at the current count
			SetBit(PORTA, count);
			count++;

			// Check if count exceeds 7 
			if (count > 7)
			count = 0;
		}

		// Update the previous switch state
		prev_switch_state = switch_state;

		// Delay to prevent rapid toggling
		_delay_ms(10); // Adjust this delay as needed
	}

	return 0;
}



