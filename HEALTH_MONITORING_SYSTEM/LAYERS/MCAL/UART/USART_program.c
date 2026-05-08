/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  USART_program.c          ****************/
/****************************************************************************/


//*****************************<_INC_PART_>*************************** */

#include  "USART_interface.h"
#include  "USART_private.h"
#include  "USART_config.h"

#include  "BIT_MATH.h"
#include "STD_TYPES.h"





ErrorState MCAL_USART_initialize(void){

    ErrorState checkErrorState = OK ;

    /* Set baud rate */
    uint_16 UBRR = ((F_CPU/(16UL*USART_BAUD_RATE))-1);
    UBRRH  = (uint_8)(UBRR >> 8);
    USART->UBRRL = (uint_8)(UBRR);

    /* Enable receiver and transmitter */
    USART->UCSRB = (1<<UCSRB_RXEN) | (1<<UCSRB_TXEN) ;

    /* Set frame format*/
    #if   USART_CHAR_SIZE == 5
    UCSRC = (1 << UCSRC_URSEL);

    #elif USART_CHAR_SIZE == 6
    UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ0) ;
    
    #elif USART_CHAR_SIZE == 7
    UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) ;
    
    #elif USART_CHAR_SIZE == 8
    UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
    
    #elif USART_CHAR_SIZE == 9
    UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
    SET_BIT(USART->UCSRB,UCSRB_UCSZ2);

    #else 
    #error "invalid choise !"

    #endif /*< USART_CHAR_SIZE*/
    
    return checkErrorState ;
}


////////////////////////////////////////////////////////////////<_0_0______/\/\/\/\/\/


 ErrorState MCAL_USART_transmitData(uint_8 data){

  ErrorState checkErrorState = OK ;
  // Wating untill data transmition
  while(! READ_BIT(USART->UCSRA ,UCSRA_UDRE )) ;
  //Send data
   USART->UDR = data;

  return checkErrorState ;
}

////////////////////////////////////////////////////////////////<_0_0______/\/\/\/\/\/


 ErrorState MCAL_USART_receiveData(uint_8 *data){

  ErrorState checkErrorState = OK ;

  // Wating untill data Received Completly 
  while(! READ_BIT(USART->UCSRA ,UCSRA_RXC )) ;
  //Receive data 
  *data = USART->UDR ;

  return checkErrorState ;
}

