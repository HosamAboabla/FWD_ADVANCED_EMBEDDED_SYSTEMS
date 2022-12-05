typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Light_Switch_Config_Ptr char


typedef Light_Switch_pin char;




/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Light_Switch_init                                 *
 * Description          : Initialize the light switch                       *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (array of the required configurations)     *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Light_Switch_init(Light_Switch_Config_Ptr* config);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Light_Switch_Read                                 *
 * Description          : Read the state of light switch                    *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (struture of port and pin)                    *
 * Parameters (out)     : value (current state of the light)                *
 * Return value:        : void                                              *
 ***************************************************************************/
void Light_Switch_Read(Light_Switch_pin pin , uint8_t* value);
