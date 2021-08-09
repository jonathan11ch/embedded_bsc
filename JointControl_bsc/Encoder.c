#include <stdlib.h>
#include <string.h>
#include "Encoder.h"

#define RAD_RATIO       (6.28318L)
#define DEG_RATIO       (360L)
#define TICK_RATIO      (10000L)
#define TICK_PER_SECOND (1000L)  // Sampling frequency of 1kHz


/* Variable definition */

/* Joint encoder */
uint16_t JointEncoderPOSCNT = 0U; 
int32_t JointTickCount[2] = {0L,0L};
int32_t JointVelocity = 0L;
volatile int16_t JointRevolutionCount = 0;
/* Pulley encoder */
uint16_t PulleyEncoderPOSCNT = 0U; 
int32_t PulleyTickCount[2] = {0L,0L};
int32_t PulleyVelocity = 0L;
volatile int16_t PulleyRevolutionCount = 0;
/**/
int16_t Deg= 0;
int16_t DegPulley= 0;
int16_t Rad = 0;

/******************************************************************************/
/* Joint Encoder Functions */
/******************************************************************************/
void vEncoderJointSetup( void )
{
    prvEncoderQEI1Setup();
}

void vEncoderOnJointCounterReset( void )
{
   // if it overflowed
     if (QEI1CONbits.UPDN ==  1)
     {
       JointRevolutionCount++;
     }
     else 
     {
       JointRevolutionCount--;
     }
     IFS3bits.QEI1IF = 0;    // clear the interrupt flag
}

void vEncoderJointPositionCalculation( void )
{
    /* Read encoder counter */
    JointEncoderPOSCNT = POS1CNT;
    if( JointEncoderPOSCNT < 0 ){ JointEncoderPOSCNT *= -1; };
    JointTickCount[1] = JointTickCount[0];
    JointTickCount[0] = ( int32_t )(JointEncoderPOSCNT) + ( int32_t )(JointRevolutionCount*encoderPULSES_PER_REV);
    /* Degrees computed for debugging or display */
    Deg = ( int16_t )((JointTickCount[0]*DEG_RATIO)/TICK_RATIO);
    Rad = ( int16_t )((JointTickCount[0]*RAD_RATIO)/TICK_RATIO);
}

void vEncoderJointVelocityCalculation( void )
{
    JointVelocity = (JointTickCount[0] - JointTickCount[1])*TICK_PER_SECOND;    
}

/******************************************************************************/
/* Pulley Encoder Functions */
/******************************************************************************/
void vEncoderPulleySetup( void )
{
    prvEncoderQEI2Setup();
}

void vEncoderOnPulleyCounterReset( void )
{
    // if it overflowed
     if (QEI2CONbits.UPDN ==  1)
     {
       PulleyRevolutionCount++;
     }
     else
     {
       PulleyRevolutionCount--;
     }
     IFS4bits.QEI2IF = 0;    // clear the interrupt flag
}

void vEncoderPulleyPositionCalculation( void )
{
     /* Read encoder counter */
    PulleyEncoderPOSCNT = POS2CNT;
    if( PulleyEncoderPOSCNT < 0 ){ PulleyEncoderPOSCNT *= -1; };
    PulleyTickCount[1] = PulleyTickCount[0];
    PulleyTickCount[0] = ( int32_t )(PulleyEncoderPOSCNT) + ( int32_t )(PulleyRevolutionCount*encoderPULSES_PER_REV);
    /* Degrees computed for debugging or display */
    DegPulley = ( int16_t )((PulleyTickCount[0]*DEG_RATIO)/TICK_RATIO);
    //Rad = ( int16_t )((PulleyTickCount[0]*RAD_RATIO)/TICK_RATIO);
}

void vEncoderPulleyVelocityCalculation( void )
{
    PulleyVelocity = (PulleyTickCount[0] - PulleyTickCount[1])*TICK_PER_SECOND;   
}
/******************************************************************************/
/* Private Functions */
/******************************************************************************/
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
    
    //ConfigIntQEI 
    IFS3bits.QEI1IF = 0;    // clear the interrupt flag
    IEC3bits.QEI1IE = 1;                // Enable QEI interrupt
    IPC14bits.QEI1IP = 2;               // Interrupt priority level 2
}

void prvEncoderQEI2Setup( void ){
    /* input port setup */
    A_CH2_TRIS = 1;
    B_CH2_TRIS = 1;
    I_CH2_TRIS = 1;    
    /* Interface configuration */
    QEI2CONbits.QEIM = 0;                // Disable QEI Module
    QEI2CONbits.CNTERR = 0;              // Clear any count errors
    QEI2CONbits.QEISIDL = 0;             // Continue operation during sleep
    QEI2CONbits.SWPAB = 0;               // QEA and QEB not swapped
    QEI2CONbits.PCDOUT = 0;              // Normal I/O pin operation
    QEI2CONbits.POSRES = 1;              // Index pulse resets position counter
    QEI2CONbits.TQCKPS = 0b00;           // 1:1 prescale timer value
    /* Digital filter configuration*/
    DFLT2CONbits.CEID = 1;              // Count error interrupts disabled
    DFLT2CONbits.QEOUT = 1;             // Digital filters output enabled for QEn pins
    DFLT2CONbits.QECK = 0b000;          //1:1 clock divide for digital filter for QEn
    /* Set counting registers */
    POS2CNT = CNT2_RESET_VAL;           // Reset position counter
    MAX2CNT = CNT2_MAX_VAL;             // Set max count register
    /* select RPINR16 to map encoder channels */
    RPINR16bits.QEA2R = CHA_2;          // RP11 ( pin22 )
    RPINR16bits.QEB2R = CHB_2;          // RP10 ( pin21 )
    /* select RPINR17 to map the index channel */
    RPINR17bits.INDX2R = IDX_2;         //  RP5 ( pin14 )
    QEI2CONbits.QEIM = 0b101;            // X2 mode with position counter reset by MAX1CNT
    
    //ConfigIntQEI 
    IFS4bits.QEI2IF = 0;                // clear the interrupt flag
    IEC4bits.QEI2IE = 1;                // Enable QEI interrupt
    IPC18bits.QEI2IP = 2;               // Interrupt priority level 2
    
}