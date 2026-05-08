/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  USART_private.h          ****************/
/****************************************************************************/



#ifndef    USART_PRIVATE_H_
#define    USART_PRIVATE_H_

#include "STD_types.h"


/* USART Registers Mapping */

typedef struct {
    uint_8 UBRRL;    /* 0x29 */
    uint_8 UCSRB;    /* 0x2A */
    uint_8 UCSRA;    /* 0x2B */
    uint_8 UDR;      /* 0x2C */
} USART_Regs;

#define   USART    ((volatile USART_Regs*) 0x29)


/**
 * @brief UCSRC & UBRRH REGISTERS DEFINITIONS 
 * @note  BOTH HAVE THE SAME ADDRESS 
 * 
 * 
 */

#define   UCSRC    *((volatile uint_8 *)0x40)    
#define   UBRRH    *((volatile uint_8 *)0x40)




/* --- UCSRA Bits --- */
#define UCSRA_RXC       7    /* USART Receive Complete */
#define UCSRA_TXC       6    /* USART Transmit Complete */
#define UCSRA_UDRE      5    /* USART Data Register Empty */
#define UCSRA_FE        4    /* Frame Error */
#define UCSRA_DOR       3    /* Data OverRun */
#define UCSRA_PE        2    /* Parity Error */
#define UCSRA_U2X       1    /* Double the USART Transmission Speed */
#define UCSRA_MPCM      0    /* Multi-processor Communication Mode */

/* --- UCSRB Bits --- */
#define UCSRB_RXCIE     7    /* RX Complete Interrupt Enable */
#define UCSRB_TXCIE     6    /* TX Complete Interrupt Enable */
#define UCSRB_UDRIE     5    /* USART Data Register Empty Interrupt Enable */
#define UCSRB_RXEN      4    /* Receiver Enable */
#define UCSRB_TXEN      3    /* Transmitter Enable */
#define UCSRB_UCSZ2     2    /* Character Size Bit 2 */
#define UCSRB_RXB8      1    /* Receive Data Bit 8 */
#define UCSRB_TXB8      0    /* Transmit Data Bit 8 */

/* --- UCSRC Bits --- */
#define UCSRC_URSEL     7    /* Register Select (Must be 1 for UCSRC) */
#define UCSRC_UMSEL     6    /* USART Mode Select (0: Async, 1: Sync) */
#define UCSRC_UPM1      5    /* Parity Mode Bit 1 */
#define UCSRC_UPM0      4    /* Parity Mode Bit 0 */
#define UCSRC_USBS      3    /* Stop Bit Select */
#define UCSRC_UCSZ1     2    /* Character Size Bit 1 */
#define UCSRC_UCSZ0     1    /* Character Size Bit 0 */
#define UCSRC_UCPOL     0    /* Clock Polarity */

/* --- UBRRH Bits --- */
#define UBRRH_URSEL     7    /* Register Select (Must be 0 for UBRRH) */






#endif /*</ USART_PRIVATE_H_*/

