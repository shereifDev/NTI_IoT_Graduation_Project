/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     HBS_interface.h           ****************** */


#ifndef   _HBS_INTERFACE_H_
#define	  _HBS_INTERFACE_H_

//*****************************<_INC_PART_>*************************** */

#include     "STD_types.h"
#include "EXTI_interface.h"
#include "TIMER1_interface.h"

//*****************************<_DEF_PART_>*************************** */





//*************************<FUNCTION PROTOTYEPS********************** */


/**
 * @brief Callback function executed every time a pulse is detected (Rising Edge).
 * 
 * 
 */
static void ECUAL_HeartBeat_Callback(void);


/**
 * @brief Initializes the Heartbeat sensor (EXTI and Timer1).
 * 
 * 
 * 
 */
ErrorState ECUAL_HeartBeat_init(void);

/**
 * @brief Gets the latest calculated BPM value.
 * 
 * 
 */
ErrorState ECUAL_HeartBeat_getBPM(uint_16 *bpm);
#endif	/* _HBS_INTERFACE_H_ */

