/* 
 * File:   UART.h
 * Author: jacasasb
 *
 * Created on August 11, 2021, 11:52 AM
 */

#ifndef UART_H
#define	UART_H

#include "main.h"
#ifdef	__cplusplus
extern "C" {
#endif
    
#define uartBAUDRATE_1    115200
#define uartSPEED_MODE    16         //x4(high speed) or x16(low speed)
#define uartBRG_1         1           //((mainFCY/uartBAUDRATE_1)/uartSPEED_MODE)-1
/*to migrate to HARDWARE.H*/    
#define uartRX_PORT       2 //RP2 pin 6
#define uartTX_PORT       RPOR1bits.RP3R // pin 7
#define uartRX_TRIS       TRISBbits.TRISB2
#define uartTX_TRIS       TRISBbits.TRISB3
#define adcPCFG4          AD1PCFGLbits.PCFG4
#define adcPCFG5          AD1PCFGLbits.PCFG5    
/*........................................*/
/* Communication protocol definitions */
#define uartREQUEST_DATA      'R'
#define uartSEND_DATA         'S'
    




void vUARTIntraCommunicationSetup( void );
void prvUARTSetup1( void );
void vUARTReadIntraData( void );
void vUARTWriteIntraData(uint16_t data );
void vUARTCheckDataRequest( uint16_t dataToSend );
void vUARTRequestIntraData( void );
void vUARTFlushBufferRX( void );
#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

