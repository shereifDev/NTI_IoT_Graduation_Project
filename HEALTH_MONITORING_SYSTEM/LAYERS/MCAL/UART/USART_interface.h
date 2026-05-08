/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  USART_interface.h        ****************/
/****************************************************************************/



#ifndef   USART_INTERFACE_H_
#define   USART_INTERFACE_H_



//*****************************<_INC_PART_>*************************** */

#include "STD_TYPES.h"

//*****************************<_DEF_PART_>*************************** */


/**
 * @brief  Initializes the USART peripheral with the configured baud rate and frame format.
 * @note   Configuration parameters (like baud rate, parity, etc.) are usually set in a separate config file.
 * 
 */
ErrorState MCAL_USART_initialize(void);

/**
 * @brief  Transmits a single byte of data via USART.
 * @param  data The 8-bit data (uint_8) to be transmitted.
 * 
 */
ErrorState MCAL_USART_transmitData(uint_8 data);

/**
 * @brief  Receives a single byte of data via USART.
 * @note   This function typically blocks until a byte of data is successfully received.
 * 
 */

ErrorState MCAL_USART_receiveData(uint_8 *data);


#endif /*<USART_INTERFACE_H_*/