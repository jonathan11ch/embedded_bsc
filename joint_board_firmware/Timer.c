#include <stdlib.h>
#include <string.h>
#include "Timer.h"

void vTimerTMR1Setup(void){
    /* T1CON register config */
    T1CONbits.TON   = 0;     //Reset timer counter
    T1CONbits.TSIDL = 0;     //Continue operation during IDLE
    T1CONbits.TGATE = 0;     //Gated time accumulation disables
    T1CONbits.TCS   = 0;     //Select internal clock source FOSC/2
    T1CONbits.TCKPS = 0b10;  //Prescalser selection Tcy/presc
    /* setup period */
    PR1 = 56;
    /* Clear interruption flag */
    IFS0bits.T1IF  = 0;     //Clear timer 1 interruption flag 
    IEC0bits.T1IE  = 1;     //Enable timer1 interrupts
    /* turn on timer */
    T1CONbits.TON   = 1;
}
