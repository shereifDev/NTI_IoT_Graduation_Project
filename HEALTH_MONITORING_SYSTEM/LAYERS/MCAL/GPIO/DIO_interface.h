/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     DIO_interface.h           ****************** */


#ifndef        DIO_INTERFACE_H
#define        DIO_INTERFACE_H

//*****************************<_INC_PART_>*************************** */

#include "STD_TYPES.h"

//*****************************<_DEF_PART_>*************************** */

typedef  struct {
 uint_8  GPIO_PORT  : 2  ;
 uint_8  GPIO_PIN   : 3  ;
 uint_8  GPIO_DIR   : 1  ;
 uint_8  GPIO_LOGIC : 1  ; 

}GPIO_PIN_CNFG ;


typedef enum {
  GPIO_PORTA    ,            
  GPIO_PORTB    ,         
  GPIO_PORTC    ,         
  GPIO_PORTD            
}GPIO_PORTS ;


typedef enum {
  GPIO_PIN0   , 
  GPIO_PIN1   ,    
  GPIO_PIN2   ,    
  GPIO_PIN3   ,               
  GPIO_PIN4   , 
  GPIO_PIN5   ,    
  GPIO_PIN6   ,    
  GPIO_PIN7   
}GPIO_PINS ;


#define        GPIO_INPUT           0 
#define        GPIO_OUTPUT          1 
        
#define        MAX_PORT_NUM         3 
#define        MAX_PIN_NUM          7 
#define        DIR_TWO_CHOICE       1

#define        GPIO_LOGIC_LOW       0
#define        GPIO_LOGIC_HIGH      1


/*************************<FUNCTIONS_PROTOTYEPS ********************** */

/**
 * @brief Sets the data direction of a specific pin (Input or Output).
 * 
 * @param ptr Pointer to the pin configuration structure containing:
 *           - GPIO_PORT
 *           - GPIO_PIN
 *           - GPIO_DIR
 * @return ErrorState Status of the function execution (OK or NOK).
 */

ErrorState MCAL_DIO_setPinDir(GPIO_PIN_CNFG*ptr);

/**
 * @brief Sets the logic value of a specific pin (High or Low).
 * 
 * @param ptr Pointer to the pin configuration structure.
 * @param logic The desired logic state (GPIO_LOGIC_LOW or GPIO_LOGIC_HIGH).
 * @return ErrorState Status of the function execution (OK or NOK).
 */

ErrorState MCAL_DIO_setPinValue(GPIO_PIN_CNFG*ptr,uint_8 logic);

/**
 * @brief Reads the current logic state of a specific pin.
 * 
 * @param ptr Pointer to the pin configuration structure.
 * @param PinVal Pointer to a variable where the read logic value will be stored.
 * @return ErrorState Status of the function execution (OK or NOK).
 */

ErrorState MCAL_DIO_readPinLogic(GPIO_PIN_CNFG*ptr,uint_8 *PinVal);

/**
 * @brief Toggles (inverts) the current logic state of a specific pin.
 * 
 * @param ptr Pointer to the pin configuration structure.
 * @return ErrorState Status of the function execution (OK or NOK).
 */

ErrorState MCAL_DIO_toggilePinLogic(GPIO_PIN_CNFG*ptr);

/**
 * @brief Sets the data direction for an entire port (all 8 pins).
 * 
 * @param copy_port The target port (e.g., GPIO_PORTA).
 * @param copy_dir The desired direction value for the entire port (0x00 to 0xFF).
 * @return ErrorState Status of the function execution (OK or NOK).
 */

ErrorState MCAL_DIO_setPortDir(uint_8 copy_port ,uint_8 copy_dir);

/**
 * @brief Sets the logic value for an entire port (all 8 pins).
 * 
 * @param copy_port The target port (e.g., GPIO_PORTA).
 * @param copy_val The desired logic value for the entire port (0x00 to 0xFF).
 * @return ErrorState Status of the function execution (OK or NOK).
 */

ErrorState MCAL_DIO_setPortVal(uint_8 copy_port ,uint_8 copy_val);

/**
 * @brief Reads the current logic state of an entire port.
 * 
 * @param copy_port The target port to read from (e.g., GPIO_PORTA).
 * @param pinVal Pointer to a variable where the read port value will be stored.
 * @return ErrorState Status of the function execution (OK or NOK).
 */

ErrorState MCAL_DIO_readPortLogic(uint_8 copy_port,uint_8 *pinVal);

/**
 * @brief Toggles (inverts) the logic state of all pins in an entire port.
 * 
 * @param copy_port The target port to toggle (e.g., GPIO_PORTA).
 * @return ErrorState Status of the function execution (OK or NOK).
 */

ErrorState MCAL_DIO_toggilePortLogic(uint_8 copy_port);



#endif /*< DIO_INTERFACE_H*/