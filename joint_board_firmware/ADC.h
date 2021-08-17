/* 
 * File:   ADC.h
 * Author: jacasasb
 *
 * Created on August 10, 2021, 11:15 AM
 */

#ifndef ADC_H
#define	ADC_H
#include <stdlib.h>
#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif
#ifdef	__cplusplus
extern "C" {
#endif
    
#define adcRESOLUTION_10BITS        (1023UL)
#define adcRESOLUTION_12BITS        (4095UL)

extern uint16_t Ch0InputVoltage;

void vADCReadInputVoltageCh0( void );
void vADCControlInputSetup( void );
void vADCTensionInputSetup( void );
void prvADCSetupChannel1( void );
void prvADCSetupChannel2( void );
#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

