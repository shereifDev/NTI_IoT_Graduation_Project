/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  MQTT_interface.h         ****************/
/****************************************************************************/



#ifndef _MQTT_INTERFACE_H_
#define _MQTT_INTERFACE_H_


//*****************************<_INC_PART_>*************************** */

#include  "STD_TYPES.h"

/*************************<FUNCTIONS_PROTOTYEPS ********************** */








/**
 * @brief 
 * 
 * 
 * 
 * 
 * 
 */

ErrorState MQTT_connectPacket(uint_8 *packetBuffer , const uint_8 *clientID ,const uint_8 *userName ,const uint_8 *passWord , uint_16 KAT , uint_8 *packetLength);




/**
 * @brief 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
ErrorState MQTT_publishPacket(uint_8 *packetBuffer, const uint_8 *topic, const uint_8 *payload, uint_16 payloadLen, uint_8 QoS, uint_8 retain, uint_16 packetID, uint_16 *packetLength);



#endif /*<_MQTT_INTERFACE_H_*/
