/* 
 * File:   Timer.h
 * Author: jacasasb
 *
 * Created on August 6, 2021, 5:01 PM
 */

#ifndef TIMER_H
#define	TIMER_H
#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif
#ifdef	__cplusplus
extern "C" {
#endif

void vTimerTMR1Setup(void);


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

