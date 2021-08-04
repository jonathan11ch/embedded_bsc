#include <stdlib.h>
#include <string.h>
#include "Encoder.h"

#define DEG_RATIO      1
#define TICK_RATIO     1
uint16_t JointEncoderPOSCNT = 0; 
uint16_t JointAngularPosition[2] = {0,0};


void vEncoderJointSetup( void )
{
    prvEncoderQEI1Setup();
}

void vEncoderJointPositionCalculation( void )
{
    /* Read encoder counter */
    JointEncoderPOSCNT = POS1CNT;
    //if( JointEncoderPOSCNT < 0 ){ JointEncoderPOSCNT *= -1; };
    JointAngularPosition[0] = JointEncoderPOSCNT;
    //JointAngularPosition[0] = (uint16_t)((uint32_t)(JointEncoderPOSCNT*DEG_RATIO)/TICK_RATIO);
    //JointAngularPosition[0] *= ( 9/1000 );
}

void vEncoderPulleySetup( void )
{
    prvEncoderQEI2Setup();
}

void vEncoderPulleyPositionCalculation( void )
{
    return;
}

/*  */
void prvEncoderQEI1Setup( void ){
    /* Disable Analog */
    //AD1PCFGL = 0x003f;
    /* input port setup */
    A_CH1_TRIS = 1;
    B_CH1_TRIS = 1;
    I_CH1_TRIS = 1;
    /* Interface configuration */
    QEICONbits.QEIM = 0; // Disable QEI Module
   
    QEICONbits.CNTERR = 0; // Clear any count errors
    QEICONbits.QEISIDL = 0; // Continue operation during sleep
    QEICONbits.SWPAB = 0; // QEA and QEB not swapped
    QEICONbits.PCDOUT = 0; // Normal I/O pin operation
    QEICONbits.POSRES = 1; // Index pulse resets position counter
    QEICONbits.TQCKPS = 0b00; //1:1 prescale timer value
    /* Digital filter configuration*/
    DFLT1CONbits.CEID = 1; // Count error interrupts disabled
    DFLT1CONbits.QEOUT = 1; // Digital filters output enabled for QEn pins
    DFLT1CONbits.QECK = 0b000; // 1:1 clock divide for digital filter for QEn
    /* Set counting registers */
    POS1CNT = CNT1_RESET_VAL; // Reset position counter
    MAX1CNT = CNT1_MAX_VAL; // Set max count register
     /* select RPINR14 to map encoder channels */
    RPINR14bits.QEA1R = CHA_1; // RP9 ( pin18 )
    RPINR14bits.QEB1R = CHB_1; // RP8 ( pin17 )
    /* select RPINR15 to map the index channel */
    RPINR15bits.INDX1R = IDX_1; //  RP7 ( pin16 )
    QEICONbits.QEIM = 0b101; // X4 mode with position counter reset by MAX1CNT
}

void prvEncoderQEI2Setup( void ){
    /* select RPINR16 to map encoder channels */
    RPINR16bits.QEA2R = 11; // RP11 ( pin22 )
    RPINR16bits.QEB2R = 10; // RP10 ( pin21 )
    /* select RPINR17 to map the index channel */
    RPINR17bits.INDX2R = 5; //  RP5 ( pin14 )
}