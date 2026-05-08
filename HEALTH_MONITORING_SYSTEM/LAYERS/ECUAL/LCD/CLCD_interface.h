/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     CLCD_interface.h          ****************** */


#ifndef   _CLCD_INTERFACE_H_
#define	  _CLCD_INTERFACE_H_

//*****************************<_INC_PART_>*************************** */

#include   "DIO_interface.h"

//*****************************<_DEF_PART_>*************************** */

#define   _LCD_CLEAR                      0x01
#define   _LCD_RETURN_HOME                0X02
#define   _LCD_ENTRY_MODE                 0X06
#define   _LCD_CURSOR_OFF_DISPLAY_ON      0X0C
#define   _LCD_CURSOR_ON_DISPLAY_ON       0X08
#define   _LCD_CURSOR_ON_BLINK_ON         0X0F
#define   _LCD_CURSOR_ON_BLINK_OFF        0X0E
#define   _LCD_DISPLAY_SHIFT_RIGHT        0X1C
#define   _LCD_DISPLAY_SHIFT_LEFT         0X18
#define   _LCD_8BIT_MODE_2LINE            0X38
#define   _LCD_4BIT_MODE_2LINE            0X28
#define   _LCD_CGGRAM_START               0X40
#define   _LCD_DDRAM_START                0X80

#define             ROW1                   1
#define             ROW2                   2
#define             ROW3                   3
#define             ROW4                   4
            
#define             COLUMN_1               1
#define             COLUMN_2               2
#define             COLUMN_3               3
#define             COLUMN_4               4
#define             COLUMN_5               5
#define             COLUMN_6               6
#define             COLUMN_7               7
#define             COLUMN_8               8
#define             COLUMN_9               9
#define             COLUMN_10              10
#define             COLUMN_11              11
#define             COLUMN_12              12
#define             COLUMN_13              13
#define             COLUMN_14              14
#define             COLUMN_15              15
#define             COLUMN_16              16
#define             COLUMN_17              17
#define             COLUMN_18              18
#define             COLUMN_19              19
#define             COLUMN_20              20



//*************************< USER DEFINED ****************************** */


typedef struct {
    GPIO_PIN_CNFG lcd_rs;
    GPIO_PIN_CNFG lcd_en;
    GPIO_PIN_CNFG lcd_data[4];
}CLCD_4BIT_CONFG;


typedef struct {
    GPIO_PIN_CNFG lcd_rs;
    GPIO_PIN_CNFG lcd_en;
    GPIO_PIN_CNFG lcd_data[8];
}CLCD_8BIT_CONFG;


//*************************<FUNCTION PROTOTYEPS********************** */

ErrorState ECUAL_CLCD_4bit_intialize( CLCD_4BIT_CONFG *lcd_obj);
ErrorState ECUAL_CLCD_4bit_send_command( CLCD_4BIT_CONFG *lcd_obj, uint_8 command);
ErrorState ECUAL_CLCD_4bit_send_char_data( CLCD_4BIT_CONFG *lcd_obj, uint_8 data);
ErrorState ECUAL_CLCD_4bit_send_char_data_pos( CLCD_4BIT_CONFG *lcd_obj, uint_8 row, uint_8 column, uint_8 data);
ErrorState ECUAL_CLCD_4bit_send_string( CLCD_4BIT_CONFG *lcd_obj, uint_8 *str);
ErrorState ECUAL_CLCD_4bit_send_string_pos( CLCD_4BIT_CONFG *lcd_obj, uint_8 row, uint_8 column, uint_8 *str);
ErrorState ECUAL_CLCD_4bit_send_custom_char( CLCD_4BIT_CONFG *lcd_obj,uint_8 row, uint_8 column,  uint_8 chr[], uint_8 mem_pos);

ErrorState ECUAL_CLCD_8bit_intialize( CLCD_8BIT_CONFG *lcd_obj);
ErrorState ECUAL_CLCD_8bit_send_command( CLCD_8BIT_CONFG *lcd_obj,uint_8 command);
ErrorState ECUAL_CLCD_8bit_send_char_data( CLCD_8BIT_CONFG *lcd_obj,uint_8 data);
ErrorState ECUAL_CLCD_8bit_send_char_data_pos( CLCD_8BIT_CONFG *lcd_obj,uint_8 row,uint_8 column,uint_8 data);
ErrorState ECUAL_CLCD_8bit_send_string( CLCD_8BIT_CONFG *lcd_obj,uint_8 *str);
ErrorState ECUAL_CLCD_8bit_send_string_pos( CLCD_8BIT_CONFG *lcd_obj, uint_8 row, uint_8 column, uint_8 *str);
ErrorState ECUAL_CLCD_8bit_send_custom_char( CLCD_8BIT_CONFG *lcd_obj,uint_8 row, uint_8 column,  uint_8 chr[], uint_8 mem_pos);

ErrorState convert_byte_to_string(uint_8 value, uint_8 *str);
ErrorState convert_short_to_string(uint_16 value, uint_8 *str);
ErrorState convert_int_to_string(uint_32 value, uint_8 *str);



static ErrorState ECUAL_CLCD_send_4bits( CLCD_4BIT_CONFG *lcd_obj, uint_8 data_command);

static ErrorState ECUAL_CLCD_8bit_set_cursor( CLCD_8BIT_CONFG *lcd_obj, uint_8 row, uint_8 column);
static ErrorState ECUAL_CLCD_4bit_set_cursor( CLCD_4BIT_CONFG *lcd_obj, uint_8 row, uint_8 column);

static ErrorState ECUAL_CLCD_4bit_send_enable_signal( CLCD_4BIT_CONFG *lcd_obj);
static ErrorState ECUAL_CLCD_8bit_send_enable_signal( CLCD_8BIT_CONFG *lcd_obj);

/**
 * @brief   Clears the LCD screen and returns the cursor to the home position.
 * @details Sends the Clear Display command (0x01) and waits for 2ms to ensure 
 * the LCD controller has enough time to finish the operation.
 * @param   lcd_obj : Pointer to the LCD configuration object.
 * @return  ErrorState : OK if successful, NOK if pointer is NULL.
 */
ErrorState ECUAL_CLCD_4bit_clear(CLCD_4BIT_CONFG *lcd_obj);

#endif	/* _CLCD_INTERFACE_H_*/

