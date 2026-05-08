/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     TES_program.c            ****************** */


//*****************************<_INC_PART_>*************************** */

#include    "TES_interface.h"
#include    "TES_private.h"
#include    "TES_config.h"

#include    "STD_TYPES.h"
#include    "BIT_MATH.h"



ErrorState ECUAL_LM35_init(Sensor_Channel_Sel sensorChannel) {

    ErrorState checkErrorState = OK;
    GPIO_PIN_CNFG ptr1 = {.GPIO_PORT = GPIO_PORTA , .GPIO_PIN = sensorChannel , .GPIO_DIR = GPIO_INPUT , .GPIO_LOGIC = GPIO_LOGIC_LOW}; 
    checkErrorState =  MCAL_DIO_setPinDir(&ptr1);

    return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_LM35_getTemp(uint_8 sensorChannel, float *temperature) {
    // ErrorState checkErrorState = OK;
    uint_16 digitalValue = 0;

    // checkErrorState =
     MCAL_ADC_getResult(sensorChannel, &digitalValue);

    // if (checkErrorState == OK && temperature != NULL) {
        
        *temperature = ((float)digitalValue * (LM35_VREF_MV / LM35_MV_PER_CELSIUS)) / LM35_ADC_MAX_STEPS;

    // }else {
    //     checkErrorState = NOK;
    // }

    // return checkErrorState;
}
