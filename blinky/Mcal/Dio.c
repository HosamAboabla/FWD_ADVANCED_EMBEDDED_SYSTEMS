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
* \Syntax          : void Dio_WriteChannel(Dio_PortType PortId , Dio_ChannelType ChannelId , Dio_LevelType Level)                                      
* \Description     : write value of Dio channel(pin)                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId , channelid       ,  Level               
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_PortType PortId , Dio_ChannelType ChannelId , Dio_LevelType Level)
{
	switch( PortId )
	{
		case Dio_PortA :
			if( Level == Dio_LevelHigh )
			{
				GPIOA->DATA |= (1U << ChannelId);
			}
			else
			{
				GPIOA->DATA &= ~( 1U << ChannelId );
			}
			break;
			
		case Dio_PortB :
			if( Level == Dio_LevelHigh )
			{
				GPIOB->DATA |= (1U << ChannelId);
			}
			else
			{
				GPIOB->DATA &= ~( 1U << ChannelId );
			}
			break;
			
		case Dio_PortC :
			if( Level == Dio_LevelHigh )
			{
				GPIOC->DATA |= (1U << ChannelId);
			}
			else
			{
				GPIOC->DATA &= ~( 1U << ChannelId );
			}
			break;
		
		case Dio_PortD :
			if( Level == Dio_LevelHigh )
			{
				GPIOD->DATA |= (1U << ChannelId);
			}
			else
			{
				GPIOD->DATA &= ~( 1U << ChannelId );
			}
			break;
			
		case Dio_PortE :
			if( Level == Dio_LevelHigh )
			{
				GPIOE->DATA |= (1U << ChannelId);
			}
			else
			{
				GPIOE->DATA &= ~( 1U << ChannelId );
			}
			break;
			
			
		case Dio_PortF :
			if( Level == Dio_LevelHigh )
			{
				GPIOF->DATA |= (1U << ChannelId);
			}
			else
			{
				GPIOF->DATA &= ~( 1U << ChannelId );
			}
			break;
			
			

	}

}





/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortType PortId , Dio_ChannelType ChannelId , Dio_PinDirection Direction)                                      
* \Description     : Read value of Dio channel(pin)                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId , channelid , Direction                    
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId , Dio_ChannelType ChannelId )
{
	Dio_LevelType value;
	switch( PortId )
	{
		case Dio_PortA:
				value = GET_BIT(GPIOA->DATA , ChannelId);
				return value;

		
		case Dio_PortB:
			value = GET_BIT(GPIOB->DATA , ChannelId);
			return value;
		
		case Dio_PortC:
			value = GET_BIT(GPIOC->DATA , ChannelId);
			return value;
		
		case Dio_PortD:
			value = GET_BIT(GPIOD->DATA , ChannelId);
			return value;
		
		case Dio_PortE:
			value = GET_BIT(GPIOE->DATA , ChannelId);
			return value;
		
		case Dio_PortF:
			value = GET_BIT(GPIOF->DATA , ChannelId);
			return value;
		

		
	}
}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId , Dio_PinDirection Direction)                                  
* \Description     : read value of Dio port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId , Direction
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType
*******************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
		Dio_PortLevelType value;
		switch( PortId )
		{
			case Dio_PortA:
				value = (Dio_PortLevelType) (GPIOA->DATA);
				return value;


			
			case Dio_PortB:
				value = (Dio_PortLevelType) (GPIOB->DATA);
				return value;
			
			case Dio_PortC:
				value = (Dio_PortLevelType) (GPIOC->DATA);
				return value;
			
			case Dio_PortD:
				value = (Dio_PortLevelType) (GPIOD->DATA);
				return value;
			
			case Dio_PortE:
				value = (Dio_PortLevelType) (GPIOE->DATA);
				return value;
			
			case Dio_PortF:
				value = (Dio_PortLevelType) (GPIOF->DATA);
				return value;
			
			
		}
}









/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId , Dio_PortLevelType Level)                                   
* \Description     : write value of Dio port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId , 	Level
* \Parameters (out): None                                                      
* \Return value:   : void
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId , Dio_PortLevelType Level)
{
		switch(PortId)
		{
			case Dio_PortA:
				GPIOA->DATA = Level;
				break;
			
			case Dio_PortB:
				GPIOB->DATA = Level;
				break;
			
			case Dio_PortC:
				GPIOC->DATA = Level;
				break;
			
			case Dio_PortD:
				GPIOD->DATA = Level;
				break;
			
			case Dio_PortE:
				GPIOE->DATA = Level;
				break;
			
			case Dio_PortF:
				GPIOF->DATA = Level;
				break;
			


		}
}


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
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);




/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
