/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  EXTI_program.c           ****************/
/****************************************************************************/


/***************************<__INC_PART__>*********************** */

#include  "EXTI_interface.h"
#include  "EXTI_private.h"
#include  "EXTI_config.h"

#include  "STD_types.h"
#include  "BIT_MATH.h"





void (*EXTI_INT0_CallBack)(void) = NULL ;



ErrorState MCAL_EXTI_initINT0(void) {

    ErrorState checkErrorState = OK ;
    //Set INT0 to work with Rising Edge (MCUCR Register)
    SET_BIT(MCUCR, ISC00);
    SET_BIT(MCUCR, ISC01);
    
    //Enable Peripheral Interrupt 
    SET_BIT(GICR, INT0);
    
    //Enable Global Interrupt
    SET_BIT(SREG, I_BIT); 

    return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState MCAL_EXTI_setCallBackINT0(void (*ptrToFunc)(void)) {
    ErrorState checkErrorState = OK;
    if (ptrToFunc != NULL) {
        EXTI_INT0_CallBack = ptrToFunc;
    }else {
        checkErrorState = NOK;
    }

    return checkErrorState;
}

/////////////////////////////////////////////////////////////////////////////_____+_+///

// ISR for INT0
void __vector_1 (void) __attribute__ ((signal));
void __vector_1 (void) {
    if(EXTI_INT0_CallBack != NULL) {
        EXTI_INT0_CallBack();
    }
}



