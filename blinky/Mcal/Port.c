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

#include "Port.h"
#include "Dio.h"


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
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)                                      
* \Description     : write value of Dio channel(pin)                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId , channelid       ,  Level               
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Port_Init(const Port_ConfigType* ConfigPtr, uint8 length)
{
	
	while(length--)
	{
		// Enable port clock
		SYSCTL->RCGCGPIO |= (1U << ConfigPtr-> PortId);
		
		// configure mode
		switch(ConfigPtr->Mode)
		{
			case Port_PinDio:
				switch( ConfigPtr->PortId )
				{
					case Dio_PortA:
						GPIOA->AFSEL &= ~( 1 << ConfigPtr->ChannelId );
						GPIOA->DEN |= ( 1 << ConfigPtr->ChannelId );
						switch( ConfigPtr->Direction )
						{
							case Port_PinOutput:
								GPIOA->DIR |= ( 1 << ConfigPtr->ChannelId );
								Dio_WriteChannel( ConfigPtr->PortId , ConfigPtr->ChannelId , ConfigPtr->Level);
								switch(ConfigPtr->Current)
								{
									case Port_PinCurrent2:
										GPIOA->DR2R |= (1 << ConfigPtr->ChannelId );
										break;
									case Port_PinCurrent4:
										GPIOA->DR4R |= (1 << ConfigPtr->ChannelId );
										break;
									case Port_PinCurrent8:
										GPIOA->DR8R |= (1 << ConfigPtr->ChannelId );
										break;
								}
								break;
							case Port_PinInput:
								GPIOA->DIR &= ~( 1 << ConfigPtr->ChannelId );
								switch(ConfigPtr->Attach)
								{
									case Port_PinAttachPUP:
										GPIOA->PUR |= ( 1 << ConfigPtr->ChannelId );
										break;
									case Port_PinAttachPDW:
										GPIOA->PDR |= ( 1 << ConfigPtr->ChannelId );
										break;
								}
								break;
						}
						break;
						
								
						
						
						
						case Dio_PortB:
							GPIOB->AFSEL &= ~( 1 << ConfigPtr->ChannelId );
							GPIOB->DEN |= ( 1 << ConfigPtr->ChannelId );
							switch( ConfigPtr->Direction )
							{
								case Port_PinOutput:
									GPIOB->DIR |= ( 1 << ConfigPtr->ChannelId );
									Dio_WriteChannel( ConfigPtr->PortId , ConfigPtr->ChannelId , ConfigPtr->Level);
									switch(ConfigPtr->Current)
									{
										case Port_PinCurrent2:
											GPIOB->DR2R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent4:
											GPIOB->DR4R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent8:
											GPIOB->DR8R |= (1 << ConfigPtr->ChannelId );
											break;
									}
									break;
								case Port_PinInput:
									GPIOB->DIR &= ~( 1 << ConfigPtr->ChannelId );
									switch(ConfigPtr->Attach)
									{
										case Port_PinAttachPUP:
											GPIOB->PUR |= ( 1 << ConfigPtr->ChannelId );
											break;
										case Port_PinAttachPDW:
											GPIOB->PDR |= ( 1 << ConfigPtr->ChannelId );
											break;
									}
									break;
							}
							break;
							
							
							
						case Dio_PortC:
							GPIOC->AFSEL &= ~( 1 << ConfigPtr->ChannelId );
							GPIOC->DEN |= ( 1 << ConfigPtr->ChannelId );
							switch( ConfigPtr->Direction )
							{
								case Port_PinOutput:
									GPIOC->DIR |= ( 1 << ConfigPtr->ChannelId );
									Dio_WriteChannel( ConfigPtr->PortId , ConfigPtr->ChannelId , ConfigPtr->Level);
									switch(ConfigPtr->Current)
									{
										case Port_PinCurrent2:
											GPIOC->DR2R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent4:
											GPIOC->DR4R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent8:
											GPIOC->DR8R |= (1 << ConfigPtr->ChannelId );
											break;
									}
									break;
								case Port_PinInput:
									GPIOC->DIR &= ~( 1 << ConfigPtr->ChannelId );
									switch(ConfigPtr->Attach)
									{
										case Port_PinAttachPUP:
											GPIOC->PUR |= ( 1 << ConfigPtr->ChannelId );
											break;
										case Port_PinAttachPDW:
											GPIOC->PDR |= ( 1 << ConfigPtr->ChannelId );
											break;
									}
									break;
							}
							break;
							
							
						case Dio_PortD:
							GPIOD->AFSEL &= ~( 1 << ConfigPtr->ChannelId );
							GPIOD->DEN |= ( 1 << ConfigPtr->ChannelId );
							switch( ConfigPtr->Direction )
							{
								case Port_PinOutput:
									GPIOD->DIR |= ( 1 << ConfigPtr->ChannelId );
									Dio_WriteChannel( ConfigPtr->PortId , ConfigPtr->ChannelId , ConfigPtr->Level);
									switch(ConfigPtr->Current)
									{
										case Port_PinCurrent2:
											GPIOD->DR2R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent4:
											GPIOD->DR4R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent8:
											GPIOD->DR8R |= (1 << ConfigPtr->ChannelId );
											break;
									}
									break;
								case Port_PinInput:
									GPIOD->DIR &= ~( 1 << ConfigPtr->ChannelId );
									switch(ConfigPtr->Attach)
									{
										case Port_PinAttachPUP:
											GPIOD->PUR |= ( 1 << ConfigPtr->ChannelId );
											break;
										case Port_PinAttachPDW:
											GPIOD->PDR |= ( 1 << ConfigPtr->ChannelId );
											break;
									}
									break;
							}
							break;
							
							
						case Dio_PortE:
							GPIOE->AFSEL &= ~( 1 << ConfigPtr->ChannelId );
							GPIOE->DEN |= ( 1 << ConfigPtr->ChannelId );
							switch( ConfigPtr->Direction )
							{
								case Port_PinOutput:
									GPIOE->DIR |= ( 1 << ConfigPtr->ChannelId );
									Dio_WriteChannel( ConfigPtr->PortId , ConfigPtr->ChannelId , ConfigPtr->Level);
									switch(ConfigPtr->Current)
									{
										case Port_PinCurrent2:
											GPIOE->DR2R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent4:
											GPIOE->DR4R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent8:
											GPIOE->DR8R |= (1 << ConfigPtr->ChannelId );
											break;
									}
									break;
								case Port_PinInput:
									GPIOE->DIR &= ~( 1 << ConfigPtr->ChannelId );
									switch(ConfigPtr->Attach)
									{
										case Port_PinAttachPUP:
											GPIOE->PUR |= ( 1 << ConfigPtr->ChannelId );
											break;
										case Port_PinAttachPDW:
											GPIOE->PDR |= ( 1 << ConfigPtr->ChannelId );
											break;
									}
									break;
							}
							break;
						
							
							
						case Dio_PortF:
							GPIOF->AFSEL &= ~( 1 << ConfigPtr->ChannelId );
							GPIOF->DEN |= ( 1 << ConfigPtr->ChannelId );
							switch( ConfigPtr->Direction )
							{
								case Port_PinOutput:
									GPIOF->DIR |= ( 1 << ConfigPtr->ChannelId );
									Dio_WriteChannel( ConfigPtr->PortId , ConfigPtr->ChannelId , ConfigPtr->Level);
									switch(ConfigPtr->Current)
									{
										case Port_PinCurrent2:
											GPIOF->DR2R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent4:
											GPIOF->DR4R |= (1 << ConfigPtr->ChannelId );
											break;
										case Port_PinCurrent8:
											GPIOF->DR8R |= (1 << ConfigPtr->ChannelId );
											break;
									}
									break;
								case Port_PinInput:
									GPIOF->DIR &= ~( 1 << ConfigPtr->ChannelId );
									switch(ConfigPtr->Attach)
									{
										case Port_PinAttachPUP:
											GPIOF->PUR |= ( 1 << ConfigPtr->ChannelId );
											break;
										case Port_PinAttachPDW:
											GPIOF->PDR |= ( 1 << ConfigPtr->ChannelId );
											break;
									}
									break;
							}
							break;
						
				}
				break;
			case Port_PinAlterFunction:
				break;
		}
		// configure direction and level if output
		// configure attach if input
		// configure current if output
		
		ConfigPtr++;
	}
	
}



/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
