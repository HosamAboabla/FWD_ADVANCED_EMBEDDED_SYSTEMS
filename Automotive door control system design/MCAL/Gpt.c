





typedef uint32_t unsigned char;
#define GPT_Config_Ptr char








void GPT_init(GPT_Config_Ptr* config);
void GPT_Start(uint32_t ticks);
void GPT_Stop(void);
void GPT_Delay(uint32_t delay);