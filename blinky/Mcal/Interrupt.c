/*
 * Interrupt.c
 *
 * Created: 10/18/2022 1:16:52 PM
 *  Author: Abdallah
 */ 

/************************************************************************/
/* INCLUDES                                                                     */
/************************************************************************/
#include "Interrupt.h"


/************************************************************************/
/* NVIC APIs                                                                      */
/************************************************************************/
ERROR NVIC_EnableInterrupt(uint8_t InterruptNumber)
{
	switch(InterruptNumber)
	{
		case TIMER1A_16_32_INTERRUPT_NUMBER:
			/* NVIC - EN0 is responsible for interrupt  from 0 to 31 */
			NVIC->ISER[0] |= ( 1 << TIMER1A_16_32_INTERRUPT_NUMBER);
			
			break;
		default:
			return E_NOT_OK;
	}
	return E_NOT_OK;
}


ERROR NVIC_DisableInterrupt(uint8_t InterruptNumber)
{
	switch(InterruptNumber)
	{
		case TIMER1A_16_32_INTERRUPT_NUMBER:
			NVIC->ISER[0] &= ~( 1U <<TIMER1A_16_32_INTERRUPT_NUMBER);
			break;
		default:
			return E_NOT_OK;
	}
	return E_NOT_OK;
}
