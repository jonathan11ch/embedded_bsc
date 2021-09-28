/* 
 * File:   Status.h
 * Author: jacasasb
 *
 * Created on September 28, 2021, 10:30 AM
 */

#ifndef STATUS_H
#define	STATUS_H
#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif
#ifdef	__cplusplus
extern "C" {
#endif

/*to migrate to HARDWARE.H*/
#define statusENABLE_PORT   PORTBbits.RB4
#define statusENABLE_LAT    LATBbits.LATB4
#define statusENABLE_TRIS   TRISBbits.TRISB4 
    
#define statusSTATE_PORT    PORTAbits.RA4
#define statusSTATE_LAT     LATAbits.LATA4
#define statusSTATE_TRIS    TRISAbits.TRISA4 
    
#define statusLED_PORT      PORTBbits.RB6
#define statusLED_LAT       LATBbits.LATB6
#define statusLED_TRIS      TRISBbits.TRISB6 
/*...........................................*/
    
    
    
void vStatusLedToggle( void );
uint16_t u16_StatusCheck( void );
void vStatusHardwareSetup( void );

#ifdef	__cplusplus
}
#endif

#endif	/* STATUS_H */

