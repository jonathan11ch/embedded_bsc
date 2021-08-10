/* 
 * File:   PWM.h
 * Author: jacasasb
 *
 * Created on August 6, 2021, 4:55 PM
 */

#ifndef PWM_H
#define	PWM_H
#include "Encoder.h"
#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif

#define pwmMAX              ( 1837UL )
#define pwmDC_90            ( 1660UL )
#define pwmDC_10            ( 184UL )
#define pwmDC_RANGE         (pwmDC_90 - pwmDC_10)
#define pwmINPUT_RESOLUTION encoderPULSES_PER_REV
#define pwmMIN              ( 0 )
#define pwmPTPER            (920)

void vPWMWritePWM1(uint16_t value);

void vPWMSetup1( void );

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

