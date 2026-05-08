/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     CLCD_program.c            ****************** */


//*****************************<_INC_PART_>*************************** */

#include    "CLCD_interface.h"
#include    "CLCD_private.h"
#include    "CLCD_config.h"

#include    "STD_TYPES.h"
#include    "BIT_MATH.h"

#include <stdio.h>   
#include <string.h>  

#define      F_CPU      8000000UL
#include     <util/delay.h>
   




ErrorState ECUAL_CLCD_4bit_intialize( CLCD_4BIT_CONFG *lcd_obj){

    ErrorState checkErrorState = OK;
    uint_8 lcd_4bit_intialize_count = ZERO;
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
        checkErrorState = MCAL_DIO_setPinDir(&(lcd_obj ->lcd_rs));
        checkErrorState = MCAL_DIO_setPinDir(&(lcd_obj ->lcd_en));
        
        for(lcd_4bit_intialize_count = 0 ; lcd_4bit_intialize_count < 4 ; lcd_4bit_intialize_count++){

            checkErrorState = MCAL_DIO_setPinDir(&(lcd_obj ->lcd_data[lcd_4bit_intialize_count]));
        } 

         _delay_ms(20);
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_8BIT_MODE_2LINE);
        _delay_ms(5);
         checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_8BIT_MODE_2LINE);
        _delay_us(150);
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_8BIT_MODE_2LINE);
        
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_CLEAR);
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_RETURN_HOME);
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_ENTRY_MODE);
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_CURSOR_OFF_DISPLAY_ON);
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_4BIT_MODE_2LINE); 
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_DDRAM_START);
    }
    
 return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_CLCD_4bit_send_command( CLCD_4BIT_CONFG *lcd_obj, uint_8 command){
    ErrorState checkErrorState = OK;
    
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
         checkErrorState = MCAL_DIO_setPinValue(&(lcd_obj ->lcd_rs),LOW);
         checkErrorState = ECUAL_CLCD_send_4bits(lcd_obj, command >> 4);
         checkErrorState = ECUAL_CLCD_4bit_send_enable_signal(lcd_obj);
         checkErrorState = ECUAL_CLCD_send_4bits(lcd_obj, command);
         checkErrorState = ECUAL_CLCD_4bit_send_enable_signal(lcd_obj);
         
    }
    
  return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState ECUAL_CLCD_4bit_send_char_data( CLCD_4BIT_CONFG *lcd_obj, uint_8 data){
    ErrorState checkErrorState = OK;
    
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
         checkErrorState = MCAL_DIO_setPinValue(&(lcd_obj ->lcd_rs),HIGH);
         checkErrorState = ECUAL_CLCD_send_4bits(lcd_obj, data >> 4);
         checkErrorState = ECUAL_CLCD_4bit_send_enable_signal(lcd_obj);
         checkErrorState = ECUAL_CLCD_send_4bits(lcd_obj, data);
         checkErrorState = ECUAL_CLCD_4bit_send_enable_signal(lcd_obj);
    }
    
 return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_CLCD_4bit_send_char_data_pos( CLCD_4BIT_CONFG *lcd_obj, uint_8 row, uint_8 column, uint_8 data){

    ErrorState checkErrorState = OK;
    
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
        checkErrorState = ECUAL_CLCD_4bit_set_cursor(lcd_obj, row, column);
        checkErrorState = ECUAL_CLCD_4bit_send_char_data(lcd_obj,data);
    }
    
  return checkErrorState ;
}



/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState ECUAL_CLCD_4bit_send_string( CLCD_4BIT_CONFG *lcd_obj, uint_8 *str){

    ErrorState checkErrorState = OK;
    
    if((NULL == lcd_obj) || (NULL == str)){
        checkErrorState = NOK;
    }else{
        while(*str){
            checkErrorState = ECUAL_CLCD_4bit_send_char_data(lcd_obj,*str++);
        }
    }
    
  return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_LCD_4bit_send_string_pos( CLCD_4BIT_CONFG *lcd_obj, uint_8 row, uint_8 column, uint_8*str){

    ErrorState checkErrorState = OK;
    
    if((NULL == lcd_obj) || (NULL == str)){
        checkErrorState = NOK;
    }else{
        checkErrorState = ECUAL_CLCD_4bit_set_cursor(lcd_obj, row, column);
        while(*str){
            checkErrorState = ECUAL_CLCD_4bit_send_char_data(lcd_obj,*str++);
        }
    }
    
  return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_LCD_4bit_send_custom_char( CLCD_4BIT_CONFG *lcd_obj,uint_8 row, uint_8 column, const uint_8 chr[], uint_8 mem_pos){

    ErrorState checkErrorState = OK;
    uint_8 lcd_counter = ZERO;
    
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, (_LCD_CGGRAM_START + (mem_pos * 8)));
        for(lcd_counter=0 ; lcd_counter<COLUMN_8; lcd_counter++){
            checkErrorState = ECUAL_CLCD_4bit_send_char_data(lcd_obj, chr[lcd_counter]);
        }
        checkErrorState = ECUAL_CLCD_4bit_send_char_data_pos(lcd_obj, row, column, mem_pos);
    }
    
  return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_CLCD_8bit_intialize( CLCD_8BIT_CONFG *lcd_obj){

    ErrorState checkErrorState = OK;
    uint_8 lcd_4bit_intialize_count = ZERO;
    
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
        checkErrorState = MCAL_DIO_setPinDir(&(lcd_obj ->lcd_rs));
        checkErrorState = MCAL_DIO_setPinDir(&(lcd_obj ->lcd_en));
        
        for(lcd_4bit_intialize_count=0 ; lcd_4bit_intialize_count<8 ; lcd_4bit_intialize_count++){

            checkErrorState = MCAL_DIO_setPinDir(&(lcd_obj ->lcd_data[lcd_4bit_intialize_count]));
        } 
        
        _delay_ms(20);
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_8BIT_MODE_2LINE);
        _delay_ms(5);
         checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_8BIT_MODE_2LINE);
        _delay_us(150);
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_8BIT_MODE_2LINE);
         
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_CLEAR );
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_RETURN_HOME   );
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_ENTRY_MODE );
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_CURSOR_OFF_DISPLAY_ON );
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_8BIT_MODE_2LINE); 
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, _LCD_DDRAM_START );
        
    }

 return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_CLCD_8bit_send_command( CLCD_8BIT_CONFG *lcd_obj,uint_8 command){

    ErrorState checkErrorState = OK;
    uint_8 l_lcd_8bit_command = ZERO;
    
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
        checkErrorState = MCAL_DIO_setPinValue(&(lcd_obj ->lcd_rs),LOW);
        for(l_lcd_8bit_command = ZERO ; l_lcd_8bit_command<8 ; l_lcd_8bit_command++){

            checkErrorState = MCAL_DIO_setPinValue( &(lcd_obj ->lcd_data[l_lcd_8bit_command]), ( (command >> l_lcd_8bit_command) & (uint_8)(0x01) ) );
        }
        checkErrorState = ECUAL_CLCD_8bit_send_enable_signal(lcd_obj);
    }
    
return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_CLCD_8bit_send_char_data( CLCD_8BIT_CONFG *lcd_obj,uint_8 data){
    ErrorState checkErrorState = OK;
    uint_8 l_lcd_8bit_data = ZERO;
    
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
        checkErrorState = MCAL_DIO_setPinValue(&(lcd_obj ->lcd_rs),HIGH);
        
        for(l_lcd_8bit_data = ZERO ; l_lcd_8bit_data <COLUMN_8 ; l_lcd_8bit_data ++){
            checkErrorState = MCAL_DIO_setPinValue( &(lcd_obj ->lcd_data[l_lcd_8bit_data ]), ( (data >> l_lcd_8bit_data ) & (uint_8)(0x01) ) );
        }
        
        checkErrorState = ECUAL_CLCD_8bit_send_enable_signal(lcd_obj);
    }
    
  return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState ECUAL_CLCD_8bit_send_char_data_pos( CLCD_8BIT_CONFG *lcd_obj,uint_8 row,uint_8 column,uint_8 data){

    ErrorState checkErrorState = OK;
    
    if((NULL == lcd_obj)){
        checkErrorState = NOK;
    }else{
        checkErrorState = ECUAL_CLCD_8bit_set_cursor(lcd_obj, row, column);
        checkErrorState = ECUAL_CLCD_8bit_send_char_data(lcd_obj,data);
    }
    
 return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_LCD_8bit_send_string( CLCD_8BIT_CONFG *lcd_obj,uint_8*str){
    ErrorState checkErrorState = OK;
    
    if((NULL == lcd_obj) || (NULL == str)){
        checkErrorState = NOK;
    }else{
        while(*str){
            checkErrorState = ECUAL_CLCD_8bit_send_char_data(lcd_obj, *str++);
        }
    }
    
  return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_CLCD_8bit_send_string_pos( CLCD_8BIT_CONFG *lcd_obj, uint_8 row, uint_8 column, uint_8*str){

    ErrorState checkErrorState = OK;
    
    if((NULL == lcd_obj) || (NULL == str)){
        checkErrorState = NOK;
    }else{
        checkErrorState = ECUAL_CLCD_8bit_set_cursor(lcd_obj, row, column);
        while(*str){
            checkErrorState = ECUAL_CLCD_8bit_send_char_data(lcd_obj, *str++);
        }
    }
    
  return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_CLCD_8bit_send_custom_char( CLCD_8BIT_CONFG *lcd_obj,uint_8 row, uint_8 column,  uint_8 chr[], uint_8 mem_pos){

    ErrorState checkErrorState = OK;
    uint_8 lcd_counter = ZERO;
    
    if(NULL == lcd_obj){
        checkErrorState = NOK;
    }else{
        checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj, (_LCD_CGGRAM_START + (mem_pos * 8)));
        for(lcd_counter=0 ; lcd_counter<COLUMN_8; lcd_counter++){
            checkErrorState = ECUAL_CLCD_8bit_send_char_data(lcd_obj, chr[lcd_counter]);
        }
        checkErrorState = ECUAL_CLCD_8bit_send_char_data_pos(lcd_obj, row, column, mem_pos);
    }
    
  return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState convert_byte_to_string(uint_8 value, uint_8 *str){

    ErrorState checkErrorState = OK;
    
    if((NULL == str)){
        checkErrorState = NOK;
    }else{
        memset(str, '\0', 4);
        sprintf(str, "%i", value);
    }
    
return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState convert_int_to_string(uint_32 value, uint_8 *str){

    ErrorState checkErrorState = OK;
    
    if((NULL == str)){
        checkErrorState = NOK;
    }else{
        memset(str, '\0', 11);
        sprintf(str,"%lu", value);
    }
    
 return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


static ErrorState ECUAL_CLCD_send_4bits( CLCD_4BIT_CONFG *lcd_obj, uint_8 data_command){

    ErrorState checkErrorState = OK;
    
    if((NULL == lcd_obj)){
        checkErrorState = NOK;
    }else{
        checkErrorState = MCAL_DIO_setPinValue( &(lcd_obj ->lcd_data[0]),( (data_command >> 0) & (uint_8)(0x01) ) );
        checkErrorState = MCAL_DIO_setPinValue( &(lcd_obj ->lcd_data[1]),( (data_command >> 1) & (uint_8)(0x01) ) );
        checkErrorState = MCAL_DIO_setPinValue( &(lcd_obj ->lcd_data[2]),( (data_command >> 2) & (uint_8)(0x01) ) );
        checkErrorState = MCAL_DIO_setPinValue( &(lcd_obj ->lcd_data[3]),( (data_command >> 3) & (uint_8)(0x01) ) );
    }

 return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


static ErrorState ECUAL_CLCD_4bit_send_enable_signal( CLCD_4BIT_CONFG *lcd_obj){

     ErrorState checkErrorState = OK;
    
    if((NULL == lcd_obj)){
        checkErrorState = NOK;
    }else{
        checkErrorState = MCAL_DIO_setPinValue(&(lcd_obj ->lcd_en), HIGH);
        _delay_ms(2);
         checkErrorState = MCAL_DIO_setPinValue(&(lcd_obj ->lcd_en), LOW);
        _delay_ms(2);

    }

  return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


static ErrorState ECUAL_CLCD_8bit_send_enable_signal( CLCD_8BIT_CONFG *lcd_obj){

    ErrorState checkErrorState = OK;
    
    if((NULL == lcd_obj)){
        checkErrorState = NOK;
    }else{
        checkErrorState  = MCAL_DIO_setPinValue(&(lcd_obj ->lcd_en), HIGH);
        _delay_ms(2);
         checkErrorState = MCAL_DIO_setPinValue(&(lcd_obj ->lcd_en), LOW);
        _delay_ms(2);

    }

 return checkErrorState ;

}

/////////////////////////////////////////////////////////////////////////////_____+_+///


static ErrorState ECUAL_CLCD_8bit_set_cursor( CLCD_8BIT_CONFG *lcd_obj, uint_8 row, uint_8 column){

    ErrorState checkErrorState = OK;
    
    column--;
    if((NULL == lcd_obj)){

        checkErrorState = NOK;
    }
    else{
        switch(row){
            case ROW1 :
                checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj,0x80+column);
                break;
            case ROW2 :
                 checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj,0xc0+column);
                break;
            case ROW3 :
                 checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj,0x94+column);
                break;
            case ROW4 :
                 checkErrorState = ECUAL_CLCD_8bit_send_command(lcd_obj,0xd4+column);
                break;
            default : 
                break;
        }
    }

 return checkErrorState ;
}


/////////////////////////////////////////////////////////////////////////////_____+_+///


static ErrorState ECUAL_CLCD_4bit_set_cursor( CLCD_4BIT_CONFG *lcd_obj, uint_8 row, uint_8 column){

    ErrorState checkErrorState = OK;
    
    column--;
    if((NULL == lcd_obj)){
        checkErrorState = NOK;
    }else{
        switch(row){
            case ROW1 :
                checkErrorState  = ECUAL_CLCD_4bit_send_command(lcd_obj,0x80+column);
                break;
            case ROW2 :
                 checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj,0xc0+column);
                break;
            case ROW3 :
                 checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj,0x94+column);
                break;
            case ROW4 :
                 checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj,0xd4+column);
                break;
            default : 
                break;
        }
    }

 return checkErrorState ;

}


/////////////////////////////////////////////////////////////////////////////_____+_+///


ErrorState ECUAL_CLCD_4bit_clear(CLCD_4BIT_CONFG *lcd_obj) {
    
    ErrorState checkErrorState = OK;

    if (NULL == lcd_obj) {
        checkErrorState = NOK;
    } else {
        
        checkErrorState = ECUAL_CLCD_4bit_send_command(lcd_obj, _LCD_CLEAR);
        _delay_ms(2); 
    }

    return checkErrorState;
}