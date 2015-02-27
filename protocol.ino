//#include "config.h"
//#include <Arduino.h>

static uint8_t proto_state;
static uint32_t bind_time;

#define PROTO_READY   0x01
#define PROTO_BINDING 0x02
#define PROTO_BINDDLG 0x04

void PROTOCOL_SetBindState(uint32_t msec)
{
    if (msec) {
        if (msec == 0xFFFFFFFF)
            bind_time = msec;
        else
            bind_time = millis() + msec;
        proto_state |= PROTO_BINDING;
    } else {
        proto_state &= ~PROTO_BINDING;
    }
}
