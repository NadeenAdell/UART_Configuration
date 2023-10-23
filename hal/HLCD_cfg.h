/*
 * HLCD_cfg.h
 *
 * Created: 3/27/2023 11:34:58 AM
 *  Author: Peter
 */ 


#ifndef HLCD_CFG_H_
#define HLCD_CFG_H_

///////////////////////////////////////////////////////////////MACROO//////////////////////////////////////////////////////
#define LCD_MODE     FOUR_BIT_MODE

#define FOUR_BIT_MODE    0
#define EIGHT_BIT_MODE   1

#define  DATA_PORT       PORTA
#define  CMD_PORT        PORTB


#define  REG_PORTA  MDIO_PORTA


#define RS_PIN    PIN1
#define RW_PIN    PIN2
#define E_PIN     PIN3

#define LCD_D1   PIN0
#define LCD_D2   PIN1
#define LCD_D3   PIN2
#define LCD_D4   PIN3
#define LCD_D5   PIN4
#define LCD_D6   PIN5
#define LCD_D7   PIN6
#define LCD_D8   PIN7


#define INIT_4_BIT_MODE_CMD_1   0x33
#define INIT_4_BIT_MODE_CMD_2   0x32
#define INIT_4_BIT_MODE_CMD_3   0x28

#define  COMMAND_0xf0      0xf0
#define  COMMAND_0x0f      0x0f

#define  SHIFTING_LEFT_VAL_4      4

#define NUll_CHARACTER          '\0'



#define INIT_4_BIT_MODE_CMD_1   0x33
#define INIT_4_BIT_MODE_CMD_2   0x32
#define INIT_4_BIT_MODE_CMD_3   0x28  



#define CLEAR_DISPLAY_SCREEN           0x01
#define INCREMENT_CURSOR_TO_RIGHT      0x06
#define DISPLAY_ON_CURSOR_Blinking     0x0E
#define DISPLAY_ON_CURSOR_OFF          0x0c
#define CLEAR_LCD                      0x01
#define RETURN_HOME                    0x02
#define LCD_FUNCSET                    0x38  //display in 2 lines
#define HLCD_ON_OFFCONTOL              0x0f

#endif /* HLCD_CFG_H_ */