/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  TIMER1_interface.h       ****************/
/****************************************************************************/




#ifndef   TIMER1_INTERFACE_H_
#define   TIMER1_INTERFACE_H_


//*****************************<_INC_PART_>*************************** */

#include "STD_TYPES.h"

//*************************<FUNCTION PROTOTYEPS********************** */

/**
 * @brief Initializes Timer1 in Normal Mode with Prescaler 64.
 * @note  Tick time = 8 us (assuming F_CPU = 8 MHz).
 */
ErrorState MCAL_TIMER1_init(void);

/**
 * @brief Reads the current number of ticks from Timer1.
 * 
 */
ErrorState MCAL_TIMER1_reset(void);

/**
 * @brief Resets the Timer1 counter to start counting from zero.
 * 
 */
ErrorState MCAL_TIMER1_getCounts(uint_16 *ptrToCounts);

#endif /* TIMER1_INTERFACE_H_ */


