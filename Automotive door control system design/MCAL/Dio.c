














typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define DIO_Config_Ptr char


typedef DIO_pin char;





void DIO_init(DIO_Config_Ptr* config);
void DIO_Write(DIO_pin pin , uint8_t value);
void DIO_Read(DIO_pin pin , uint8_t* value);
void DIO_Toggle(DIO_pin pin);
