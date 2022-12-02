typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define ADC_Config_Ptr char


typedef ADC_pin char;





void ADC_init(ADC_Config_Ptr* config);
void ADC_Read(ADC_pin pin , uint8_t* value);

