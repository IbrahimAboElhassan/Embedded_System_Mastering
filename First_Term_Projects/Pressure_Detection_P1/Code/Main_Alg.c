
#include "Main_Alg.h"

// Define status.
enum {
    MA_High_Pressure
}MA_Status;

// state pointer to function.
extern void (*MA_state)();

int MA_P_Val = 0;
int MA_Threshold = 20;

STATE_define(MA_High_Pressure)
{
    // state action
    MA_Status = MA_High_Pressure;
    
    // read pressure value from pressure sensor.
    MA_P_Val = PS_catch_Pressure_Val();

    //check event and update state.
    MA_state = STATE(MA_High_Pressure);
}

// interface with Alarm monitor.
int MA_High_Pressure_Detect()
{
    return(MA_P_Val > MA_Threshold);
}