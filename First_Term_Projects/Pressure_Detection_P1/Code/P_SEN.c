#include "P_SEN.h"

static int P_Val = 0;

// Define Status
enum{
    PS_init,
    PS_Reading,
    PS_waiting,
}Status_PS;

// state pointer to function
extern void (*PS_state)();

STATE_define(PS_init)
{
    //state action
    Status_PS = PS_init;

    // check event and update state
    PS_state = STATE(PS_Reading);
}

STATE_define(PS_Reading)
{
    // state action
    Status_PS = PS_Reading;

    // read from pressure sensor.
    P_Val = GPIO_getPressureVal();

    // check event and update state
    PS_state = STATE(PS_waiting);

}

STATE_define(PS_waiting)
{
    // state action
    Status_PS = PS_waiting;

    // wait for date
    GPIO_Delay(1000);

    // check event and update state
    PS_state = STATE(PS_Reading);
}

// interface with main algorithm.
int PS_catch_Pressure_Val()
{
    return P_Val;
}