/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  ADC_interface.h          ****************/
/****************************************************************************/



#ifndef   ADC_INTERFACE_H_
#define   ADC_INTERFACE_H_


//*****************************<_INC_PART_>*************************** */

#include     "STD_types.h"

/******************************ADC_CHANNEL_SEL******************* */

typedef enum {

    ADC_CH1 , 
    ADC_CH2 , 
    ADC_CH3 , 
    ADC_CH4 , 
    ADC_CH5 , 
    ADC_CH6 , 
    ADC_CH7 , 
    ADC_CH8 

}ADC_CHANNEL_SEL;



/**
 * @brief  Initializes the ADC peripheral based on static configurations.
 * 
 * @details This function configures the reference voltage, result adjustment 
 *          (Right/Left), and clock prescaler as defined in "ADC_config.h", 
 *          and finally enables the ADC module.
 * 
 * @param  void
 * @return ErrorState: OK if initialization is successful, NOK otherwise.
 * 
 */
ErrorState MCAL_ADC_init(void);



/**
 * @brief  Reads the analog value from a specific ADC channel (Synchronous).
 * 
 * @details This function selects the given ADC channel, starts the conversion, 
 *          and waits (polls) until the conversion is complete using a timeout 
 *          mechanism to prevent infinite blocking. The digital result is then 
 *          stored in the provided pointer.
 * 
 * @param  Copy_Channel : The ADC channel to be read (e.g., ADC_CH0 to ADC_CH7).
 * @param  result       : Pointer to a uint_16 variable to store the final digital value.
 * 
 * @return ErrorState   : OK if the conversion is successful, 
 *                        NOK if a timeout occurs or if the pointer is NULL.
 */
ErrorState MCAL_ADC_getResult(uint_8 Copy_Channel , uint_16 *result);



#endif /*<ADC_INTERFACE_H_*/