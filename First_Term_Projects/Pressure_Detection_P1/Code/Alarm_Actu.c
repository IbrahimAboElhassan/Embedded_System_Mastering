
#include "Alarm_Actu.h"

#define TRUE 1
#define FALSE 0

// status define
enum{
    Aactu_init,
    Aactu_waiting,
    Aactu_ACT_ON,
    Aactu_ACT_OFF
}A_Act_Status;

// state pointer to function.
extern void (*Aactu_state)();

STATE_define(Aactu_init)
{
    //state action
    A_Act_Status = Aactu_init;

    // check event and update state
    Aactu_state = STATE(Aactu_waiting);

}
STATE_define(Aactu_waiting)
{
    //state action.
    A_Act_Status = Aactu_waiting;

}
STATE_define(Aactu_ACT_ON)
{
    //state action
    A_Act_Status = Aactu_ACT_ON;

    //start alarm actuator.
    GPIO_Set_Alarm_actuator(TRUE);

    // check event and update state
    Aactu_state = STATE(Aactu_waiting);
}
STATE_define(Aactu_ACT_OFF)
{
    //state action.
    A_Act_Status = Aactu_ACT_OFF;

    GPIO_Set_Alarm_actuator(FALSE);

    // check event and update state
    Aactu_state = STATE(Aactu_waiting);

}


void Aactu_Start_Alarm()
{
    //Update state
    Aactu_state = STATE(Aactu_ACT_ON);
}

void Aactu_Stop_Alarm()
{
    //Update state
    Aactu_state = STATE(Aactu_ACT_OFF);
}
