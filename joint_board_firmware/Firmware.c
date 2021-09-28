
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Firmware.h"
#include "Encoder.h"
#include "PWM.h"
#include "Timer.h"
#include "Control.h"
#include "ADC.h"
#include "UART.h"
#include "Status.h"


#define firmwareLEAD_STATE         ( 1 )  
#define firmwareFOLLOW_STATE       ( 2 )

uint16_t mainState;

extern uint8_t IsDataRecevied; 
extern uint16_t IntraDataRX;


void vFirmwareMainRoutine( void )
{   
    vFirmwareUpdateMainState();
    switch( mainState )
    {
        case firmwareFOLLOW_STATE:
            vFirmwareFollowRoutine();
            break;
        case firmwareLEAD_STATE:
            vFirmwareLeadRoutine();
            break;
        default:
            vFirmwareDefaultRoutine();
            break;
    
    }
    IFS0bits.T1IF = 0;
}


void vFirmwareFollowRoutine( void )
{
    /* Clear interruption flags */
    vUARTRequestIntraData();
    /* Compute Encoder Positions */
    vEncoderPulleyPositionCalculation();
    vEncoderPulleyVelocityCalculation();
    vEncoderJointPositionCalculation();
    vEncoderJointVelocityCalculation();
    /* Compute Control */
    
    /* Read Intradata (2 BYTES)*/
    vUARTReadIntraData();
    /* Write PWM Command */
    vPWMWritePWM1( POS1CNT );
}



void vFirmwareLeadRoutine( void )
{
    /* Comm */
    vUARTCheckDataRequest(0x0201);
    vADCReadInputVoltageCh0();
}

void vFirmwareUpdateMainState( void )
{
    mainState = u16_StatusCheck();
}

void vFirmwareDefaultRoutine( void )
{

}

void vFirmwareInitialRoutine( void )
{
    
}

void vFirmwareIdleRoutine( void )
{

}

void vFirmwareHardwareSetup( void )
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
}