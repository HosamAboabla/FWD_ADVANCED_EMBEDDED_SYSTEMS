typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Buzzer_Config_Ptr char


typedef Buzzer_pin char;





void Buzzer_init(Buzzer_Config_Ptr* config);
void Buzzer_On(Buzzer_pin pin);
void Buzzer_Off(Buzzer_pin pin);
