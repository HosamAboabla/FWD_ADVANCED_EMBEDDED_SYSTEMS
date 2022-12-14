/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Gpt.h"



/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



/******************************************************************************
* \Syntax          : void Gpt_TimerInit(void)                                   
* \Description     : Initialize timer                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/




void (*__timer_callback)(void);

void Gpt_TimerInit(void)
{
	       /* Timer1A timeout flag bit clears*/
	SYSCTL->RCGCTIMER |= 63;// (1<<1);  /*enable clock Timer1 subtimer A in run mode */
	
	int count = 0;
	while(count < 10000 ) count++;
	
	TIMER1->CTL = 0; /* disable timer1 output */
	TIMER1->CFG =  0x4; /*select 32-bit configuration option */
	TIMER1->TAMR |= (1U << 4); // TIMER1->TAMR &= ~(1U << 4); // count down
	TIMER1->TAMR |= 0x2; /*select periodic down counter mode of timer1 */
	TIMER1->TAILR =  0 ;/* TimerA counter starting count down value  */
	
	TIMER1->TAPR = 250-1; /* TimerA prescaler value */
	
	TIMER1->IMR = 0; /* disables TimerA time-out  interrupt mask */
	
	
	
	
	

	
	// NVIC->ISER[0] |= (1 << 21); /*enable IRQ21 */
}




void Gpt_TimerDelayMs( uint32 msValue ) {
		uint32 i;
		TIMER1->TAPR = 0;  // No prescaler
		// load timer with counts for 1 ms overflow 
		TIMER1->TAILR  = 16000 -1;
			// clear timer timeout flag 
		TIMER1->ICR = 0x01; 
		// enable timer for counting 
		TIMER1->CTL = 0x01;
	
		for ( i =0; i < msValue; i++){

			while ( (( TIMER1->RIS ) & 0x1) == 0x00 ) ; /* wait for TimerA timeout flag */
		
			 TIMER1->ICR = 0x01; 
		} 
	
}




void Gpt_StartTimer( uint32 ticks , void (*f)(void) )
{

		TIMER1->TAILR = ticks;// 64000-1 ;
		TIMER1->ICR = 0x1;          /* TimerA timeout flag bit clears*/
		TIMER1->CTL = 0x01;        /* Enable TimerA module */
		GetReg(NVIC,EN0) |= (1 << 21);
		TIMER1->IMR = 0x01; /* enable TimerA time-out  interrupt mask */
	
	__timer_callback = f;

}


void TIMER1A_Handler()
{ 
	__timer_callback();

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
