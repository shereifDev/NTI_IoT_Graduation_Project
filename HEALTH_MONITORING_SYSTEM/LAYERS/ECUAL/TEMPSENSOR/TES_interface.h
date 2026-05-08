/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     TES_interface.h           ****************** */


#ifndef   _TES_INTERFACE_H_
#define	  _TES_INTERFACE_H_

//*****************************<_INC_PART_>*************************** */

#include  "ADC_interface.h"
#include  "DIO_interface.h"

//*****************************<_DEF_PART_>*************************** */

typedef enum {

    Channel_1  ,
    Channel_2  ,
    Channel_3  ,
    Channel_4  ,
    Channel_5  ,
    Channel_6  ,
    Channel_7  ,
    Channel_8  

}Sensor_Channel_Sel;


//*************************<FUNCTION PROTOTYEPS********************** */


/**
 * @brief   Initializes the LM35 temperature sensor pin.
 * @details This function configures the specified ADC channel pin exclusively on 
 * PORTA as an input. It also ensures the internal pull-up resistor is 
 * disabled (Logic Low) to prevent interference with the analog signal.
 * @param   sensorChannel : The ADC channel where the LM35 is connected (e.g., ADC_CH0).
 * @return  ErrorState    : OK if the pin direction is set successfully, NOK otherwise.
 */
ErrorState ECUAL_LM35_init(Sensor_Channel_Sel sensorChannel);



/**
 * @brief   Reads the analog voltage from the LM35 sensor and calculates the temperature in Celsius.
 * @details This function uses the ADC module to read the digital value corresponding to the 
 * voltage output of the LM35 sensor. It then applies the conversion formula 
 * (Temp = (ADC_Value * 500) / 1024) assuming a 5V reference voltage and 10-bit resolution.
 * @param   sensorChannel : The ADC channel where the LM35 is connected (e.g., ADC_CH0).
 * @param   temperature   : Pointer to a float variable to store the final temperature value.
 * @return  ErrorState    : OK if the conversion and calculation are successful, 
 *                          NOK if the ADC fails or the pointer is NULL.
 * 
 * 
 */
ErrorState ECUAL_LM35_getTemp(uint_8 sensorChannel, float *temperature);






#endif	/* _TES_INTERFACE_H_ */

