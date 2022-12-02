typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Light_Config_Ptr char


typedef Light_pin char;





void Light_init(Light_Config_Ptr* config);
void Light_On(Light_pin pin);
void Light_Off(Light_pin pin);
