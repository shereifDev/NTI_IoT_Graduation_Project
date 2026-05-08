/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     DIO_program.c             ****************** */



//*****************************<_INC_PART_>*************************** */

#include "DIO_interface.h"
#include "DIO_private.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"





ErrorState MCAL_DIO_setPinDir(GPIO_PIN_CNFG*ptr){

    ErrorState checkErrorState = OK ;

    if((NULL == ptr) || (ptr->GPIO_PORT > MAX_PORT_NUM) || (ptr->GPIO_PIN > MAX_PIN_NUM) || (ptr->GPIO_DIR > DIR_TWO_CHOICE)){
      checkErrorState = NOK  ;
    }else {

    switch (ptr->GPIO_PORT){

        case GPIO_PORTA:
        if(ptr->GPIO_DIR == GPIO_OUTPUT) SET_BIT(DIO_DDRA,ptr->GPIO_PIN);
        else  CLR_BIT(DIO_DDRA,ptr->GPIO_PIN);
        break;

        case GPIO_PORTB:
        if(ptr->GPIO_DIR == GPIO_OUTPUT) SET_BIT(DIO_DDRB,ptr->GPIO_PIN);
        else  CLR_BIT(DIO_DDRB,ptr->GPIO_PIN);
        break;

        case GPIO_PORTC:
        if(ptr->GPIO_DIR == GPIO_OUTPUT) SET_BIT(DIO_DDRC,ptr->GPIO_PIN);
        else  CLR_BIT(DIO_DDRC,ptr->GPIO_PIN);
        break;

        case GPIO_PORTD:
        if(ptr->GPIO_DIR == GPIO_OUTPUT) SET_BIT(DIO_DDRD,ptr->GPIO_PIN);
        else  CLR_BIT(DIO_DDRD,ptr->GPIO_PIN);
        break;

        default:
        /*NO THING*/
        break;
    }
}

return  checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState MCAL_DIO_setPinValue(GPIO_PIN_CNFG*ptr,uint_8 logic){

ErrorState checkErrorState = OK ;
if( (NULL == ptr) || (ptr->GPIO_PORT > MAX_PORT_NUM) ||  (ptr->GPIO_PIN >MAX_PIN_NUM)){
    checkErrorState = NOK ;
}else{
    switch (ptr->GPIO_PORT){

        case GPIO_PORTA:
        if(logic == GPIO_LOGIC_HIGH) SET_BIT(DIO_PORTA,ptr->GPIO_PIN);
        else CLR_BIT(DIO_PORTA,ptr->GPIO_PIN);
        break;

        case GPIO_PORTB:
        if(logic == GPIO_LOGIC_HIGH) SET_BIT(DIO_PORTB,ptr->GPIO_PIN);
        else CLR_BIT(DIO_PORTB,ptr->GPIO_PIN);
        break;

        case GPIO_PORTC:
        if(logic == GPIO_LOGIC_HIGH) SET_BIT(DIO_PORTC,ptr->GPIO_PIN);
        else CLR_BIT(DIO_PORTC,ptr->GPIO_PIN);
        break;

        case GPIO_PORTD:
        if(logic == GPIO_LOGIC_HIGH) SET_BIT(DIO_PORTD,ptr->GPIO_PIN);
        else CLR_BIT(DIO_PORTD,ptr->GPIO_PIN);
        break;
    
    
        default:
        /*NO THING*/
        break;
    }
}

return checkErrorState ;

}



/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState MCAL_DIO_readPinLogic(GPIO_PIN_CNFG*ptr,unsigned char *pinVal){

    
    ErrorState  checkErrorState = OK ;
    if((NULL == ptr) || (ptr->GPIO_PORT > MAX_PORT_NUM) || (ptr->GPIO_PIN > MAX_PIN_NUM)){
      checkErrorState = NOK  ;
    }else {

        switch (ptr->GPIO_PORT)
        {
            case GPIO_PORTA:
                *pinVal = READ_BIT(DIO_PINA,ptr->GPIO_PIN);
                break;
            
            case GPIO_PORTB:
                 *pinVal = READ_BIT(DIO_PINB,ptr->GPIO_PIN);
                break;
            case GPIO_PORTC:
                 *pinVal = READ_BIT(DIO_PINC,ptr->GPIO_PIN);
                break;
                
            case GPIO_PORTD:
                 *pinVal = READ_BIT(DIO_PIND,ptr->GPIO_PIN);
            break;
            

            default:
            /*NO THING*/
            break;
        }

    }
    
return checkErrorState ;
}

/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState MCAL_DIO_toggilePinLogic(GPIO_PIN_CNFG*ptr){

    unsigned char  checkErrorState = OK ;

    if(NULL == ptr || ptr->GPIO_PORT > MAX_PORT_NUM || ptr->GPIO_PIN > MAX_PIN_NUM){
      checkErrorState = NOK  ;
    }else{

        switch (ptr->GPIO_PORT){
            case GPIO_PORTA:
                TOGGLE_BIT(DIO_PORTA,ptr->GPIO_PIN);
                break;
            
            case GPIO_PORTB:
                TOGGLE_BIT(DIO_PORTB,ptr->GPIO_PIN);
                break;

            case GPIO_PORTC:
                TOGGLE_BIT(DIO_PORTC,ptr->GPIO_PIN);
                break;
                
            case GPIO_PORTD:
                TOGGLE_BIT(DIO_PORTD,ptr->GPIO_PIN);
            break;
            

            default:
            break;
        }

    }

return checkErrorState ;

}

/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState MCAL_DIO_setPortDir(unsigned char copy_port , unsigned char copy_dir){

 unsigned char  checkErrorState = OK ;

 if(copy_port > MAX_PORT_NUM ){
  checkErrorState = NOK ;
 }
   switch (copy_port ){

    case GPIO_PORTA:
    DIO_DDRA = copy_dir;
    break;

    case GPIO_PORTB:
    DIO_DDRB = copy_dir;
    break;


    case GPIO_PORTC:
    DIO_DDRC = copy_dir;
    break;
 

    case GPIO_PORTD:
    DIO_DDRD = copy_dir;
    break;
 
 
   default:
     /*NO THING*/
    break;
 }

 return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState MCAL_DIO_setPortVal(unsigned char copy_port , unsigned char copy_val){

 unsigned char  checkErrorState = OK ;

 if(copy_port > MAX_PORT_NUM ){
  checkErrorState = NOK ;
 }
   switch (copy_port ){

    case GPIO_PORTA:
    DIO_PORTA = copy_val;
    break;

    case GPIO_PORTB:
    DIO_PORTB = copy_val;
    break;


    case GPIO_PORTC:
    DIO_PORTC = copy_val;
    break;
 

     case GPIO_PORTD:
    DIO_PORTD = copy_val;
    break;
 
 
   default:
     /*NO THING*/
    break;
 }

 return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState MCAL_DIO_readPortLogic(unsigned char copy_port,unsigned char *PinVal){

 unsigned char  checkErrorState = OK ;

 if(copy_port > MAX_PORT_NUM ){
  checkErrorState = NOK ;
 }else{

    switch (copy_port)
    {
        case GPIO_PORTA :
            *PinVal = DIO_PINA ;
            break;
        
        case GPIO_PORTB :
        *PinVal = DIO_PINB ;
        break;
    
        case GPIO_PORTC :
        *PinVal = DIO_PINC ;
        break;
    

        case GPIO_PORTD :
        *PinVal = DIO_PIND ;
        break;
    
       default:
       /*NO THING*/
        break;
    }

 }

return checkErrorState ;

}

/////////////////////////////////////////////////////////////////////////////_____+_+///

  

ErrorState MCAL_DIO_toggilePortLogic(unsigned char copy_port){

    unsigned char checkErrorState = OK ;

    if(copy_port > MAX_PORT_NUM ){
        checkErrorState = NOK ;
    }else{
        switch (copy_port)
        {
            case GPIO_PORTA :
                DIO_PORTA = ~DIO_PORTA ;
                break;
            case GPIO_PORTB :
                DIO_PORTB = ~DIO_PORTB ;
                break;
            case GPIO_PORTC :
                DIO_PORTC = ~DIO_PORTC ;
                break;
            case GPIO_PORTD :
                DIO_PORTD = ~DIO_PORTD ;
                break;
            default:
                break;
        }
    }
    
    return checkErrorState ;
}