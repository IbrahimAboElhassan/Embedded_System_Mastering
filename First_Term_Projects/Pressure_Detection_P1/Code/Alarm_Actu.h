
#ifndef ALARM_ACTU_H_
#define ALARM_ACTU_H_

#include "state.h"

// state functions declaration for alarm actuator.
STATE_define(Aactu_init);
STATE_define(Aactu_waiting);
STATE_define(Aactu_ACT_ON);
STATE_define(Aactu_ACT_OFF);


#endif // ALARM_ACTU_H_