#include <stdlib.h>
#include <string.h>
#include <p33FJ128MC802.h>
#include "UART.h"

uint16_t IntraDataRX = 0;
uint8_t IsDataRecevied = 0; 


void vUARTRequestIntraData( void )
{
    /* flush the input buffer */
    vUARTFlushBufferRX();
    /* send request word */
    vUARTWriteIntraData(uartREQUEST_DATA);
}


void vUARTReadIntraData( void )
{
    IsDataRecevied = 0;
    if(U1STAbits.URXDA == 1)
    {
        /* Read data */
        IntraDataRX = U1RXREG;
        IsDataRecevied = 1;
    }    
}


void vUARTCheckDataRequest( uint16_t dataToSend )
{
    vUARTReadIntraData();
    if ( IsDataRecevied )
    {
        if(IntraDataRX == uartREQUEST_DATA)
        {
            /* send data */
            vUARTWriteIntraData(dataToSend);
            vUARTWriteIntraData(dataToSend>>8);
        }
        
    }
   
    
}

void vUARTFlushBufferRX( void )
{
    uint16_t dataToFlush;
    while( U1STAbits.URXDA == 1 )
    {
        dataToFlush = U1RXREG;
    }
}

void vUARTIntraCommunicationSetup( void )
{
    prvUARTSetup1();
}




void vUARTWriteIntraData(uint16_t data )
{
    /* check output buffer availability */
    while(U1STAbits.UTXBF == 1);
    U1TXREG = data;
    
    
}



void prvUARTSetup1( void )
{
    /* Analog ports disabled */
    adcPCFG4 = 1;  //digital mode
    adcPCFG5 = 1;  //digital mode
    /* Configure according to pins */
    uartRX_TRIS = 1;
    uartTX_TRIS = 1;
	RPINR18bits.U1RXR = uartRX_PORT;
    uartTX_PORT = 0b00011; //TX peripheral function assigned to RP3
    //RPOR6bits.RP12R = 0b00011; //TX peripheral function assigned to RP3

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
    U1MODEbits.BRGH = 0;    // Standard speed mode (16 x baud clock per bit period)
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
    
    //IFS0bits.U1RXIF=0; /* clear UART1 receiver interrupt flag */
    //IFS0bits.U1TXIF=0; /* clear UART1 transmitter interrupt flag */
    //IEC0bits.U1RXIE=1; /* enable UART1 receiver ISR */
    /* baud rate config */
    U1BRG = uartBRG_1;                // 115200 @7370000 with standard speed (x16)
}


