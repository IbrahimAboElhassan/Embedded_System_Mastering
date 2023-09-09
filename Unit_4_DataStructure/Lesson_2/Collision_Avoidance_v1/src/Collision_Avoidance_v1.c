/*
 ============================================================================
 Name        : Collision_Avoidance_v1.c
 Author      : Ibrahim Abo Elhassan
 Description : C program for Ultrasonic sensor to avoid collision.
 ============================================================================
 */

#include "CA.h"
void setup()
{
	// init all the drivers
	// init IRQ ....
	// init HAL US_Drivier DC_Driver
	// init Block
	// Set States pointers for each Block
	CA_state = STATE(CA_waiting);
}

int main()
{
    volatile int d;
	setup();
	srand(time(NULL)); // initialize random seed
	while (1)
	{
		// call state for each Block
		CA_state();
        for(d = 0;d<=1000;d++);
	}
	return 0; // add return statement for main function
}
