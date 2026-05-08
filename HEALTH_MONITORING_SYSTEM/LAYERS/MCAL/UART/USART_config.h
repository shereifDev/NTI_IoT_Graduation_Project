/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  USART_config.h           ****************/
/****************************************************************************/



#ifndef   USART_CONFIG_H_
#define   USART_CONFIG_H_


/**
 * @brief  this macro used for select the baud rate(freq) 
 * @note   choose a value between 0 to 4095 
 */

#define          USART_BAUD_RATE           9600UL
#define          F_CPU                     8000000UL  



/**
 * @brief this macro used for select the charachtar size we want to send or receive 
 * @note    u have 5 options :
 *                             - 5 
 *                             - 6
 *                             - 7
 *                             - 8
 *                             - 9
 *
 */
#define          USART_CHAR_SIZE            8













#endif /*<USART_CONFIG_H_*/


