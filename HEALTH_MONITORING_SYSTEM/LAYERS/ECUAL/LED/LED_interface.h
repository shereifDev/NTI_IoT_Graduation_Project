/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     LED_interface.h           ****************** */




#ifndef  _LED_INTERFACE_H
#define	 _LED_INTERFACE_H


//*****************************<_INC_PART_>*************************** */

#include   "DIO_interface.h"

//*****************************<_DEF_PART_>*************************** */


typedef struct {
    uint_8 port_name :2;
    uint_8 pin       :3;
    uint_8 led_state :1;
    uint_8 connection:1;
}LED_CNFG;


typedef enum {
    LED_OFF,
    LED_ON
}LED_STATUS;

typedef enum {
    LED_ACTIVE_LOW  ,
    LED_ACTIVE_HIGH
    
}LED_CONNECTION;


/*************************<FUNCTIONS_PROTOTYEPS ********************** */

/**
 * @brief  Initializes the LED by setting its port and pin direction as output.
 * @param  led Pointer to the LED configuration structure (LED_CNFG).
 * @return ErrorState indicating the success or failure of the initialization.
 */
ErrorState ECUAL_LED_intialize(LED_CNFG *led);

/**
 * @brief  Turns the specified LED on.
 * @param  led Pointer to the LED configuration structure (LED_CNFG).
 * @return ErrorState indicating if the operation was successful.
 */
ErrorState ECUAL_LED_turn_on (LED_CNFG *led); 

/**
 * @brief  Turns the specified LED off.
 * @param  led Pointer to the LED configuration structure (LED_CNFG).
 * @return ErrorState indicating if the operation was successful.
 */
ErrorState ECUAL_LED_turn_off (LED_CNFG *led);

/**
 * @brief  Toggles the current state of the specified LED (ON to OFF, or OFF to ON).
 * @param  led Pointer to the LED configuration structure (LED_CNFG).
 * @return ErrorState indicating if the operation was successful.
 */
ErrorState ECUAL_LED_toggle (LED_CNFG *led);


#endif /*<_LED_INTERFACE_H*/