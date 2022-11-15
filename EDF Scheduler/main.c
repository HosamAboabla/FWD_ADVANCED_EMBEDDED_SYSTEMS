/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"

#include "buffer.h"

/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )


/*-----------------------------------------------------------*/
#define BUTTON_1_RISING_MESSAGE	"Button_1_Rising_Edge\n"
#define BUTTON_1_RISING_MESSAGE_length 21UL
#define BUTTON_1_FALLING_MESSAGE	"Button_1_Falling_Edge\n"
#define BUTTON_1_FALLING_MESSAGE_length 22UL
#define BUTTON_2_RISING_MESSAGE	"Button_2_Rising_Edge\n"
#define BUTTON_2_RISING_MESSAGE_length 21UL
#define BUTTON_2_FALLING_MESSAGE	"Button_2_Falling_Edge\n"
#define BUTTON_2_FALLING_MESSAGE_length 22UL
#define PERIODIC_TRANSMITTER_MESSAGE	"Periodic_Transmitter\n"
#define PERIODIC_TRANSMITTER_MESSAGE_length 21UL


Buffer_t uart_buffer = { 0 , 49 , { NULL } };



TaskHandle_t Task_1_Handler = NULL;
TaskHandle_t Task_2_Handler = NULL;
TaskHandle_t Button_1_Monitor_Handler = NULL;
TaskHandle_t Button_2_Monitor_Handler = NULL;
TaskHandle_t Periodic_Transmitter_Handler = NULL;
TaskHandle_t Uart_Receiver_Handler = NULL;
TaskHandle_t Load_1_Simulation_Handler = NULL;
TaskHandle_t Load_2_Simulation_Handler = NULL;

volatile int miss = 0;
pinState_t buttonState;

/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/


/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */








void Button_1_Monitor( void * pvParameters )
{
	int xLastWakeTime = xTaskGetTickCount(); 
	pinState_t previousStateB1 = PIN_IS_LOW;
	pinState_t currentStateB1  = PIN_IS_LOW;

	for( ;; )
	{
			/* Task code goes here. */
		Packet_t packet;
		currentStateB1 = GPIO_read(PORT_0 , PIN14);
		if( previousStateB1 != currentStateB1 )
		{
			if( currentStateB1 == PIN_IS_LOW)
			{
				packet.message = BUTTON_1_FALLING_MESSAGE;
				packet.message_length = BUTTON_1_FALLING_MESSAGE_length;
				buffer_store(&uart_buffer , &packet);
			}
			else
			{
				packet.message = BUTTON_1_RISING_MESSAGE;
				packet.message_length = BUTTON_1_RISING_MESSAGE_length;
				buffer_store(&uart_buffer , &packet);
			}
		}
		

		vTaskDelayUntil( &xLastWakeTime , 50);
		previousStateB1 = currentStateB1;

	}
}


void Button_2_Monitor( void * pvParameters )
{
	int xLastWakeTime = xTaskGetTickCount(); 
	pinState_t previousStateB2 = PIN_IS_LOW;
	pinState_t currentStateB2  = PIN_IS_LOW;

	for( ;; )
	{
			/* Task code goes here. */
		Packet_t packet;
		currentStateB2 = GPIO_read(PORT_0 , PIN15);
		if( previousStateB2 != currentStateB2 )
		{
			if( currentStateB2 == PIN_IS_LOW)
			{
				packet.message = BUTTON_2_FALLING_MESSAGE;
				packet.message_length = BUTTON_2_FALLING_MESSAGE_length;
				buffer_store(&uart_buffer , &packet);
			}
			else
			{
				packet.message = BUTTON_2_RISING_MESSAGE;
				packet.message_length = BUTTON_2_RISING_MESSAGE_length;
				buffer_store(&uart_buffer , &packet);
			}
		}
		

		vTaskDelayUntil( &xLastWakeTime , 50);
		previousStateB2 = currentStateB2;

	}
}


void Periodic_Transmitter( void * pvParameters )
{
	int i = 0;
	int xLastWakeTime = xTaskGetTickCount(); 
	Packet_t packet;
	packet.message =PERIODIC_TRANSMITTER_MESSAGE;
	packet.message_length =PERIODIC_TRANSMITTER_MESSAGE_length;
	for( ;; )
	{
		buffer_store(&uart_buffer , &packet);
		vTaskDelayUntil( &xLastWakeTime , 100);
	}
}




void Uart_Receiver( void * pvParameters )
{
	int i = 0;
	int xLastWakeTime = xTaskGetTickCount(); 
	Packet_t packet;
	for( ;; )
	{
		
		if ( buffer_restore(&uart_buffer , &packet) == BUFFER_SUCCESS)
		{
			vSerialPutString( packet.message,packet.message_length );
		}

		
		vTaskDelayUntil( &xLastWakeTime , 20);
	}
}

void Load_1_Simulation( void * pvParameters )
{
	int i = 0;
	int xLastWakeTime = xTaskGetTickCount(); 

	for( ;; )
	{
			/* Task code goes here. */
		
		for( i = 0 ; i < 33333 ; i++)
		{
			i = i;
		}

		
		GPIO_write(PORT_0 , PIN0 , PIN_IS_LOW);
		vTaskDelayUntil( &xLastWakeTime , 10);
		GPIO_write(PORT_0 , PIN0 , PIN_IS_HIGH);
	}
}



void Load_2_Simulation( void * pvParameters )
{
	int i = 0;
	int xLastWakeTime = xTaskGetTickCount(); 

	for( ;; )
	{
			/* Task code goes here. */
		
		for( i = 0 ; i < 50000 ; i++)
		{
			i = i;
		}

		
		GPIO_write(PORT_0 , PIN1 , PIN_IS_LOW);
		vTaskDelayUntil( &xLastWakeTime , 100);
		GPIO_write(PORT_0 , PIN1 , PIN_IS_HIGH);
	}
}





int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();

	
    /* Create Tasks here */

		xTaskPeriodicCreate(
								Button_1_Monitor,       /* Function that implements the task. */
								"Button 1",          /* Text name for the task. */
								100,      /* Stack size in words, not bytes. */
								( void * ) 0,    /* Parameter passed into the task. */
								1,/* Priority at which the task is created. */
								&Button_1_Monitor_Handler,
								50);
								
		xTaskPeriodicCreate(
								Button_2_Monitor,       /* Function that implements the task. */
								"Button 2",          /* Text name for the task. */
								100,      /* Stack size in words, not bytes. */
								( void * ) 0,    /* Parameter passed into the task. */
								1,/* Priority at which the task is created. */
								&Button_1_Monitor_Handler,
								50);
								
		xTaskPeriodicCreate(
								Periodic_Transmitter,       /* Function that implements the task. */
								"Periodic Transmitter",          /* Text name for the task. */
								100,      /* Stack size in words, not bytes. */
								( void * ) 0,    /* Parameter passed into the task. */
								1,/* Priority at which the task is created. */
								&Periodic_Transmitter_Handler,
								100);
								
		xTaskPeriodicCreate(
								Uart_Receiver,       /* Function that implements the task. */
								"Uart Receiver",          /* Text name for the task. */
								100,      /* Stack size in words, not bytes. */
								( void * ) 0,    /* Parameter passed into the task. */
								1,/* Priority at which the task is created. */
								&Uart_Receiver_Handler,
								20);
								
		xTaskPeriodicCreate(
								Load_1_Simulation,       /* Function that implements the task. */
								"Load 1 Simulation",          /* Text name for the task. */
								100,      /* Stack size in words, not bytes. */
								( void * ) 0,    /* Parameter passed into the task. */
								1,/* Priority at which the task is created. */
								&Load_1_Simulation_Handler,
								10);
								
		xTaskPeriodicCreate(
								Load_2_Simulation,       /* Function that implements the task. */
								"Load 2 Simulation",          /* Text name for the task. */
								100,      /* Stack size in words, not bytes. */
								( void * ) 0,    /* Parameter passed into the task. */
								1,/* Priority at which the task is created. */
								&Uart_Receiver_Handler,
								100);
	

	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


