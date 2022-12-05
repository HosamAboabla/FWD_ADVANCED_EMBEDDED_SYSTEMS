

typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Speed_Sensor_Config_Ptr char


typedef Speed_Sensor_pin char;




/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Speed_Sensor_init                                 *
 * Description          : Initialize the speed sensor                       *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (array of the required configurations)     *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Speed_Sensor_init(Speed_Sensor_Config_Ptr* config);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Speed_Sensor_Read                                 *
 * Description          : Read speed value                                  *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (struture of port and pin)                    *
 * Parameters (out)     : value (Current speed value)                       *
 * Return value:        : void                                              *
 ***************************************************************************/
void Speed_Sensor_Read(Speed_Sensor_pin pin , uint8_t* value);


