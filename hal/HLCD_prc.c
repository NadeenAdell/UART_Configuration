/*
 * HLCD_prc.c
 *
 * Created: 3/27/2023 11:35:30 AM
 *  Author: Peter
 */ 

////////////////////////////////////////////////////////Includes/////////////////////////////////////////////////
#include "../Mcal/dio/dio_interface.h"
#include "../Mcal/dio/dio_private.h"
#include "../LIB/BIT_Math.h"
#include "../LIB/STD_Types.h"

#include "HLCD_cfg.h"
#include "HLCD_prv.h"
#include "HLCD_init.h"
#define F_CPU 16000000
#include <util/delay.h>

/////////////////////////////////////////////////////IMPLEMENTATION///////////////////////////////////////////

void HLCD_Void_Init(void)
{
	#if   LCD_MODE == EIGHT_BIT_MODE
	MDIO_setPinDirection(CMD_PORT , RS_PIN , PIN_OUT);
	MDIO_setPinDirection(CMD_PORT , RW_PIN , PIN_OUT);
	MDIO_setPinDirection(CMD_PORT , E_PIN , PIN_OUT);
	MDIO_setPinDirection(DATA_PORT , PORT_OUT);
	
	_delay_ms(100);
	
	//HLCD_Void_WirteCommand(INCREMENT_CURSOR_TO_RIGHT);
	//HLCD_Void_WirteCommand(HLCD_ON_OFFCONTOL);
	//HLCD_Void_WirteCommand(CLEAR_LCD);
	//HLCD_Void_WirteCommand(LCD_FUNCSET);
	//HLCD_Void_WirteCommand(RETURN_HOME);
	HLCD_Void_WirteCommand(CLEAR_DISPLAY_SCREEN);
	HLCD_Void_WirteCommand(DISPLAY_ON_CURSOR_OFF);
	HLCD_Void_WirteCommand(INCREMENT_CURSOR_TO_RIGHT);
	HLCD_Void_WirteCommand(RETURN_HOME);
	
	
	_delay_ms(20);
	
	#elif LCD_MODE == FOUR_BIT_MODE
	MDIO_setPinDirection(CMD_PORT , RS_PIN , PIN_OUT);
	MDIO_setPinDirection(CMD_PORT , RW_PIN , PIN_OUT);
	MDIO_setPinDirection(CMD_PORT , E_PIN , PIN_OUT);
	
	MDIO_setPinDirection(DATA_PORT , LCD_D5 , PIN_OUT);
	MDIO_setPinDirection(DATA_PORT , LCD_D6 , PIN_OUT );
	MDIO_setPinDirection(DATA_PORT , LCD_D7 , PIN_OUT);
	MDIO_setPinDirection(DATA_PORT , LCD_D8 , PIN_OUT  );
	
	_delay_ms(100);
	
	HLCD_Void_WirteCommand(INIT_4_BIT_MODE_CMD_1);
	HLCD_Void_WirteCommand(INIT_4_BIT_MODE_CMD_2);
	HLCD_Void_WirteCommand(INIT_4_BIT_MODE_CMD_3);
	
	//HLCD_Void_WirteCommand(INCREMENT_CURSOR_TO_RIGHT);
	//HLCD_Void_WirteCommand(HLCD_ON_OFFCONTOL);
	//HLCD_Void_WirteCommand(CLEAR_LCD);
	//HLCD_Void_WirteCommand(LCD_FUNCSET);
	//HLCD_Void_WirteCommand(RETURN_HOME);
	HLCD_Void_WirteCommand(CLEAR_DISPLAY_SCREEN);
	HLCD_Void_WirteCommand(DISPLAY_ON_CURSOR_OFF);
	HLCD_Void_WirteCommand(INCREMENT_CURSOR_TO_RIGHT);
	HLCD_Void_WirteCommand(RETURN_HOME);
	
	#endif
}


void HLCD_Void_WirteCommand(u8 Cmd)
{
	#if LCD_MODE  ==  EIGHT_BIT_MODE
    MDIO_setPinValue(CMD_PORT , RS_PIN , PIN_LOW);
    MDIO_setPinValue(CMD_PORT , RW_PIN , PIN_LOW);
    MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	MDIO_setPinValue(DATA_PORT , Cmd);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_HIGH);
	 _delay_ms(1);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
     	
	 
    #elif LCD_MODE == FOUR_BIT_MODE
	MDIO_setPinValue(CMD_PORT , RS_PIN , PIN_LOW);
	MDIO_setPinValue(CMD_PORT , RW_PIN , PIN_LOW);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	REG_PORTA = (Cmd & COMMAND_0xf0) | (REG_PORTA & COMMAND_0x0f);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_HIGH);
	_delay_ms(1);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	
	REG_PORTA = (Cmd << SHIFTING_LEFT_VAL_4) | (REG_PORTA & COMMAND_0x0f);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_HIGH);
	_delay_ms(1);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	_delay_ms(5);
	
    #endif
}


void HLCD_Void_WriteChar(u8 chr)
{
	#if LCD_MODE  ==  EIGHT_BIT_MODE
	MDIO_setPinValue(CMD_PORT , RS_PIN , PIN_HIGH);
	MDIO_setPinValue(CMD_PORT , RW_PIN , PIN_LOW);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	MDIO_setPinValue(DATA_PORT , chr);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_HIGH);
	_delay_ms(1);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	
	#elif LCD_MODE == FOUR_BIT_MODE
	MDIO_setPinValue(CMD_PORT , RS_PIN , PIN_HIGH);
	MDIO_setPinValue(CMD_PORT , RW_PIN , PIN_LOW);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	REG_PORTA = (chr & COMMAND_0xf0) | (REG_PORTA & COMMAND_0x0f);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_HIGH);
	_delay_ms(1);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	
	REG_PORTA = (chr << SHIFTING_LEFT_VAL_4) | (REG_PORTA & COMMAND_0x0f);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_HIGH);
	_delay_ms(1);
	MDIO_setPinValue(CMD_PORT , E_PIN , PIN_LOW);
	
	_delay_ms(5);
	
	#endif


}



void HLCD_Void_WrireString(u8 * pstr)
{
	u8 Copy_u8i=0;
	while(pstr[Copy_u8i] != NUll_CHARACTER)
	{
		HLCD_Void_WriteChar(pstr[Copy_u8i]);
		Copy_u8i++;
	}
}



void HLCD_Void_ClearLCD(void)
{
	HLCD_Void_WirteCommand(CLEAR_DISPLAY_SCREEN);
}


void HLCD_Void_Write_Num (s32 integr)
{

	s32 y = 1;
	
	if (integr == 0)
	{
		HLCD_Void_WriteChar('0');
	}

	if(integr < 0)
	{
		HLCD_Void_WriteChar('-');
		integr *= -1;
	}

	while(integr > 0)
	{
		y = ((y*10) + (integr%10));
		integr /= 10;
	}

	while(y > 1 )
	{
		HLCD_Void_WriteChar(((y%10)+48));
		y /= 10;
	}
}



void HLCD_Void_GoTo(u8 Row , u8 Col)
{
	u8 address ;
	if (Row < 2 /*num of rows*/ && Col <16/*numof columns*/)
	{
		address = (Row * 0x40/*first column in second row*/) + Col;
		//instarction of enable cgram
		address = SET_BIT(address , 7);
		HLCD_Void_WirteCommand(address);		
	}
}


void HLCD_Void_GenerateSpecialChar(u8 *pattern , u8 Location , u8 row , u8 col)
{
	u8 address , index;
	if (Location < 8)
	{
		address = Location *8;
		address = SET_BIT(address , 6);
		HLCD_Void_WirteCommand(address);
		for (index = 0 ; index < 8 ; index++)
		{
			HLCD_Void_WriteChar(pattern[index]);
		}
	}
	HLCD_Void_GoTo(row , col);
	HLCD_Void_WriteChar(Location);
	HLCD_Void_WirteCommand(RETURN_HOME);
}
