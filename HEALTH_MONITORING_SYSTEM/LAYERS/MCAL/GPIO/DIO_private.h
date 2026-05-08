/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     DIO_private.h             ****************** */



#ifndef        DIO_PRIVATE_H
#define        DIO_PRIVATE_H


/********************<PORTA REGISTERS DEFINTIONS>************************* */

#define             DIO_DDRA          (*(volatile unsigned char*)0x3A)
#define             DIO_PORTA         (*(volatile unsigned char*)0x3B)
#define             DIO_PINA          (*(volatile unsigned char*)0x39)

/********************<PORTB REGISTERS DEFINTIONS>************************* */

#define             DIO_DDRB          (*(volatile unsigned char*)0x37)
#define             DIO_PORTB         (*(volatile unsigned char*)0x38)
#define             DIO_PINB          (*(volatile unsigned char*)0x36)


/********************<PORTC REGISTERS DEFINTIONS>************************* */

#define             DIO_DDRC          (*(volatile unsigned char*)0x34)
#define             DIO_PORTC         (*(volatile unsigned char*)0x35)
#define             DIO_PINC          (*(volatile unsigned char*)0x33)

/********************<PORTD REGISTERS DEFINTIONS>************************* */

#define             DIO_DDRD          (*(volatile unsigned char*)0x31)
#define             DIO_PORTD         (*(volatile unsigned char*)0x32)
#define             DIO_PIND          (*(volatile unsigned char*)0x30)

#endif /*< DIO_PRIVATE_H*/