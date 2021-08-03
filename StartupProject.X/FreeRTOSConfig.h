/* 
 * File:   FreeRTOSConfig.h
 * Author: jonathan
 *
 * Created on July 31, 2021, 4:58 PM
 */

#ifndef FREERTOSCONFIG_H
#define	FREERTOSCONFIG_H

//#include <p33FJ128MC802.h>

#if defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif
/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/
/* Microcontroller MIPs (FCY) */
#define F_CPU   7370000L
#define FCY     F_CPU/2

#define configUSE_PREEMPTION			1
#define configUSE_IDLE_HOOK				1
#define configUSE_TICK_HOOK				0
#define configTICK_RATE_HZ				( ( TickType_t ) 1000 )
#define configCPU_CLOCK_HZ				( ( unsigned long ) F_CPU)  /* Fosc / 2 */
#define configMAX_PRIORITIES			( 5UL )
#define configMINIMAL_STACK_SIZE		( 190 )
#define configISR_STACK_SIZE            ( 250 )
#define configTOTAL_HEAP_SIZE			( ( size_t ) 5120 )  /*5120*/
#define configMAX_TASK_NAME_LEN			( 4 )
#define configUSE_TRACE_FACILITY		0
#define configUSE_16_BIT_TICKS			1
#define configIDLE_SHOULD_YIELD			1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )
/* Software timer related configuration options. */
#define configUSE_TIMERS						0
#define configTIMER_TASK_PRIORITY				( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH				20
#define configTIMER_TASK_STACK_DEPTH			( configMINIMAL_STACK_SIZE * 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1
#define INCLUDE_xTaskGetCurrentTaskHandle       1   //modified by me


#define configCHECK_FOR_STACK_OVERFLOW  3


/* Prevent C specific syntax being included in assembly files. */
//#ifndef __LANGUAGE_ASSEMBLY
	//void vAssertCalled( const char *pcFileName, unsigned long ulLine );
//	#define configASSERT( x ) if( ( x ) == 0 ) vAssertCalled( __FILE__, __LINE__ )
//#endif

 
/* The priority at which the tick interrupt runs.  This should probably be
kept at 1. */
#define configKERNEL_INTERRUPT_PRIORITY	0x01
/* The maximum interrupt priority from which FreeRTOS.org API functions can
be called.  Only API functions that end in ...FromISR() can be used within
interrupts. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY	0x03

/*Modified by me: this settings require implemented callback functions*/
//#define configUSE_IDLE_HOOK             1
//#define configCHECK_FOR_STACK_OVERFLOW  2



#endif	/* FREERTOSCONFIG_H */

