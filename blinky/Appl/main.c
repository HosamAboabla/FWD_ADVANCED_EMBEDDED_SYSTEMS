#include "TM4C123GH6PM.h"
#include "Dio.h"
#include "Port.h"
#include "Port_Types.h"
#include "Gpt.h"


void TIMER1A_Handler(void);

#define NVIC_B 					     0xE000E000
#define EN0									 0x100

#define GetReg(X,Y)				(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
	

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



void Time1A_1sec_delay(void)
{
	       /* Timer1A timeout flag bit clears*/
	SYSCTL->RCGCTIMER |= ( 1U << 1U );  /*enable clock Timer1 subtimer A in run mode */
	TIMER1->CTL = 0; /* disable timer1 output */
	TIMER1->CFG = 0x4; /*select 16-bit configuration option */
	TIMER1->TAMR &= ~(1U << 4); // count down
	TIMER1->TAMR |= ( 1U << 1U ); /*select periodic down counter mode of timer1 */
	TIMER1->TAPR = 3;//  250-1; /* TimerA prescaler value */
	TIMER1->TAILR = 0; // 64000-1 ; /* TimerA counter starting count down value  */
	
	TIMER1->IMR =0x01; /*enables TimerA time-out  interrupt mask */
	
	
	
	TIMER1->TAILR = 64000-1 ;
	TIMER1->ICR = 0x1;          /* TimerA timeout flag bit clears*/
	
	
	GetReg(NVIC,EN0) |= (1 << 21);
	TIMER1->CTL = 0x01;        /* Enable TimerA module */
	// NVIC->ISER[0] |= (1 << 21); /*enable IRQ21 */
	
	
	
}

void t0_init(void)
{
	SYSCTL->RCGCTIMER |= (1U << 0 ); // Enable clock for TIMER0 32/16
	// 1- disable TimerA and TimerB
	TIMER0->CTL &= ~( 1U << 0);
	// For a 16/32-bit timer, this value selects the 32-bit timer configuration.
	TIMER0->CFG = 0x0;
	
	
	TIMER0->TAMR |= ( 0x2 << 0); // TIMER0->TAMR = 0x02; // Periodic mode
	TIMER0->TAMR &= ~(1U << 4); // count down
	
		// An interrupt is generated when the match value in the GPTMTAMATCHR
	// TIMER0->TAMR |= (1U << 5); 
	
	TIMER0->TAILR = 0x00F42400; // 10000;
	// TIMER0->ICR = 0x1;   
	// TIMER0->IMR |= ( 1U << 0 ); // Enable Match Interrupt Mask
	TIMER0->CTL |= ( 1U << 0); // Enable TimerA
	// NVIC->ISER[0] |= (1 << 19); /*enable IRQ21 */

}


void SysInit(void)
{
	SYSCTL->RCC  = 0x803D40;
}

int main(void)
{
	// SysInit();
	SystemCoreClockUpdate();
 	SysTick_Config(SystemCoreClock);
	
	Port_ConfigType ConfigPtr[]  = { pinf0 , pinf7 };
	Port_Init(ConfigPtr , 2);


	// __enable_irq();
	Time1A_1sec_delay();
	t0_init();
	
	// Gpt_Timer1Init();
	// Gpt_StartTimer1();
	


	uint8 value;
	while(1)
	{

		
		if( (TIMER0->RIS & 0x1) == 1 )
		{
			TIMER0->ICR |= ( 1 << 0 );
			GPIOF->DATA  ^= (1 << 0);
			
		}
		GPIOF->DATA  ^= (1 << 7);
		// Dio_WriteChannel(Dio_PortF , Dio_Pin7 , Dio_LevelHigh);
		// value = Dio_ReadPort(Dio_PortF);
		// Gpt_Timer1DelayMs( 1000 );
		
		
		// Dio_WriteChannel(Dio_PortF , Dio_Pin0 , Dio_LevelLow);
		// value = Dio_ReadPort(Dio_PortF);
		// Gpt_Timer1DelayMs(  2000 ) ; 
		
		
	}
	
	return 0;
}





/* Timer1 subtimer A interrupt service routine */
void TIMER1A_Handler()
{
	GPIOF->DATA  ^= (1 << 0); /* toggle Blue LED*/
    // if(TIMER1->MIS & 0x1)
    //    GPIOF->DATA  ^= (1 << 0); /* toggle Blue LED*/
  TIMER1->ICR = 0x1;          /* Timer1A timeout flag bit clears*/
}


void TIMER0A_Handler(void)
{
	Dio_WriteChannel(Dio_PortF , Dio_Pin0 , Dio_LevelHigh);
}




/*
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_GPIOHBCTL_R      (*((volatile unsigned long *)0x400FE06C))
#define GPIO_PORTF_AHB_DIR_R    (*((volatile unsigned long *)0x4005D400))
#define GPIO_PORTF_AHB_DEN_R    (*((volatile unsigned long *)0x4005D51C))
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))	

#define LED_RED   (1U << 3)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

// #define GPIO_PORTF_DATA_BITS_R  ((volatile unsigned long *)0x40025000) // 4002 50FF
// // #define GPIO_PORTF_DATA_BITS_R  ((volatile unsigned long *)0x400250FF) // 4002 50FF



	SYSCTL->RCGCGPIO |= (1U << 5) ; // enable gpio clock
	// SYSCTL->GPIOHBCTL = 255;
	GPIOF->DIR |= 255; // output
	GPIOF->AFSEL = 0U;
	GPIOF->DEN |= 255; // digital enable
	
	// GPIO_PORTF_DATA_BITS_R[ 0xFF ] = 0xFF;
	
	// SYSCTL_RCGCGPIO_R |= (1U << 5);  enable clock for GPIOF 
	// SYSCTL_GPIOHBCTL_R |= (1U << 5);  enable AHB for GPIOF 
	// GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
	// GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
	
*/