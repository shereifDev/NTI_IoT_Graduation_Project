/*
 * main.c
 *  Author: NTI
 */ 


#include "APP.h"

CLCD_4BIT_CONFG LCD = {
	
	.lcd_rs.GPIO_PORT       =    GPIO_PORTC               ,
	.lcd_rs.GPIO_PIN        =    GPIO_PIN0                ,
	.lcd_rs.GPIO_LOGIC      =    GPIO_LOGIC_LOW           ,
	.lcd_rs.GPIO_DIR        =    GPIO_OUTPUT              ,	
	
	.lcd_en.GPIO_PORT       =    GPIO_PORTC               ,
	.lcd_en.GPIO_PIN        =    GPIO_PIN1                ,
	.lcd_en.GPIO_LOGIC      =    GPIO_LOGIC_LOW           ,
	.lcd_en.GPIO_DIR        =    GPIO_OUTPUT              ,
	
	.lcd_data[0].GPIO_PORT  =    GPIO_PORTC               ,
	.lcd_data[0].GPIO_PIN   =    GPIO_PIN2                ,
	.lcd_data[0].GPIO_LOGIC =    GPIO_LOGIC_LOW           ,
	.lcd_data[0].GPIO_DIR   =    GPIO_OUTPUT              ,
	
	.lcd_data[1].GPIO_PORT  =    GPIO_PORTC               ,
	.lcd_data[1].GPIO_PIN   =    GPIO_PIN3                ,
	.lcd_data[1].GPIO_LOGIC =    GPIO_LOGIC_LOW           ,
	.lcd_data[1].GPIO_DIR   =    GPIO_OUTPUT              ,
	
	.lcd_data[2].GPIO_PORT  =    GPIO_PORTC               ,
	.lcd_data[2].GPIO_PIN   =    GPIO_PIN4                ,
	.lcd_data[2].GPIO_LOGIC =    GPIO_LOGIC_LOW           ,
	.lcd_data[2].GPIO_DIR   =    GPIO_OUTPUT              ,
	
	.lcd_data[3].GPIO_PORT  =    GPIO_PORTC               ,
	.lcd_data[3].GPIO_PIN   =    GPIO_PIN5                ,
	.lcd_data[3].GPIO_LOGIC =    GPIO_LOGIC_LOW           ,
	.lcd_data[3].GPIO_DIR   =    GPIO_OUTPUT              ,
	
	
};

BUZZER_CNFG buzzer1 = {
	.port  = GPIO_PORTD  , 
	.pin   = GPIO_PIN4   , 
	.state = SOUND_OFF
};

LED_CNFG RED_LED = {
	
	.port_name   = GPIO_PORTD      ,
	.pin         = GPIO_PIN5       ,
	.connection  = LED_ACTIVE_HIGH ,
	.led_state   = LED_OFF         
};

LED_CNFG GREEN_LED = {
	
	.port_name   = GPIO_PORTD      ,
	.pin         = GPIO_PIN6       ,
	.connection  = LED_ACTIVE_HIGH ,
	.led_state   = LED_OFF
};

LED_CNFG YELLOW_LED = {
	
	.port_name   = GPIO_PORTD      ,
	.pin         = GPIO_PIN7       ,
	.connection  = LED_ACTIVE_HIGH ,
	.led_state   = LED_OFF
};


float_32  temprature  = 0 ;
uint_8    temp_buff[20]   ;


uint_16   BPM   ;
uint_8    BPM_buff[20] = "SHERIF"   ;

uint_8  PACKET_BUFFER[131] ;
uint_8  userName[] =  "device"  ;
uint_8  password[] = "sVTS-uWhlktAdhkp1cwZjpSCZLKGKtI0"  ;
uint_16 packetLength ;

uint_8  d1[] = "ds/Temperature" ;
uint_8  d2[] = "ds/Heart Rate" ;

int main(void){
	
	/*</SYSTEM INITIALIZATIONS>*/
	SYS_init();
	MQTT_connectPacket(PACKET_BUFFER,"NTI_TEAM_100100",userName,password,45,packetLength);
	for(uint_16 i = 0 ; i < packetLength ; ++i){
	   MCAL_USART_transmitData(PACKET_BUFFER[i]);
	}
	
    while(1){
		
		/*******<DISPLAY TEMPRETURE>*******/
		ECUAL_LM35_getTemp(Channel_1,&temprature);
		convert_int_to_string(temprature,temp_buff);
		ECUAL_CLCD_4bit_send_string_pos(&LCD,1,1,(uint_8 *)"TEMP : ");
		ECUAL_CLCD_4bit_send_string_pos(&LCD,1,7,temp_buff);
		MQTT_publishPacket(PACKET_BUFFER,d1,temp_buff,3,0,0,0,&packetLength);
		for(uint_16 i = 0 ; i < packetLength ; ++i){
			MCAL_USART_transmitData(PACKET_BUFFER[i]);
		}
		
		/*******<DISPLAY HEART BEAT>*******/
		ECUAL_HeartBeat_getBPM(&BPM);
		convert_int_to_string(BPM,BPM_buff);
		ECUAL_CLCD_4bit_send_string_pos(&LCD,2,1,(uint_8 *)"BPM : ");
		ECUAL_CLCD_4bit_send_string_pos(&LCD,2,7,BPM_buff);
		
		MQTT_publishPacket(PACKET_BUFFER,d2,BPM_buff,3,0,0,0,&packetLength);
		for(uint_16 i = 0 ; i < packetLength ; ++i){
			MCAL_USART_transmitData(PACKET_BUFFER[i]);
		}
		
		if((temprature >= MIN_TEMP && temprature <= MAX_TEMP ) && (BPM >= MIN_BPM && BPM <= MAX_BPM )  ){
			
			ECUAL_LED_turn_on(&GREEN_LED);
			ECUAL_LED_turn_off(&RED_LED);
			ECUAL_BUZZER_turn_off(&buzzer1);
			
		}else if (temprature < MIN_TEMP || temprature > MAX_TEMP  || BPM < MIN_BPM || BPM > MAX_BPM ){
			ECUAL_LED_turn_on(&RED_LED);
			ECUAL_LED_turn_off(&GREEN_LED);
			ECUAL_BUZZER_turn_on(&buzzer1);	
		}else {
			ECUAL_LED_turn_off(&RED_LED);
			ECUAL_LED_turn_off(&GREEN_LED);
			ECUAL_BUZZER_turn_off(&buzzer1);		
	 }	
	 
	 _delay_ms(2000);		
  }

  

}



void SYS_init(void){
	
	/*****************<MCAL INIT>******************/
	MCAL_ADC_init();
	MCAL_USART_initialize();
	
	/******************<ECUAL INIT>****************/
	ECUAL_HeartBeat_init();
	ECUAL_CLCD_4bit_intialize(&LCD);
	ECUAL_LM35_init(Channel_1);
	ECUAL_BUZZER_initialize(&buzzer1);
	ECUAL_LED_intialize(&RED_LED);
	ECUAL_LED_intialize(&GREEN_LED);
	ECUAL_LED_intialize(&YELLOW_LED);
	
}