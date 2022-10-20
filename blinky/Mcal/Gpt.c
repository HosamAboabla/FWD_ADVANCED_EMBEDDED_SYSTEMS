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
* \Syntax          : Dio_LevelTyp0e Dio_FlipChannel(Dio_ChannelType ChannelId)                                   
* \Description     : flip value of Dio channel (pin)                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
void Gpt_Timer1Init(void)
{
	       /* Timer1A timeout flag bit clears*/
	SYSCTL->RCGCTIMER |= (1<<1);  /*enable clock Timer1 subtimer A in run mode */
	TIMER1->CTL = 0; /* disable timer1 output */
	TIMER1->CFG =  0x04; /*select 16-bit configuration option */
	TIMER1->TAMR &= ~(1U << 4); // count down
	TIMER1->TAMR |= 0x2; /*select periodic down counter mode of timer1 */
	TIMER1->TAILR = 0; // 64000-1 ; /* TimerA counter starting count down value  */
	TIMER1->TAPR = 250-1; /* TimerA prescaler value */
	TIMER1->IMR = 0; /* disables TimerA time-out  interrupt mask */
	
	
	GetReg(NVIC,EN0) |= (1 << 21);
	
	

	
	// NVIC->ISER[0] |= (1 << 21); /*enable IRQ21 */
}




void Gpt_Timer1DelayMs( uint32 msValue ) {
		uint32 i;
		TIMER1->TAPR = 0; 
		// load timer with counts for 1 ms overflow 
		TIMER1->TAILR  = 16000-1;
			// clear timer timeout flag 
		TIMER1->ICR = 0x01; 
		// enable timer for counting 
		TIMER1->CTL = 0x01;
	
		for ( i =0; i < msValue; i++){

			while ( (( TIMER1->RIS ) & 0x1) == 0x00 ) ; /* wait for TimerA timeout flag */
		
			 TIMER1->ICR = 0x01; 
		} 
	
}




void Gpt_StartTimer1(void)
{

		TIMER1->TAILR = ( 1000 / ((62.5* 250)/1000000) )- 1 ;// 64000-1 ;
		TIMER1->ICR = 0x1;          /* TimerA timeout flag bit clears*/
		TIMER1->CTL = 0x01;        /* Enable TimerA module */
		TIMER1->IMR = 0x01; /* enable TimerA time-out  interrupt mask */

}


/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
