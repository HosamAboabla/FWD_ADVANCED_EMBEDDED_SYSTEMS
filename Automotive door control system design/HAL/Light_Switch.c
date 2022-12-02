typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Light_Switch_Config_Ptr char


typedef Light_Switch_pin char;





void Light_Switch_init(Light_Switch_Config_Ptr* config);
void Light_Switch_Read(Light_Switch_pin pin , uint8_t* value);
