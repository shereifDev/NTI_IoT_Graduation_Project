/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     BUZZER_interface.h        ****************** */






#ifndef  _BUZZER_INTERFACE_H
#define	 _BUZZER_INTERFACE_H




//*****************************<_INC_PART_>*************************** */

#include   "DIO_interface.h"

//*****************************<_DEF_PART_>*************************** */


typedef enum {
    SOUND_OFF,
    SOUND_ON
}BUZZER_STATE;


typedef struct {
    uint_8 port:3;
    uint_8 pin:3 ;
    uint_8 state:1; 
}BUZZER_CNFG;


/*************************<FUNCTIONS_PROTOTYEPS ********************** */

/**
 * @brief  Initializes the buzzer by setting its port and pin direction as output.
 * @param  ptr Pointer to the Buzzer configuration structure (BUZZER_CNFG).
 * @return ErrorState indicating the success or failure of the initialization.
 * 
 */
ErrorState ECUAL_BUZZER_initialize (BUZZER_CNFG *ptr);

/**
 * @brief  Turns the buzzer on, causing it to emit sound.
 * @param  ptr Pointer to the Buzzer configuration structure (BUZZER_CNFG).
 * @return ErrorState indicating if the operation was successful.
 */
ErrorState ECUAL_BUZZER_turn_on (BUZZER_CNFG *ptr);

/**
 * @brief  Turns the buzzer off, silencing it.
 * @param  ptr Pointer to the Buzzer configuration structure (BUZZER_CNFG).
 * @return ErrorState indicating if the operation was successful.
 */
ErrorState ECUAL_BUZZER_turn_off (BUZZER_CNFG *ptr);

/**
 * @brief  Toggles the current state of the buzzer (ON to OFF, or OFF to ON).
 * @param  ptr Pointer to the Buzzer configuration structure (BUZZER_CNFG).
 * @return ErrorState indicating if the operation was successful.
 */
ErrorState ECUAL_BUZZER_toggle (BUZZER_CNFG *ptr);

#endif /*<_BUZZER_INTERFACE_H*/