

typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define CAN_Config_Ptr char


typedef DIO_pin char;





void CAN_init(CAN_Config_Ptr* config);
void CAN_Send(uint32_t* data);
void CAN_Receive(uint32_t* data);

