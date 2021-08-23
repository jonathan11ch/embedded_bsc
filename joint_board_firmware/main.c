/* 
 * File:   main.c
 * Author: jacasasb
 *
 * Created on July 28, 2021, 4:33 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "Encoder.h"
#include "PWM.h"
#include "Timer.h"
#include "Control.h"
#include "ADC.h"
#include "UART.h"




/*
 * 
 */
volatile unsigned int tickCount = 0;
unsigned int receivedChar, ADCValue;

void toggleOutput(void){
    PORTBbits.RB4 = ~PORTBbits.RB4;
}

void auxClockConfig(void){
    ACLKCONbits.SELACLK = 0; // Primary PLL (Fvco) provides source clock
    
}


void setLED(uint16_t value, uint16_t v){
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB3 = 0;
    LATBbits.LATB4 = value;
    LATBbits.LATB3 = v;
}

void PLLConfig(void){
    PLLFBD  = 28;                // M  = 30
    CLKDIVbits.PLLPRE  =   0;    // N1 = 2
    CLKDIVbits.PLLPOST =   0;    // N2 = 2
    ACLKCONbits.APSTSCLR = 7;    //divide auxiliary clock by 1
    while(OSCCONbits.LOCK !=1);  //wait for PLL to lock
}






void vDebugQEIPorts( void )
{
    TRISBbits.TRISB7 = 0;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB9 = 0;
    
}

void ToggleLed( void )
{
    TRISBbits.TRISB6 = 0;
    LATBbits.LATB6 = ~PORTBbits.RB6;
}


void __attribute__((__interrupt__, auto_psv)) _T1Interrupt( void )
{
    /* Clear interruption flags */
    IFS0bits.T1IF = 0;
    ToggleLed();
    vADCReadInputVoltageCh0();
    vEncoderPulleyPositionCalculation();
    vEncoderPulleyVelocityCalculation();
    vEncoderJointPositionCalculation();
    vEncoderJointVelocityCalculation();
    vUARTWriteIntraData();
    vUARTReadIntraData();
    
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



void vMainHardwareSetup( void )
{
    /* PWM Setup */
    vPWMSetup1();
    /* Encoder interfaces */
    vEncoderJointSetup();
    vEncoderPulleySetup();
    /* ADC setup */
    vADCControlInputSetup();
    /* Setup control loop timer */
    vTimerTMR1Setup();
    vUARTIntraCommunicationSetup();
    //EncoderPos = POS1CNT;
    vPWMWritePWM1( POS1CNT );
}

/*
 * 
 * 
 * 
 */
int main(int argc, char** argv) {
    /* Configure Hardware */
    vMainHardwareSetup();

    //uint16_t pwm = 0;
    

    for ( ;; )
    {
		if ( !tickCount )	/* every 100ms */
        {
            
            if(  Deg < 0)
            {
                setLED( 1, QEI1CONbits.UPDN );
            }
            else
            {
                setLED( 0, QEI1CONbits.UPDN );
            }
            tickCount=1000;				/* Re-Load */            
            
            
            
            //if ( pwm > 1837 ){ pwm = 0; };
        }
        tickCount --;
    }
    return (EXIT_SUCCESS);
}

