typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Buzzer_Config_Ptr char


typedef Buzzer_pin char;




/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Buzzer_init                                       *
 * Description          : initialize the buzzer                             *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (array of the required configurations)     *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Buzzer_init(Buzzer_Config_Ptr* config);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Buzzer_On                                         *
 * Description          : turn on the buzzer                                *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (struture of port and pin)                    *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Buzzer_On(Buzzer_pin pin);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Buzzer_Off                                        *
 * Description          : turn off the buzzer                               *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (struture of port and pin)                    *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Buzzer_Off(Buzzer_pin pin);
