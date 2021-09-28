/* 
 * File:   main.c
 * Author: jacasasb
 *
 * Created on July 28, 2021, 4:33 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "Firmware.h"
#include "Encoder.h"



/*
 * 
 */

void ToggleLed( void )
{
    TRISBbits.TRISB6 = 0;
    LATBbits.LATB6 = ~PORTBbits.RB6;
}


void __attribute__((__interrupt__, auto_psv)) _T1Interrupt( void )
{
    vFirmwareMainRoutine();
    return;
}


void __attribute__((__interrupt__,auto_psv)) _QEI1Interrupt(void)
{
    vEncoderOnJointCounterReset();
}

void __attribute__((__interrupt__,auto_psv)) _QEI2Interrupt(void)
{
    vEncoderOnPulleyCounterReset();
}

//void __attribute__((__interrupt__,auto_psv)) _U1RXInterrupt(void)
//{
//    extern volatile uint8_t IsDataRecevied; 
//    extern volatile uint16_t IntraDataRX;
//    ToggleLed();
//    IsDataRecevied = 1;
//    IntraDataRX = U1RXREG;
//    IFS0bits.U1RXIF = 0;    //clear UART1 RX interrupt flag   
//}



/*
 * 
 * 
 * 
 */
int main(int argc, char** argv) {
    /* Configure Hardware */
    vFirmwareHardwareSetup();

    vFirmwareInitialRoutine();
    for ( ;; )
    {
		vFirmwareIdleRoutine();
    }
    return (EXIT_SUCCESS);
}

