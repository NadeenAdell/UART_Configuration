#include "lib/STD_Types.h"
#include "lib/BIT_Math.h"
#include "MCAL/dio/dio_interface.h"
#include "MCAL/uart/uart_interface.h"
#include "hal/HLCD_init.h"
#include <util/delay.h>

extern const ST_USART_CONFIG st_g_USARTconf;
int main(void)
{
	HLCD_Void_Init();
	MDIO_setPinDirection(PORTC , PIN7 ,PIN_OUT);
	MUART_init(&st_g_USARTconf);    //Linking Config
	MUART_init();                   //pre-compiling config
    while(1)
    {
		u8 arr[]="UART Done Link Config";
		u8 u8_receiveddata = 0;
		u8_receiveddata = MUART_receiveByte();
		if (u8_receiveddata == 'a')
		{
			MDIO_setPinValue(PORTC , PIN7 , PIN_HIGH);
			HLCD_Void_WriteChar(u8_receiveddata);
			_delay_ms(4000);
			HLCD_Void_ClearLCD();
		
			HLCD_Void_WrireString(arr);
			_delay_ms(4000);
			HLCD_Void_ClearLCD();
			MDIO_setPinValue(PORTC , PIN7 , PIN_LOW);
		}
		
		MUART_sendByte(u8_receiveddata);
        //TODO:: Please write your application code 
    }
}