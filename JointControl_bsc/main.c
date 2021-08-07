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
    TRISBbits.TRISB5 = 0;
    LATBbits.LATB4 = value;
    LATBbits.LATB5 = v;
}

void PLLConfig(void){
    PLLFBD  = 28;                // M  = 30
    CLKDIVbits.PLLPRE  =   0;    // N1 = 2
    CLKDIVbits.PLLPOST =   0;    // N2 = 2
    ACLKCONbits.APSTSCLR = 7;    //divide auxiliary clock by 1
    while(OSCCONbits.LOCK !=1);  //wait for PLL to lock
}



void vADCSetup(void){
    /* ADC */
    AD1CON1bits.FORM = 0;   /* Data Output Form: Unsigned Int */
    AD1CON1bits.SSRC = 7;   /* auto-convert */
    AD1CON1bits.ASAM = 0;   /* sampling begins when SAMP bit is set */
    AD1CON1bits.AD12B = 0;  /* 10-bit operation */
    AD1CON2bits.SMPI = 0;   /* every sample/conversion operation */
    AD1CON2bits.CHPS = 0;   /* Converts CH0 */
    AD1CON3bits.ADRC = 0;   /* ADC Clock is derived from System */
    AD1CON3bits.SAMC = 31;  /* Auto Sample Time 31*Tad */
    AD1CON3bits.ADCS = 0;   /* Tad = Tcy*(ADCS+1) */
    AD1CHS0bits.CH0SA = 0;  /* AN0 for CH0 */
    AD1CHS0bits.CH0NA = 0;  /* Vref- for CH0 */
    AD1PCFGLbits.PCFG0 = 0; /* AN0 as Analog Input */
    AD1CON1bits.ADON = 1;   /* Turn on ADC */
}

void vUARTSetup(void){
    /* Configure according to pins */
	//RPINR = ?;
    //RPOR9 = ?;
    /* UART (8-N-1) */
    U1MODE = 0;
    U1BRG = 11;         /* 19200 @7370000 Hz */
    U1MODE = 0x8000;    /* Low-Speed */
    U1STA = 0x0400;
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

void writePWM1(uint16_t value){
    P1DC1 = value;
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt( void )
{
    /* Clear interruption flags */
    IFS0bits.T1IF = 0;
    ToggleLed();
    vEncoderJointPositionCalculation();
    return;
}


void __attribute__((__interrupt__,auto_psv)) _QEI1Interrupt(void)
{
  extern volatile int16_t RevolutionCount ;
   // if it overflowed
     if (QEI1CONbits.UPDN ==  1){
       RevolutionCount++;
     } else {
       RevolutionCount--;
     }
     IFS3bits.QEI1IF = 0;    // clear the interrupt flag
}


void vMainHardwareSetup( void )
{
    /* PWM Setup */
    vPWMSetup1();
    /* Encoder interfaces */
    vEncoderJointSetup();
    vEncoderPulleySetup();
    /* Setup control loop timer */
    vTimerTMR1Setup();
    /* ADC setup */
    //vADCSetup();     
}

/*
 * 
 * 
 * 
 */
int main(int argc, char** argv) {
    /* Configure Hardware */
    vMainHardwareSetup();

    uint16_t pwm = 0;
    uint16_t EncoderPos = 0;

    while ( 1 )
    {
        
        
		if ( !tickCount )	/* every 100ms */
        {
            EncoderPos = POS1CNT;
            if( EncoderPos > 10000)
            {
                setLED( 1, QEI1CONbits.UPDN );
            }
            else
            {
                setLED( 0, QEI1CONbits.UPDN );
            }
            tickCount=1000;				/* Re-Load */            
            
            
            //xScale = (uint32_t)(EncoderPos*PWM_MAX);
            //Divider = (uint16_t)(xScale/10000);
            pwm = (uint16_t)(((uint32_t)(EncoderPos*PWM_MAX))/PULSES_PER_REV);
            writePWM1( pwm );
            //if ( pwm > 1837 ){ pwm = 0; };
        }
        tickCount --;
    }
    return (EXIT_SUCCESS);
}

