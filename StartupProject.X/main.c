/* 
 * File:   main.c
 * Author: jonathan
 *
 * Created on July 31, 2021, 4:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Priorities at which the tasks are created. */
#define mainQUEUE_RECEIVE_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )
#define	mainQUEUE_SEND_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )

/* The rate at which data is sent to the queue.  The 200ms value is converted
to ticks using the portTICK_PERIOD_MS constant. */
#define mainQUEUE_SEND_FREQUENCY_MS			( 200 / portTICK_PERIOD_MS )

/* The number of items the queue can hold.  This is 1 as the receive task
will remove items as they are added, meaning the send task should always find
the queue empty. */
#define mainQUEUE_LENGTH					( 1 )

/* Values passed to the two tasks just to check the task parameter
functionality. */
#define mainQUEUE_SEND_PARAMETER			( 0x1111UL )
#define mainQUEUE_RECEIVE_PARAMETER			( 0x22UL )

/* The period of the blinky software timer.  The period is specified in ms and
converted to ticks using the portTICK_PERIOD_MS constant. */
#define mainBLINKY_TIMER_PERIOD				( 50 / portTICK_PERIOD_MS )

/* The LED used by the communicating tasks and the blinky timer respectively. */
#define mainTASK_LED_PRIORITY				( tskIDLE_PRIORITY + 2 )
#define mainTIMER_LED						( 1 )

/* Misc. */
#define mainDONT_BLOCK						( 0 )

/*-----------------------------------------------------------*/


//#if defined(__dsPIC33F__)
//	#include <p33Fxxxx.h>
//#endif

/*
 * 
 */

/*-----------------------------------------------------------*/
/*Application Hooks (FreeRTOS callbacks)*/
/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time task stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook	function is 
	called if a task stack overflow is detected.  Note the system/interrupt
	stack is not checked. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()). */
}
/*-----------------------------------------------------------*/

void _general_exception_handler( unsigned long ulCause, unsigned long ulStatus )
{
	/* This overrides the definition provided by the kernel.  Other exceptions 
	should be handled here. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/
/*Application tasks*/
/*-----------------------------------------------------------*/

static void vLedTask( void  *pParameters )
{
    
    TRISBbits.TRISB4 = 1;
    int count = 0;
    for( ;; )
    {    
        count ++;
        PORTBbits.RB4 = ~PORTBbits.RB4;
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
    
    vTaskDelete( NULL );
}


int main( void ) 
{
    /* Setup the hardware */
    
    /* Create the tasks */
    xTaskCreate( vLedTask, "ledTask", configMINIMAL_STACK_SIZE, NULL, mainTASK_LED_PRIORITY, NULL );
    /* Launch the freeRTOS scheduler*/
    vTaskStartScheduler();
    /*Launch infinite loop*/
    for( ;; );
    /*return */
    return (EXIT_SUCCESS);
}

