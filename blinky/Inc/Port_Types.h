/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  Port
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef Port_TYPES_H
#define Port_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum {
	Port_PinDio = 0,
	Port_PinAlterFunction
	
} Port_PinModeType ;


typedef enum {
	Port_PinInput = 0,
	Port_PinOutput
	
} Port_PinDirectionType;

typedef enum {
	Port_PinAttachPUP = 0,
	Port_PinAttachPDW
	
} Port_PinInternalAttachType ;


typedef enum {
	Port_PinCurrent2 = 0,
	Port_PinCurrent4,
	Port_PinCurrent8
} Port_PinOutputCurrentType ;


typedef struct Port_ConfigType {
	Dio_PortType PortId;
	Dio_ChannelType ChannelId;
	Port_PinModeType Mode;
	Dio_LevelType Level;
	Port_PinDirectionType Direction;
	Port_PinInternalAttachType Attach;
	Port_PinOutputCurrentType Current;
	
} Port_ConfigType;

#endif  /* Port_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
