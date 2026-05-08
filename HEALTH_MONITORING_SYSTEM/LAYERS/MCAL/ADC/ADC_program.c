/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  ADC_program.c            ****************/
/****************************************************************************/


/***************************<__INC_PART__>*********************** */

#include  "ADC_interface.h"
#include  "ADC_private.h"
#include  "ADC_config.h"

#include  "STD_types.h"
#include  "BIT_MATH.h"







ErrorState MCAL_ADC_init(void){

    ErrorState checkErrorState = OK ;

    /*SELECT THE REFRANCE VILTAGE*/
    #if REF_VOLTAGE == Internal_Voltage

    // set REFS0 & REFS1 @ ADMUX Register 
    SET_BIT(ADC_ADMUX,ADMUX_REFS0);
    SET_BIT(ADC_ADMUX,ADMUX_REFS1);

    #elif REF_VOLTAGE == AVCC_PIN
    // set REFS0 & clear REFS1 @ ADMUX Register 
    SET_BIT(ADC_ADMUX,ADMUX_REFS0);
    CLR_BIT(ADC_ADMUX,ADMUX_REFS1);

    #else 
    // Clear REFS0 & REFS1 @ ADMUX Register 
    CLR_BIT(ADC_ADMUX,ADMUX_REFS0);
    CLR_BIT(ADC_ADMUX,ADMUX_REFS1);

    #endif/*<_REF_VOLTAGE_*/


    /*SELECT THE ADC ADJUST*/
    #if ADC_ADJUST_RESULT == ADC_RIGHT_ADJUST 
    CLR_BIT(ADC_ADMUX,ADMUX_ADLAR);
    #else 
    SET_BIT(ADC_ADMUX,ADMUX_ADLAR);
    #endif/*<_ADC_ADJUST_RESULT_*/ 

    /*SELECT THE INPUT CLK*/
    /* Clear Prescaler Bits First */ 
    ADC_ADCSRA &= 0xF8;
    #if   ADC_FREQ == FOSC_DIV_2 
    #elif ADC_FREQ == FOSC_DIV_4
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS1); 
    #elif ADC_FREQ == FOSC_DIV_8
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS0); 
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS1); 
    #elif ADC_FREQ == FOSC_DIV_16
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS2);
    #elif ADC_FREQ == FOSC_DIV_32
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS0); 
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS2);
    #elif ADC_FREQ == FOSC_DIV_64
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS1); 
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS2); 
    #elif ADC_FREQ == FOSC_DIV_128
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS0); 
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS1); 
    SET_BIT(ADC_ADCSRA,ADCSRA_ADPS2);  
    #endif /*<_ADC_FREQ_*/ 

    /*ENABLE THE ADC*/
    SET_BIT(ADC_ADCSRA,ADCSRA_ADEN);

    /*RETURN STATE*/
     return checkErrorState;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState MCAL_ADC_getResult(uint_8 Copy_Channel , uint_16 *result){

    ErrorState checkErrorState = OK ;
    uint_32 Local_Timeout = 0;

    if(NULL == result){
      checkErrorState = NOK ;
    }else{
        //CLR _1st 5BITS
        ADC_ADMUX &= 0xE0;
        ADC_ADMUX |= (Copy_Channel & 0x1F);

        //Start Conversion
        SET_BIT(ADC_ADCSRA, ADCSRA_ADSC);

        //waiting untill finish conversion
        while(READ_BIT(ADC_ADCSRA, ADCSRA_ADIF) == 0 && (Local_Timeout < 10000)){
        Local_Timeout ++;
        }
        if(Local_Timeout>=10000){
          checkErrorState = NOK ;
        }else{

            //Clear Flag
            SET_BIT(ADC_ADCSRA, ADCSRA_ADIF);

            //Return Result
            *result = ADC_ADCL ;
            *result |= (ADC_ADCH<<8) ;
        }
   }
    
 return checkErrorState;

}