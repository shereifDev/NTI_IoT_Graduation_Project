/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  ADC_config.h             ****************/
/****************************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/***************************<__INC_PART__>*********************** */

#include "ADC_private.h"

/***************************<__CONFIG_PART__>******************** */




/**
 * @brief  Choose the Channel which connected with ur sensor...
 *         - ADC_ch1
 *         - ADC_ch2
 *         - ADC_ch3
 *         - ADC_ch4
 *         - ADC_ch5
 *         - ADC_ch6
 *         - ADC_ch7
 *         - ADC_ch8
 */

#define         INPUT_CHANNEL         ADC_CH1








/**
 * @brief  Select the voltage reference for the ADC
 * @note in case choise AVCC_PIN or Internal_Voltage.. must be connect AREF PIN with External cap
 *
 * options :  
 *            - AREF_PIN
 *            - AVCC_PIN
 *            - Internal_Voltage
 *
 */

#define         REF_VOLTAGE           AVCC_PIN








/**
 * @brief Select the Frequency of the input Clock of the ADC
 *
 * options : 
 *            - FOSC_DIV_2
 *            - FOSC_DIV_4
 *            - FOSC_DIV_8
 *            - FOSC_DIV_16
 *            - FOSC_DIV_32
 *            - FOSC_DIV_64
 *            - FOSC_DIV_128
 */

#define         ADC_FREQ             FOSC_DIV_128






/**
 * @brief  Select the Conversion Mode
 *
 * options :
 *           - SINGLE_CONV_MODE
 *           - AUTO_TRIGGERING_MODE
 */

 #define       CONVERSION_MODE     SINGLE_CONV_MODE  








/**
 * @brief  SELECT THE ADC ADJUST RESULT  
 * 
 * options : 
 *           - ADC_RIGHT_ADJUST
 *           - ADC_LEFT_ADJUST
 */

 #define       ADC_ADJUST_RESULT      ADC_RIGHT_ADJUST 
 
 
 



/**
 * @brief  Select ADC Auto Trigger Source
 *
 *   Options:
             - FREE_RUNNING
             - ANALOG_COMPARATOR
             - EXTERNAL_INTERRUPT0
             - TIMER0_COMPARE_MATCH
             - Timer/Counter0_Overflow
             - Timer/Counter1_Compare_Match_B
             - Timer/Counter1_Overflow
             - Timer/Counter1_Capture_Event
*/

#define        ADC_TRIGGER_SOURCE      FREE_RUNNING






















#endif /*< ADC_CONFIG_H__*/