/* 
 * File:   Encoder.h
 * Author: jacasasb
 *
 * Created on August 4, 2021, 12:18 PM
 */

#ifndef ENCODER_H
#define	ENCODER_H

#include <stdlib.h>
#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif
#ifdef	__cplusplus
extern "C" {
#endif

#define PULSES_PER_REV      ( 10000U )  //PPR US digital H1 encoder
#define COUNT_INC_PER_REV   2       //x2 mode (make sure to modify QEIM) 
#define RESOLUTION_16_BIT   65536   //
#define MAX_COUNT_PER_REV   (PULSES_PER_REV*COUNT_INC_PER_REV-1)
    
    
#define CHA_1  9
#define CHB_1  8
#define IDX_1  7
    

#define A_CH1_TRIS          TRISBbits.TRISB9
#define B_CH1_TRIS          TRISBbits.TRISB8
#define I_CH1_TRIS          TRISBbits.TRISB7
    
#define A_CH2_TRIS          TRISBbits.TRISB11
#define B_CH2_TRIS          TRISBbits.TRISB10
#define I_CH2_TRIS          TRISBbits.TRISB5        

    

#define CNT1_RESET_VAL  0x0000
#define CNT1_MAX_VAL    0x2710

    
/* Global Variables definitions */
extern uint16_t JointAngularPosition[2]; // position and velocity 
//int16_t PulleyAngularPosition[2] = {0,0}; // position and velocity 
extern int32_t JointTickCount[2];
extern int16_t Deg;
extern volatile int16_t RevolutionCount;
    
void vEncoderJointSetup( void );
void vEncoderJointPositionCalculation( void );
void vEncoderPulleySetup( void );

/* Private functions */
void prvEncoderQEI1Setup( void );
void prvEncoderQEI2Setup( void );
#ifdef	__cplusplus
}
#endif

#endif	/* ENCODER_H */