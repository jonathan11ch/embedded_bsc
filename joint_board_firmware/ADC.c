#include <stdlib.h>
#include <string.h>
#include "ADC.h"


uint16_t Ch0InputVoltage = 0;

void vADCReadInputVoltageCh0( void )
{
    AD1CON1bits.SAMP = 1;
    while( !AD1CON1bits.DONE ); 
    Ch0InputVoltage = ADC1BUF0;
    AD1CON1bits.DONE = 0;
}


void vADCControlInputSetup( void )
{
    prvADCSetupChannel1();
}

void vADCTensionInputSetup( void )
{
    prvADCSetupChannel2();
}

/******************************************************************************/
/* Private ADC Functions */
/******************************************************************************/
void prvADCSetupChannel1( void )
{
    adcTRIS0 = 1;       // set input port
    /* AD1CON1 bit config */
    AD1CON1bits.ADON = 0;       //set ADC1 OFF
    AD1CON1bits.ADSIDL = 1;     //stop in idle mode
    AD1CON1bits.AD12B = 0;       //10 bit resolution
    AD1CON1bits.FORM = 0b00;    //Data output format unsigned int
    AD1CON1bits.SSRC = 0b111;     // Auto-convert source clock
    AD1CON1bits.ASAM = 0;       // sampling begins when SAMP bit is set
    AD1CON1bits.SAMP = 0;       // ADC sample enable bit
    /* AD1CON2 bit config */
    AD1CON2bits.VCFG = 0b000;   //use same MCU voltage as reference
    AD1CON2bits.CSCNA = 0;      // Do not scan inputs
    AD1CON2bits.CHPS = 0b00;    //Convert channel CH0
    AD1CON2bits.SMPI = 0b0000;  //ADC interrupt generated every sample operation
    /* ADC1CON3 bit config */
    AD1CON3bits.ADRC = 0;       //ADC clock source derived from system clock
    AD1CON3bits.SAMC = 0b11111;  //Auto sample time 31*Tad
    AD1CON3bits.ADCS = 0;       //ADC conversion clock Tad = Tcy*(ASCS+1)
    
    AD1CHS0bits.CH0NA = 0;      //Channel 0 negative input is Vrefl
    AD1CHS0bits.CH0SA = 0;      //Channel 0 positive input is AN0;
    
    adcPCFG0 = 0;     // port AN0 (pin 2) in Analog mode
    
    /* Turn on ADC */
    AD1CON1bits.ADON =1;
}

void prvADCSetupChannel2( void )
{

}

