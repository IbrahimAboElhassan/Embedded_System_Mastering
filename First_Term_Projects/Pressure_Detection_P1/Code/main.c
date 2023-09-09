
/* main.c
*  By: Ibrahim Abo Elhassan 
*/

#include <stdio.h>
#include <stdlib.h>

#include "Driver.h"
#include "P_SEN.h"
#include "Main_Alg.h"
#include "Alarm_Mon.h"
#include "Alarm_Actu.h"

void (*PS_state)() = STATE(PS_init);
void (*Aactu_state)() = STATE(Aactu_init);
void (*AM_state)() = STATE(AM_alarmOFF);
void (*MA_state)() = STATE(MA_High_Pressure);

int main()
{
    // initialization hardware
    GPIO_INITIALIZATION();

    while(1)
    {
        PS_state();
        Aactu_state();
        AM_state();
        MA_state();

    }

    return 0;
}