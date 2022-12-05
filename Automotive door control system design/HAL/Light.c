typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Light_Config_Ptr char


typedef Light_pin char;




/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Light_init                                        *
 * Description          : Initialize the light                              *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (array of the required configurations)     *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Light_init(Light_Config_Ptr* config);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Light_On                                          *
 * Description          : turn on the light                                 *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (struture of port and pin)                    *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Light_On(Light_pin pin);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Light_Off                                         *
 * Description          : turn off the light                                *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (struture of port and pin)                    *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Light_Off(Light_pin pin);
