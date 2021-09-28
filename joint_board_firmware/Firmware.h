/* 
 * File:   Firmware.h
 * Author: jacasasb
 *
 * Created on August 26, 2021, 3:51 PM
 */

#ifndef FIRMWARE_H
#define	FIRMWARE_H

#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif





void vFirmwareMainRoutine( void );

void vFirmwareHardwareSetup( void );
void vFirmwareUpdateMainState( void );
void vFirmwareInitialRoutine( void );
void vFirmwareFollowRoutine( void );
void vFirmwareLeadRoutine( void );
void vFirmwareDefaultRoutine( void );

void vFirmwareIdleRoutine( void );


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* FIRMWARE_H */

