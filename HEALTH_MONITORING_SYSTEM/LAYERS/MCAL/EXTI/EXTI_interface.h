/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  EXTI_interface.h         ****************/
/****************************************************************************/




#ifndef   EXTI_INTERFACE_H_
#define   EXTI_INTERFACE_H_

//*****************************<_INC_PART_>*************************** */

#include     "STD_types.h"
  

// Define the Interrupt sense control
#define EXTI_RISING_EDGE    1
#define EXTI_FALLING_EDGE   2

// Function to initialize INT0
ErrorState MCAL_EXTI_initINT0(void);

// Function to set the Callback 
ErrorState MCAL_EXTI_setCallBackINT0(void (*ptrToFunc)(void)) ;





#endif /*<EXTI_INTERFACE_H_*/

