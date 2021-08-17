/* 
 * File:   main.h
 * Author: jacasasb
 *
 * Created on August 6, 2021, 5:11 PM
 */

#ifndef MAIN_H
#define	MAIN_H
#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

    
    
/* Microcontroller MIPs (FCY) */
#define mainF_CPU   ( 7370000L )
#define mainFCY     ( mainF_CPU/2 )
    



#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

