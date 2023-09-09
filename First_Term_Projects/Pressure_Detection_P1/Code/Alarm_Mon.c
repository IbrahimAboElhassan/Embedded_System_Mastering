#include "Alarm_Mon.h"

//Define status.
enum{
    AM_alarmOFF,
    AM_alarmON,
    AM_waiting
}AM_Status;

// state pointer to function.
extern void (*AM_state)();

STATE_define(AM_alarmOFF)
{
    //state action.
    AM_Status = AM_alarmOFF;

    //stop alarm actuator.
    Aactu_Stop_Alarm();

    if(MA_High_Pressure_Detect() != 0)
    {
        AM_state = STATE(AM_alarmON);
    }

}
STATE_define(AM_alarmON)
{
    AM_Status = AM_alarmON;

    // start alarm actuator.
    Aactu_Start_Alarm();

    AM_state = STATE(AM_waiting);

}
STATE_define(AM_waiting)
{
    AM_Status = AM_waiting;

    GPIO_Delay(6000);

    AM_state = STATE(AM_alarmOFF);

}