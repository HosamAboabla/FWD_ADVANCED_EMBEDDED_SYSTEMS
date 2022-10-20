/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/
#ifndef Dio_H
#define Dio_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "Dio_Types.h"
#include "Bit_Math.h"
#include "TM4C123GH6PM.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void Dio_WriteChannel(Dio_PortType PortId , Dio_ChannelType ChannelId , Dio_LevelType Level);




/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortType PortId , Dio_ChannelType ChannelId , Dio_PinDirection Direction)                                      
* \Description     : Read value of Dio channel(pin)                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId , channelid  , Direction                   
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId , Dio_ChannelType ChannelId);


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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


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
void Dio_WritePort(Dio_PortType PortId , Dio_PortLevelType Level);


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


#endif  /* Dio_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
