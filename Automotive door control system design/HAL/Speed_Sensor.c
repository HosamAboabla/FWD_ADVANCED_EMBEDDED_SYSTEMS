

typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Speed_Sensor_Config_Ptr char


typedef Speed_Sensor_pin char;





void Speed_Sensor_init(Speed_Sensor_Config_Ptr* config);
void Speed_Sensor_Read(Speed_Sensor_pin pin , uint8_t* value);


