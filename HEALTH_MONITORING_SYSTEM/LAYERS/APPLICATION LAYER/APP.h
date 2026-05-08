/*
 * APP.h
 *
 * Created: 5/7/2026 10:43:55 PM
 *  Author: sherif
 */ 


#ifndef APP_H_
#define APP_H_


#include "CLCD_interface.h"
#include "ADC_interface.h"
#include "LED_interface.h"
#include "MQTT_interface.h"
#include "BUZZER_interface.h"
#include "USART_interface.h"
#include "HBS_interface.h"
#include "TES_interface.h"


#define   F_CPU       8000000UL
#include <util/delay.h>


void SYS_init(void);



#define      MAX_TEMP         40
#define      MIN_TEMP         36 


#define      MAX_BPM         100
#define      MIN_BPM         55


#endif /* APP_H_ */