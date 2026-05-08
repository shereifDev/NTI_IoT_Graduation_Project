/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  ADC_private.h            ****************/
/****************************************************************************/




#ifndef    ADC_PRIVATE_H_
#define    ADC_PRIVATE_H_


/************************ADC_Registers_Definitions*******************/

#define     ADC_BASE_ADDRESS                  0x24

#define     ADC_ADCL        (*(volatile unsigned char *)(ADC_BASE_ADDRESS+0))
#define     ADC_ADCH        (*(volatile unsigned char *)(ADC_BASE_ADDRESS+1))
#define     ADC_ADCSRA      (*(volatile unsigned char *)(ADC_BASE_ADDRESS+2))
#define     ADC_ADMUX       (*(volatile unsigned char *)(ADC_BASE_ADDRESS+3))


/*****************************ADMUX_BITS****************************/

typedef enum {

    ADMUX_MUX0    ,
    ADMUX_MUX1    ,
    ADMUX_MUX2    ,
    ADMUX_MUX3    ,
    ADMUX_MUX4    ,
    ADMUX_ADLAR   ,
    ADMUX_REFS0   ,
    ADMUX_REFS1

}ADC_ADMUX_BITS;


/*****************************ADCSRA_BITS******************** */

typedef enum {

    ADCSRA_ADPS0  ,
    ADCSRA_ADPS1  ,
    ADCSRA_ADPS2  ,
    ADCSRA_ADIE   ,
    ADCSRA_ADIF   ,
    ADCSRA_ADATE  ,
    ADCSRA_ADSC   ,
    ADCSRA_ADEN   

}ADC_ADCSRA_BITS;




/* --- ADC Reference Voltage Options --- */
#define    AREF_PIN             0
#define    AVCC_PIN             1
#define    Internal_Voltage     2




/* --- ADC Result Adjustment Options --- */
#define    ADC_RIGHT_ADJUST     0
#define    ADC_LEFT_ADJUST      1



/* --- ADC Prescaler (Clock Divider) Options --- */
#define    FOSC_DIV_2           1
#define    FOSC_DIV_4           2
#define    FOSC_DIV_8           3
#define    FOSC_DIV_16          4
#define    FOSC_DIV_32          5
#define    FOSC_DIV_64          6
#define    FOSC_DIV_128         7




/* --- ADC Conversion Mode Options --- */
#define    SINGLE_CONV_MODE     0
#define    AUTO_TRIGGERING_MODE 1



#endif /*<ADC_PRIVATE_H_*/
