typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define Door_Sensor_Config_Ptr char


typedef Door_Sensor_pin char;




/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Door_Sensor_init                                  *
 * Description          : Initialize the door sensor                        *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (array of the required configurations)     *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void Door_Sensor_init(Door_Sensor_Config_Ptr* config);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : Door_Sensor_Read                                  *
 * Description          : read the state of door closed or open             *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (structure of port and pin)                   *
 * Parameters (out)     : value (Current state of the door)                 *
 * Return value:        : void                                              *
 ***************************************************************************/
void Door_Sensor_Read(Door_Sensor_pin pin , uint8_t* value);
