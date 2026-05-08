/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  EXTI_private.h           ****************/
/****************************************************************************/




#ifndef   EXTI_PRIVATE_H_
#define   EXTI_PRIVATE_H_


/**************************<EXTI Registers Definitions>******************/                             

/* MCU Control Register - Used for INT0 and INT1 Sense Control */
#define MCUCR       *((volatile uint_8*) 0x55)

/* MCU Control and Status Register - Used for INT2 Sense Control */
#define MCUCSR      *((volatile uint_8*) 0x54)

/* General Interrupt Control Register - Used to Enable/Disable INT0, INT1, INT2 */
#define GICR        *((volatile uint_8*) 0x5B)

/* General Interrupt Flag Register - Contains Interrupt Flags */
#define GIFR        *((volatile uint_8*) 0x5A)

/* Status Register - Global Interrupt Enable Bit (I-Bit) is here */
#define SREG        *((volatile uint_8*) 0x5F)


/*********************** *</ EXTI Bits Definitions>**********************/


/* MCUCR Bits */
#define ISC00       0       /* Interrupt Sense Control 0 Bit 0 */
#define ISC01       1       /* Interrupt Sense Control 0 Bit 1 */
#define ISC10       2       /* Interrupt Sense Control 1 Bit 0 */
#define ISC11       3       /* Interrupt Sense Control 1 Bit 1 */

/* MCUCSR Bits */
#define ISC2        6       /* Interrupt Sense Control 2 */

/* GICR Bits */
#define INT2        5       /* External Interrupt Request 2 Enable */
#define INT0        6       /* External Interrupt Request 0 Enable */
#define INT1        7       /* External Interrupt Request 1 Enable */

/* GIFR Bits */
#define INTF2       5       /* External Interrupt Flag 2 */
#define INTF0       6       /* External Interrupt Flag 0 */
#define INTF1       7       /* External Interrupt Flag 1 */

/* SREG Bits */
#define I_BIT       7       /* Global Interrupt Enable Bit */



#endif /*<EXTI_PRIVATE_H_*/

