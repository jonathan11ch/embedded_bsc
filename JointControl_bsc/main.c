/* 
 * File:   main.c
 * Author: jacasasb
 *
 * Created on July 28, 2021, 4:33 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Encoder.h"

#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif
/* Microcontroller MIPs (FCY) */
#define F_CPU   7370000L
#define FCY     F_CPU/2
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


uint16_t PLLisLock(void){
    /*1 indicates PLL is Lock, PLL start-up timer is satisfied*/
    /*0 indicates PLL is out of lock, startup is in progress or PLL inactive*/
    return OSCCONbits.LOCK;
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

void vPWM1Setup( void ){
    /*Main Configuration*/
    
    P1TCONbits.PTOPS  = 0;   // time base postscaler
    P1TCONbits.PTCKPS = 0;   // time base prescale
    P1TCONbits.PTMOD  = 2;   // Up-Down count mode (more resolution)
    P1TMRbits.PTMR    = 0;   // PWM1 timer count value (start at 0)
    P1TPERbits.PTPER  = 920; // PWM1 time base period
    /*Mode Setup*/
    PWM1CON1bits.PEN1H = 1; //enable PWM  H1 
    PWM1CON1bits.PEN1L = 0; //disable PWM L1
    /*pairs in independent mode*/
    PWM1CON1bits.PMOD1 = 1; 
    PWM1CON1bits.PMOD2 = 1;
    PWM1CON1bits.PMOD3 = 1;
    P1DC1 = 0;
    P1TCONbits.PTEN   = 1;   // PWM1 time base is on
    //setLED(1);
}

void vDebugQEIPorts( void )
{
    TRISBbits.TRISB7 = 0;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB9 = 0;
    
}


void writePWM1(uint16_t value){
    P1DC1 = value;
}
void timerSetup(void){
    /* TIMER1 */
    T1CON = 0;          /* Disable Timer */
    TMR1 = 0;           /* Clear Timer register */
    PR1 = 3684;         /* Load the period value */
    T1CON = 0x8000;     /* Internal instruction cycle clock */
}
/*
 * 
 * 
 * 
 */
int main(int argc, char** argv) {
    vPWM1Setup();
    vEncoderJointSetup();
    //vDebugQEIPorts();
    //launch ADC
    vADCSetup();        
    //TRISB = ~0xA0;
    uint16_t pwm = 0;
    //uint16_t QEIcount = POS1CNT; 
    
    while ( 1 )
    {
        
        
		if ( !tickCount )	/* every 100ms */
        {
            if( POS1CNT > 1837)
            {
                setLED( 1, QEI1CONbits.UPDN );
            }
            else
            {
                setLED( 0, QEI1CONbits.UPDN );
            }
            tickCount=1000;				/* Re-Load */            
            vEncoderJointPositionCalculation();
            pwm = (uint16_t)(((uint32_t)(JointAngularPosition[0]*919))/32765);
            writePWM1( POS1CNT );
            //if ( pwm > 1837 ){ pwm = 0; };
        }
        tickCount --;
    }
    return (EXIT_SUCCESS);
}

