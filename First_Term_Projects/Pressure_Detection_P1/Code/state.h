
/* state.h
*  By: Ibrahim Abo Elhassan 
*/
#ifndef STATE_H_
#define STATE_H_

#include "Driver.h"

#include "stdio.h"
#include "stdlib.h"

// State function declartion
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

// Connections States

// Pressure Sensor =======> Main Algorithm
int PS_catch_Pressure_Val();

// Main Algorithm =======> Alarm Monitor
int MA_High_Pressure_Detect();

// Alarm Monitor =======> Alarm Actuator
void Aactu_Start_Alarm();

// Alarm Monitor =======> Alarm Actuator
void Aactu_Stop_Alarm();


#endif // STATE_H_