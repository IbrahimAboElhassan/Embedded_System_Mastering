/*
 * SPI_Slave.c
 *
 * Created: 10/28/2023 9:27:54 AM
 * Author : ibrahim
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS    4
#define MOSI  5
#define MISO  6
#define SCK   7

void SPI_SlaveInit(void)
{
	// Set MISO >> OUTPUT
	DDRB |= (1<<MISO);
	// Set MOSI, SS and SCK as INPUT pins
	DDRB &= ~(1<<MOSI) & ~(1<<SS) & ~(1<<SCK);
	// Enable SPI as a slave
	SPCR = (1<<SPE); 
}

unsigned char SPI_SlaveRX(unsigned char data)
{
	SPDR = data;                 // Start transmission data to master
	while(!(SPSR & (1<<SPIF)));  // Wait for finishing transmission
	return SPDR;                 // Return received data
}


int main(void)
{
    unsigned char message = 255; // Data to send
	DDRA = 0xFF;                 // PORTA >> OUTPUT
	SPI_SlaveInit();
	
	for(message=255 ; message>=0 ; message--)
	{
		PORTA = SPI_SlaveRX(message);
	}
}

