/* 
 * File:   PWM.h
 * Author: jacasasb
 *
 * Created on August 6, 2021, 4:55 PM
 */

#ifndef PWM_H
#define	PWM_H

#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif

#define PWM_MAX ( 1837UL)


void vPWMSetup1( void );

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

