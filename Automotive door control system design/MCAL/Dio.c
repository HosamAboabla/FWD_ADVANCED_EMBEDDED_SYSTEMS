














typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define DIO_Config_Ptr char


typedef DIO_pin char;


/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : DIO_init                                          *
 * Description          : Initialize DIO Driver                             *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (pointer to array of configurations)       * 
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void DIO_init(DIO_Config_Ptr* config);



/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : DIO_Write                                         *
 * Description          : write hight or low to output pin                  *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      :   pin (structure to port and pin number)          *
 *                          value (High or Low)                             * 
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void DIO_Write(DIO_pin pin , uint8_t value);


/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : DIO_Read                                          *
 * Description          : Read the value of input pin                       *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (structure to port and pin number)            *
 * Parameters (out)     : value (High or Low)                               *
 * Return value:        : void                                              *
 ***************************************************************************/
void DIO_Read(DIO_pin pin , uint8_t* value);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : DIO_Toggle                                        *
 * Description          : Toggle value of output pin                        *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : pin (structure to port and pin number)            *
 * Parameters (out)     : Non                                               *
 * Return value:        : void                                              *
 ***************************************************************************/
void DIO_Toggle(DIO_pin pin);
