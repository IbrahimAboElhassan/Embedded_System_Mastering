/*
 * SPI_Master.c
 *
 * Created: 10/28/2023 9:06:22 AM
 * Author : ibrahim
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS    4
#define MOSI  5
#define MISO  6
#define SCK   7

void SPI_MasterInit(void)
{
	// Set MOSI, SCK and SS as Output Pins
	DDRB |= (1<<MOSI) | (1<<SS) | (1<<SCK);
	// Set MISO as Input Pins
	DDRB &= ~(1<<MISO); 
	// Enable SPI, Master mode, Shift Clock = CLK /16
	SPCR = (1<<MSTR) | (1<<SPE) | (1<<SPR0) ;
}

unsigned char SPI_MasterTX(unsigned char data)
{
	// Start Transmission data
	SPDR = data;
	// Wait for finishing transmission
	while(!(SPSR & (1<<SPIF)));
	//Return received data
	return SPDR;	
}


int main(void)
{
	unsigned char Message; // Data to send
	DDRA = 0xFF;           // PORTA >> OUTPUT
	SPI_MasterInit();
	
	for(Message=0 ; Message<=255 ; Message++)
	{
		_delay_ms(1000);
		PORTA = SPI_MasterTX(Message);
		
	}
    
    
}

