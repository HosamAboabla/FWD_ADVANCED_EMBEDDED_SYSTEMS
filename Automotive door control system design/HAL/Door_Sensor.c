typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Door_Sensor_Config_Ptr char


typedef Door_Sensor_pin char;





void Door_Sensor_init(Door_Sensor_Config_Ptr* config);
void Door_Sensor_Read(Door_Sensor_pin pin , uint8_t* value);
