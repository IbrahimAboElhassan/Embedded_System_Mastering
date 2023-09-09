/*
 * CA.h
 *
 *  Created on: Aug 24, 2023
 *      Author: ibrahim
 */

#ifndef CA_H_
#define CA_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Automatic STATE Function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

/*enum
{
	CA_waiting, CA_driving
}CA_state_id;*/

//State pointer to function
extern void(*CA_state)();
//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

// declare ultrasonic random function
int US_Get_distance_random(int l, int r, int count);



#endif /* CA_H_ */
