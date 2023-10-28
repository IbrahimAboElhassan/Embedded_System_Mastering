/*
 * SPI_7Segment.c
 *
 * Created: 10/28/2023 11:02:39 AM
 * Author : Ibrahim
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS   4
#define MOSI 5
#define SCK  7

void SPI_MasterInit(void)
{
	// Set MOSI, SCK and SS output
	DDRB |= (1<<MOSI) | (1<<SS) | (1<<SCK);
	// Enable SPI, Master, set clock rate fck/16
	SPCR |= (1<<MSTR) | (1<<SPE) | (1<<SPR0);
}

void Execute(unsigned char command, unsigned char data)
{
	// Init packet by make SS low
	PORTB &= ~(1<<SS);
	// Start transmission Command
	SPDR = command;
	// Wait to finish transmission Command
	while(!(SPSR & (1<<SPIF)));
	// Start transmission data
	SPDR = data;
	// Wait to finish transmission data
	while(!(SPSR & (1<<SPIF)));
	// Terminate packet by make SS high
	PORTB |= (1<<SS);
} 

int main(void)
{
	unsigned char counter = 0;
	unsigned char Index_display = 1;
	SPI_MasterInit();
	
	Execute(0x09 , 0xFF);  // Decode all display
	Execute(0x0A , 0xFF);  // Max intensity 
	Execute(0x0B , 0xF7);  // Set scan limit
	Execute(0x0C , 0x01);  // Turn on display
	
    while (1) 
    {
		for(Index_display=1 ; Index_display<9 ; Index_display++)
		{
			Execute(Index_display , counter++);
			_delay_ms(1000);
		}
    }
}

