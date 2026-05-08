/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  MQTT_program.c           ****************/
/****************************************************************************/

//*****************************<_INC_PART_>*************************** */

#include   "MQTT_interface.h"
#include   "MQTT_private.h"
#include   "MQTT_config.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <string.h>   









ErrorState MQTT_connectPacket(uint_8 *packetBuffer , const uint_8 *clientID ,const uint_8 *userName ,const uint_8 *passWord , uint_16 KAT , uint_16 *packetLength){

    ErrorState checkErrorState = OK;

    if(NULL == packetBuffer || NULL == clientID || NULL == packetLength){
      checkErrorState = NOK ;
    }else{

            uint_16 cnt = 0 ;
            uint_16 i = 0;

            uint_16 clientID_len = strlen((const char*)clientID);
            uint_16 userName_len = (userName != NULL) ? strlen((const char*)userName) : 0;
            uint_16 passWord_len = (passWord != NULL) ? strlen((const char*)passWord) : 0;
            
            // Calculate Payload Length
            uint_16 payloadLen = (2 + clientID_len);
            if (userName != NULL) payloadLen += (2 + userName_len);
            if (passWord != NULL) payloadLen += (2 + passWord_len);
            
            // Variable Header Length is fixed at 10 bytes for CONNECT packet
            uint_16 remLen = 10 + payloadLen;

            /*</FIXED HEADER>*/
            // packet type + connect packet flags -> 0b00010000 (0x10)
            packetBuffer[cnt++] = 0x10 ;
            
            // Remaining length (Using standard MQTT encoding algorithm for lengths > 127)
            do {
                uint_8 encodedByte = remLen % 128;
                remLen = remLen / 128;
                if (remLen > 0) {
                    encodedByte |= 128;
                }
                packetBuffer[cnt++] = encodedByte;
            } while (remLen > 0);
            
            /*</VARIABLE HEADER>*/
            //length of MQTT word (UTF8) -> 0x04 byte
            packetBuffer[cnt++] = 0x00 ;
            packetBuffer[cnt++] = 0x04 ;
            // store MQTT word in the packet 
            packetBuffer[cnt++] = 'M';
            packetBuffer[cnt++] = 'Q';
            packetBuffer[cnt++] = 'T';
            packetBuffer[cnt++] = 'T';
            //level of MQTT protocol .. we will work @ 3.1.1 & its level is 4 
            packetBuffer[cnt++] = 0x04;
            // Connect flags 
            uint_8 flags = 0x00; 
            //Clean Session (Bit 1)
            #if MQTT_CLEAN_SESSION == 1
                SET_BIT(flags, 1);
            #endif
            //Will Flag, Will QoS, Will Retain (Bits 2, 3, 4, 5)
            #if MQTT_WILL_FLAG == 1
                SET_BIT(flags, 2); // Enable Will Flag
                
                // Set Will QoS (Bits 3 and 4)
                flags |= (MQTT_WILL_QOS << 3); 
                
                // Set Will Retain (Bit 5)
                #if MQTT_WILL_RETAIN == 1
                    SET_BIT(flags, 5);
                #endif
            #endif

            if(userName != NULL) SET_BIT(flags, 7); // Set Username flag
            if(passWord != NULL) SET_BIT(flags, 6); // Set Password flag
            packetBuffer[cnt++] = flags;
            
            // KAT (Keep Alive Timer) - Splitting 16-bit into two 8-bit registers (MSB then LSB)
            packetBuffer[cnt++] = (uint_8)(KAT >> 8);
            packetBuffer[cnt++] = (uint_8)(KAT & 0xFF);
            
            /*</PAYLOAD>*/
            //Client ID 
            packetBuffer[cnt++] = (uint_8)(clientID_len >> 8) ;
            packetBuffer[cnt++] = (uint_8)(clientID_len & 0xFF) ;
            for(i = 0; i < clientID_len; i++){
                packetBuffer[cnt++] = clientID[i];
            }

            //User Name 
            if(userName != NULL){
                packetBuffer[cnt++] = (uint_8)(userName_len >> 8) ;
                packetBuffer[cnt++] = (uint_8)(userName_len & 0xFF) ;
                for(i = 0; i < userName_len; i++){
                    packetBuffer[cnt++] = userName[i];
                }
            }

            //Password 
            if(passWord != NULL){
                packetBuffer[cnt++] = (uint_8)(passWord_len >> 8) ;
                packetBuffer[cnt++] = (uint_8)(passWord_len & 0xFF) ;
                for(i = 0; i < passWord_len; i++){
                    packetBuffer[cnt++] = passWord[i];
                }
            }

            // Return the total packet length 
            *packetLength = cnt;
    }
    
  return checkErrorState;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


ErrorState MQTT_publishPacket(uint_8 *packetBuffer, const uint_8 *topic, const uint_8 *payload, uint_16 payloadLen, uint_8 QoS, uint_8 retain, uint_16 packetID, uint_16 *packetLength) {
    
    ErrorState checkErrorState = OK;
    if (NULL == packetBuffer || NULL == topic || NULL == payload || NULL == packetLength) {
        checkErrorState = NOK;
    }else {
        uint_16 cnt = 0;
        uint_16 i = 0;
        
        uint_16 topicLen = strlen((const char*)topic);
        
        // Calculate Variable Header Length
        // (2 bytes for Topic Length) + (Topic string length)
        uint_16 varHeaderLen = 2 + topicLen;
        
        // If QoS > 0, MQTT requires 2 additional bytes for the Packet Identifier
        if (QoS > 0) {
            varHeaderLen += 2;
        }
        
        // Calculate total Remaining Length
        uint_16 remLen = varHeaderLen + payloadLen;

        /*</FIXED HEADER>*/
        //Packet type (PUBLISH -> 0b00110000 or 0x30)
        uint_8 publishFlags = 0x30;
        publishFlags |= (QoS << 1) & 0x06; 
        publishFlags |= (retain & 0x01);   
        
        packetBuffer[cnt++] = publishFlags;
        
        // 2. Remaining length 
        do {
            uint_8 encodedByte = remLen % 128;
            remLen = remLen / 128;
            if (remLen > 0) {
                encodedByte |= 128;
            }
            packetBuffer[cnt++] = encodedByte;
        } while (remLen > 0);

        /*</VARIABLE HEADER>*/
        //Topic Length (MSB then LSB)
        packetBuffer[cnt++] = (uint_8)(topicLen >> 8);
        packetBuffer[cnt++] = (uint_8)(topicLen & 0xFF);
        
        // Topic String
        for (i = 0 ; i < topicLen ; i++) {
            packetBuffer[cnt++] = topic[i];
        }
        
        // 3. Packet Identifier (Only required if QoS > 0)
        if (QoS > 0) {
            packetBuffer[cnt++] = (uint_8)(packetID >> 8);
            packetBuffer[cnt++] = (uint_8)(packetID & 0xFF);
        }

        /*</PAYLOAD>*/
        // The actual data (String or Binary)
        for (i = 0; i < payloadLen; i++) {
            packetBuffer[cnt++] = payload[i];
        }

        // Store the final packet length to be sent via UART/Bridge
        *packetLength = cnt;
    }
    
   return checkErrorState;

}