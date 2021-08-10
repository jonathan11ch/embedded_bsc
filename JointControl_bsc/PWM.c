#include <stdlib.h>
#include <string.h>
#include "PWM.h"

uint16_t value = 0;

void vPWMWritePWM1(uint16_t cmd){
    value = (uint16_t)(((uint32_t)(cmd*pwmDC_RANGE))/pwmINPUT_RESOLUTION) + pwmDC_10;
    P1DC1 = value;
}

void vPWMSetup1( void ){
    /*Main Configuration*/
    
    P1TCONbits.PTOPS  = 0;        // time base postscaler
    P1TCONbits.PTCKPS = 0;        // time base prescale
    P1TCONbits.PTMOD  = 2;        // Up-Down count mode (more resolution)
    P1TMRbits.PTMR    = 0;        // PWM1 timer count value (start at 0)
    P1TPERbits.PTPER  = pwmPTPER; // PWM1 time base period
    /*Mode Setup*/
    PWM1CON1bits.PEN1H = 1;       //enable PWM  H1 
    PWM1CON1bits.PEN1L = 0;       //disable PWM L1
    /*pairs in independent mode*/
    PWM1CON1bits.PMOD1 = 1; 
    PWM1CON1bits.PMOD2 = 1;
    PWM1CON1bits.PMOD3 = 1;
    P1DC1 = 0;
    P1TCONbits.PTEN   = 1;       // PWM1 time base is on
}
