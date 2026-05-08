/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     LED_program.c          ****************** */



//*****************************<_INC_PART_>*************************** */

#include   "LED_interface.h"
#include   "LED_private.h"
#include   "LED_config.h"

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"




ErrorState  ECUAL_LED_intialize (LED_CNFG *led){
     
     ErrorState checkErrorState = OK ;
     GPIO_PIN_CNFG  led1 = {.GPIO_PORT = led -> port_name , .GPIO_PIN = led -> pin , .GPIO_LOGIC = GPIO_LOGIC_LOW , .GPIO_DIR = GPIO_OUTPUT};
     if(NULL == led){
         checkErrorState = NOK ;
     }else{
         
        checkErrorState = MCAL_DIO_setPinDir(&led1);
      
      }
     
  return checkErrorState;
 }

/////////////////////////////////////////////////////////////////////////////_____+_+///
 
ErrorState  ECUAL_LED_turn_on (LED_CNFG *led){
     
     ErrorState checkErrorState = OK ;
     GPIO_PIN_CNFG  led1 = {.GPIO_PORT = led -> port_name , .GPIO_PIN = led -> pin , .GPIO_LOGIC = GPIO_LOGIC_LOW , .GPIO_DIR = GPIO_OUTPUT};
     if(NULL == led){
         checkErrorState = NOK ;
     }else{
         
         switch(led -> connection){
             
             case LED_ACTIVE_HIGH :
                checkErrorState = MCAL_DIO_setPinValue(&led1,GPIO_LOGIC_HIGH);
                break;
                
             case LED_ACTIVE_LOW :
                checkErrorState = MCAL_DIO_setPinValue(&led1,GPIO_LOGIC_LOW);
                break;
                
             default:
                checkErrorState = NOK ;
        }
   
     }
     
  return checkErrorState;      
 }

/////////////////////////////////////////////////////////////////////////////_____+_+///
 
ErrorState  ECUAL_LED_turn_off (LED_CNFG *led){
     
     ErrorState checkErrorState = OK ;
     GPIO_PIN_CNFG  led1 = {.GPIO_PORT = led -> port_name , .GPIO_PIN = led -> pin , .GPIO_LOGIC = GPIO_LOGIC_LOW , .GPIO_DIR = GPIO_OUTPUT};
     if(NULL == led){
         checkErrorState = NOK ;
     }else{
         
         switch(led -> connection){
             
             case LED_ACTIVE_HIGH :
                checkErrorState = MCAL_DIO_setPinValue(&led1,GPIO_LOGIC_LOW);
                break;
                
             case LED_ACTIVE_LOW :
                checkErrorState = MCAL_DIO_setPinValue(&led1,GPIO_LOGIC_HIGH);
                break;
                
             default:
                checkErrorState = NOK ;
        }
   
     }
     
  return checkErrorState;  
 }

/////////////////////////////////////////////////////////////////////////////_____+_+///
 
ErrorState  ECUAL_LED_toggle (LED_CNFG *led){
     
     ErrorState checkErrorState = OK ;
     GPIO_PIN_CNFG  led1 = {.GPIO_PORT = led -> port_name , .GPIO_PIN = led -> pin , .GPIO_LOGIC = GPIO_LOGIC_LOW , .GPIO_DIR = GPIO_OUTPUT};
     if(NULL == led){
         checkErrorState = NOK ;
     }else{
         
        checkErrorState = MCAL_DIO_toggilePinLogic(&led1) ; 
    }
     
  return checkErrorState; 
 }








