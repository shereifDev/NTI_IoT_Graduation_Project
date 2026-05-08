/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     BUZZER_program.c          ****************** */




//*****************************<_INC_PART_>*************************** */


#include   "BUZZER_interface.h"
#include   "BUZZER_private.h"
#include   "BUZZER_config.h"

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"





 ErrorState ECUAL_BUZZER_initialize (BUZZER_CNFG *ptr){
     
    ErrorState checkErrorState = OK ;
    GPIO_PIN_CNFG ptr1 = {.GPIO_PORT = ptr -> port , .GPIO_PIN = ptr -> pin , .GPIO_LOGIC = GPIO_LOGIC_LOW , .GPIO_DIR = GPIO_OUTPUT};
     if(NULL == ptr){
         checkErrorState =NOK;
     }else{
         
        checkErrorState = MCAL_DIO_setPinDir(&ptr1);
      
      }
     
  return checkErrorState; 
 }
 
/////////////////////////////////////////////////////////////////////////////_____+_+///

 
 ErrorState ECUAL_BUZZER_turn_on (BUZZER_CNFG *ptr){
     
          
     ErrorState checkErrorState = OK ;
     GPIO_PIN_CNFG ptr1 = {.GPIO_PORT = ptr -> port , .GPIO_PIN = ptr -> pin , .GPIO_LOGIC = GPIO_LOGIC_LOW , .GPIO_DIR = GPIO_OUTPUT};
     if(NULL == ptr){
         checkErrorState =NOK;
     }else{
         
        checkErrorState = MCAL_DIO_setPinValue(&ptr1,GPIO_LOGIC_HIGH);
    }
     
  return checkErrorState; 
     
 }

 
/////////////////////////////////////////////////////////////////////////////_____+_+///

 
 ErrorState ECUAL_BUZZER_turn_off (BUZZER_CNFG *ptr){
     
     ErrorState checkErrorState = OK ;
     GPIO_PIN_CNFG ptr1 = {.GPIO_PORT = ptr -> port , .GPIO_PIN = ptr -> pin , .GPIO_LOGIC = GPIO_LOGIC_LOW , .GPIO_DIR = GPIO_OUTPUT};
     if(NULL == ptr){
         checkErrorState =NOK;
     }else{
         
        checkErrorState = MCAL_DIO_setPinValue(&ptr1,GPIO_LOGIC_LOW);
      
      }
     
  return checkErrorState; 
    
 }


/////////////////////////////////////////////////////////////////////////////_____+_+///

 
 ErrorState ECUAL_BUZZER_toggle (BUZZER_CNFG *ptr){
     
          
     ErrorState checkErrorState = OK ;
     GPIO_PIN_CNFG ptr1 = {.GPIO_PORT = ptr -> port , .GPIO_PIN = ptr -> pin , .GPIO_LOGIC = GPIO_LOGIC_LOW , .GPIO_DIR = GPIO_OUTPUT};
     if(NULL == ptr){
         checkErrorState =NOK;
     }else{
         
        checkErrorState = MCAL_DIO_toggilePinLogic(&ptr1);
      
      }
     
  return checkErrorState; 
     
 }