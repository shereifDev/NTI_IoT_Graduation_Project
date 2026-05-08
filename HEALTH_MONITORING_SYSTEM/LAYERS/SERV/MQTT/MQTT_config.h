/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  MQTT_config.h            ****************/
/****************************************************************************/

#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

/* ==================[ Connection Configurations ]================== */

/* 
 * Clean Session: 
 * 1: Broker drops all session state when client disconnects.
 * 0: Broker remembers client state (subscriptions, QoS 1/2 messages).
 */
#define         MQTT_CLEAN_SESSION       1  

/* ==================[ Last Will and Testament (LWT) ]================== */

/* Will Flag: 1 to Enable LWT message on sudden disconnect, 0 to Disable */
#define        MQTT_WILL_FLAG           0  

/* Will QoS: Defines the QoS for the Will Message (0, 1, or 2) */
#define        MQTT_WILL_QOS            0  

/* Will Retain: 1 if the Broker should retain the Will Message, 0 otherwise */
#define        MQTT_WILL_RETAIN         0  

/* ==================[ General Definitions ]================== */

#define        MQTT_QOS_0               0
#define        MQTT_QOS_1               1
#define        MQTT_QOS_2               2

#endif /* MQTT_CONFIG_H */