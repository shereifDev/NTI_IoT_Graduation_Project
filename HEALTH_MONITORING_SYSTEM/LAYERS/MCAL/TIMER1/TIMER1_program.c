/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  TIMER1_program.c         ****************/
/****************************************************************************/


/***************************<__INC_PART__>*********************** */

#include  "TIMER1_interface.h"
#include  "TIMER1_private.h"
#include  "TIMER1_config.h"

#include  "STD_types.h"
#include  "BIT_MATH.h"






ErrorState MCAL_TIMER1_init(void) {

    ErrorState checkErrorState = OK ;
    TCCR1A = 0x00; 
    TCCR1B &= 0xE0; 
    // SET_BIT(TCCR1B, CS11);
    // SET_BIT(TCCR1B, CS10);
    SET_BIT(TCCR1B, CS12);
    TCNT1 = 0 ;
    
    return checkErrorState; 
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState MCAL_TIMER1_reset(void) {
    ErrorState checkErrorState = OK ;
    TCNT1 = 0;
    return  checkErrorState = OK ;;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState MCAL_TIMER1_getCounts(uint_16 *ptrToCounts) {

    ErrorState checkErrorState = OK;
    
    if (ptrToCounts == NULL) {
       checkErrorState = NOK ;
    }else {
         *ptrToCounts = TCNT1;
    }
    
    return checkErrorState ;
}