/*
 * Interrupt.h
 *
 * Created: 10/18/2022 1:17:01 PM
 *  Author: Abdallah
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/************************************************************************/
/* INCLUDES                                                                     */
/************************************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"
#include "TM4C123GH6PM.h"


/************************************************************************/
/* NVIC APIs                                                                     */
/************************************************************************/

#define TIMER1A_16_32_INTERRUPT_NUMBER 21

ERROR NVIC_EnableInterrupt(uint8 InterruptNumber);
ERROR NVIC_DisableInterrupt(uint8 InterruptNumber);



#endif /* INTERRUPT_H_ */



