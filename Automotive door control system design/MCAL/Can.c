

typedef uint32_t unsigned char;
typedef uint8_t unsigned char;
#define CAN_Config_Ptr char


typedef DIO_pin char;




/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : CAN_init                                          *
 * Description          : initialize all CAN modules                        *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (array of the required configurations)     *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void CAN_init(CAN_Config_Ptr* config);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : CAN_Send                                          *
 * Description          : Send data using CAN Bus                           *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : data (data to be send)                            *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void CAN_Send(uint32_t* data);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : CAN_Receive                                       *
 * Description          : Receive data using CAN Bus                        *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : Non                                               *
 * Parameters (out)     : data (the received data)                          *
 * Return value:        : void                                              *
 ***************************************************************************/
void CAN_Receive(uint32_t* data);

