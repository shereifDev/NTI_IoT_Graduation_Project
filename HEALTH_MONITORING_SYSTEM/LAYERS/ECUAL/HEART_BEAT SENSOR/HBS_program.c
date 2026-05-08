/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     HBS_program.c            ****************** */


//*****************************<_INC_PART_>*************************** */

#include    "HBS_interface.h"
#include    "HBS_private.h"
#include    "HBS_config.h"

#include    "STD_TYPES.h"
#include    "BIT_MATH.h"




static volatile uint_16 timeBetweenPulses = 0;
static volatile uint_8  pulseCount = 0;
static volatile uint_16 bpmValue = 0;





static void ECUAL_HeartBeat_Callback(void) {
    if (pulseCount == 0) {
        MCAL_TIMER1_reset(); // Start counting from zero
        pulseCount = 1;
    } 
    else if (pulseCount == 1) {
        MCAL_TIMER1_getCounts(&timeBetweenPulses); // Read ticks
        MCAL_TIMER1_reset(); // Restart for next beat
        
        /* * Calculation:
         * Tick time = Prescaler / F_CPU = 64 / 8000000 = 0.000008 sec
         * Time (sec) = ticks * 0.000008
         * BPM = 60 / (Ticks * 0.000032)
         * To avoid float division in ISR, we simplify: 60 / 0.000008 = 7,500,000
         */
        if(timeBetweenPulses > 0) {
            bpmValue = (uint_16)(1875000UL / timeBetweenPulses);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_HeartBeat_init(void) {
    ErrorState checkErrorState = OK;
    
    //Initialize EXTI INT0
    MCAL_EXTI_initINT0();
    
    //Initialize Timer1
    MCAL_TIMER1_init();
    
    //Set the ISR Callback
    MCAL_EXTI_setCallBackINT0(ECUAL_HeartBeat_Callback);
    
    return checkErrorState;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_HeartBeat_getBPM(uint_16 *bpm) {
    ErrorState checkErrorState = OK;
    
    if (bpm != NULL) {
        *bpm = bpmValue;
    }else {
        checkErrorState = NOK;
    }
    
    return checkErrorState;
}