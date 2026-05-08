/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  TIMER1_private.h         ****************/
/****************************************************************************/




#ifndef   TIMER1_PRIVATE_H_
#define   TIMER1_PRIVATE_H_




/* Timer/Counter1 Control Register A */
#define TCCR1A      *((volatile uint_8*) 0x4F)

/* Timer/Counter1 Control Register B */
#define TCCR1B      *((volatile uint_8*) 0x4E)

/* Timer/Counter1 Register (16-bit)  */
#define TCNT1       *((volatile uint_16*) 0x4C)

/* Timer/Counter1 Output Compare Register A */
#define OCR1A       *((volatile uint_16*) 0x4A)

/* Timer Interrupt Mask Register */
#define TIMSK       *((volatile uint_8*) 0x59)

/* Timer Interrupt Flag Register */
#define TIFR        *((volatile uint_8*) 0x58)



/* TCCR1B Bits (For Prescaler) */
#define CS10        0
#define CS11        1
#define CS12        2


#endif /*<TIMER1_PRIVATE_H_*/

