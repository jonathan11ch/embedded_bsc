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
#define uartBRG_1         ((mainFCY/uartBAUDRATE_1)/uartSPEED_MODE)-1
    
#define uartRX_PORT       2 //RP2 pin 6
#define uartTX_PORT       3 // pin 7
    
void vUARTIntraCommunicationSetup( void );
void prvUARTSetup1( void );
void vUARTReadIntraData( void );
void vUARTWriteIntraData( );



#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

