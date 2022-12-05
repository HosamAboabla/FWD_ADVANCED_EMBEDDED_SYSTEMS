





typedef uint32_t unsigned char;
#define GPT_Config_Ptr char







/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : GPT_init                                          *
 * Description          : initialize all timers drivers                     *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : config (array of the required configurations)     *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void GPT_init(GPT_Config_Ptr* config);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : GPT_Start                                         *
 * Description          : start the timer for required ticks and fire ISR   *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : Number of ticks to count                          *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void GPT_Start(uint32_t ticks);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : GPT_Stop                                          *
 * Description          : stop the timer                                    *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : None                                              *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void GPT_Stop(void);

/***************************************************************************\
 *          * Function Info *                                               *
 *                                                                          *
 * Syntax               : GPT_Delay                                         *
 * Description          : Blocking delay                                    *
 * Sync\Async           : Synchronous                                       *
 * Parameters (in)      : delay (number of ms to wait)                      *
 * Parameters (out)     : None                                              *
 * Return value:        : void                                              *
 ***************************************************************************/
void GPT_Delay(uint32_t delay);