typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define ADC_Config_Ptr char


typedef ADC_pin char;




/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : ADC_init                                          *
 * Description          : initialize all pins as Analoge inputs             *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (array of the required configurations)     *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void ADC_init(ADC_Config_Ptr* config);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : ADC_Read                                          *
 * Description          : Read the current value of ADC pin                 *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (structure to port and pin)                   *
 * Parameters (out)     : value (Actuel value of the ADC pin)               *
 * Return value:        : void                                              *
 ***************************************************************************/
void ADC_Read(ADC_pin pin , uint8_t* value);

