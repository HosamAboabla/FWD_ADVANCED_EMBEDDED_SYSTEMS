#include "TM4C123GH6PM.h"
#include "Dio.h"
#include "Port.h"
#include "Port_Types.h"
#include "Gpt.h"



static Port_ConfigType pinf0 = {
			Dio_PortF,
			Dio_Pin0,
			Port_PinDio,
			Dio_LevelHigh,
			Port_PinOutput,
			Port_PinAttachPUP,
			Port_PinCurrent2
			
};

static Port_ConfigType pinf7 = {
			Dio_PortF,
			Dio_Pin7,
			Port_PinDio,
			Dio_LevelHigh,
			Port_PinOutput,
			Port_PinAttachPUP,
			Port_PinCurrent2
			
};



int main(void)
{
	
	Port_ConfigType ConfigPtr[]  = { pinf0 , pinf7 };
	Port_Init(ConfigPtr , 2);
	
	uint32 onTime = 2000 , offTime = 1000;

	Gpt_TimerInit();
	Gpt_StartTimer(16000000);
	


	while(1)
	{

		
		
		Dio_WriteChannel(Dio_PortF , Dio_Pin0 , Dio_LevelHigh); // Turn LED on 
		Gpt_TimerDelayMs( onTime ); // On Delay
		
		
		Dio_WriteChannel(Dio_PortF , Dio_Pin0 , Dio_LevelLow); // Turn LED off 
		Gpt_TimerDelayMs( offTime ); // Off Delay
		
		
		
	}
	
	return 0;
}




