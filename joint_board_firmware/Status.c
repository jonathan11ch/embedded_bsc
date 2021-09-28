#include <stdlib.h>
#include <string.h>
#include "Status.h"





uint16_t u16_StatusCheck( void )
{
    uint16_t enable;
    uint16_t state;
    enable = statusENABLE_PORT;
    state  = statusSTATE_PORT;
    //check enable first
    if (enable == 0)
    {
        return 0;
    }
    //check state if enabled
    if(state == 0)
    {
        return 1;
    }
    else if(state == 1)
    {
        return 2;
    }
    return 0;
}


void vStatusLedToggle( void )
{
    statusLED_TRIS = 0;
    statusLED_LAT = ~statusLED_PORT;
}


void vStatusHardwareSetup( void )
{
    statusENABLE_TRIS = 1; //input enable
    statusSTATE_TRIS  = 1; //input state (switching signal)
}

