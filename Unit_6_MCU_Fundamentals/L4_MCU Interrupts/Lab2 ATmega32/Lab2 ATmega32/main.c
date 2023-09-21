/*
 * Lab2 ATmega32.c
 *
 * Created: 9/19/2023 11:06:40 PM
 * Author : ibrahim Abo Elhassan
 */ 

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	//Led ON
	PORTD |= 1<<5;
	//for 1 sec
	_delay_ms(100);
}

ISR(INT1_vect)
{
	//Led ON
	PORTD |= 1<<6;
	//for 1 sec
	_delay_ms(100);
}

ISR(INT2_vect)
{
	//Led ON
	PORTD |= 1<<7 ;
	//for 1 sec
	_delay_ms(100);
}
int main(void)
{
	//Active any logical change mode for INT0
	MCUCR |= (1<<0 |  1<<2 | 1<< 3);
	//Active rising edge mode for INT1
	MCUCR &= ~(1<<1);
	//Active falling edge mode for INT2
	MCUCSR &= ~(1<<6);
	
	//Enable External Interrupt Request (1, 2, 3) 
	GICR |= (1<<5 |  1<<6 | 1<< 7);
	
	//Enable global interrupt 
	sei(); 
	
	DDRD |= (1<<5) | (1<<6) | (1<<7) ; 
    while(1)
    {
		// Defult led is off 
		PORTD &= ~((1<<5) | (1<<6) | (1<<7)) ; 
    }
}

