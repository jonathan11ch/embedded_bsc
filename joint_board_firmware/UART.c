#include <stdlib.h>
#include <string.h>
#include <p33FJ128MC802.h>
#include "UART.h"


uint16_t IntraDataRX = 0;

void vUARTIntraCommunicationSetup( void )
{
    prvUARTSetup1();
}

void vUARTReadIntraData( void )
{
    if(U1STAbits.URXDA == 1)
    {
        /* Read data */
        IntraDataRX = U1RXREG;
    }
    
}

void vUARTWriteIntraData( )
{
    U1TXREG = 'H';
}



void prvUARTSetup1( void )
{
    /* Configure according to pins */
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB3 = 0;
	RPINR18bits.U1RXR = uartRX_PORT;
    RPOR1bits.RP3R = 0b00011; //TX peripheral function assigned to RP3

    /* U1MODE register config */
    U1MODEbits.UARTEN = 0;  // UART disabled
    U1MODEbits.USIDL = 0;   // continues operation in idle mode
    U1MODEbits.IREN = 0;    // IrDA encoder and decoder disabled
    U1MODEbits.RTSMD = 0;   // UxRTS is in flow control mode
    U1MODEbits.UEN = 0b00;  // UxTX UxRX pins are enabled and used ...
    U1MODEbits.WAKE = 0;    // Wake-up is disabled
    U1MODEbits.LPBACK = 0;  // LoopBack is disabled
    U1MODEbits.ABAUD = 0;   // Baud rate measurements is disabled or complete
    U1MODEbits.URXINV = 0;  // UART receive polarity inversion state is '1'
    U1MODEbits.BRGH = 1;    // High speed mode (4 x baud clock per bit period)
    U1MODEbits.PDSEL = 0b00;// 8-bit data, no parity
    U1MODEbits.STSEL = 0;   // 1 Stop bit
    U1MODEbits.UARTEN = 1;  // UART enabled
    /* U1STA register config */
    U1STAbits.UTXISEL1 = 0;    // Interrupt gen when at least 1 buff location is 
    U1STAbits.UTXISEL0 = 0;    // empty for transmission
    U1STAbits.UTXINV = 0;      // UxTX idle state is '1'
    U1STAbits.UTXBRK = 0;      // Sync break transmission is disabled or complete
    U1STAbits.UTXEN = 1;       // UART transmitter is enabled 
    U1STAbits.URXISEL = 0b00;  // Interupt flag bit is set when a character received
    U1STAbits.ADDEN = 0;       // Address Detect mode is disabled
    /* baud rate config */
    U1BRG = 8;                // 115200 @7370000 with high speed (x4)
}


