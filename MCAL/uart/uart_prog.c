/*
 * uart_prog.c
 *
 * Created: 10/15/2023 12:54:52 PM
 *  Author: nadeen.adel
 */ 

/***********************************Includes***********************************/
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"


#include "uart_linkingconfig.h"
#include "uart_interface.h"
#include "uart_private.h"

const ST_USART_CONFIG st_g_USARTconf = {
	.SYNC_MODE = USART_SYNC_MODE,
	.FCPU = FCPU_8MHZ,
	.BAUD_RATE = BAUD_9600,
	.SPEED_MODE = USART_NORMAL_SPEED,
	.PARITY_MODE = USART_EVEN_PARITY,
	.STOP_BIT = USART_TWO_STOP_BITS,
	.DATA_SIZE = USART_DATA_SIZE_8,
};

#define ASYNC_NORMAL_EQU               ((st_g_USARTconf.FCPU/(16*st_g_USARTconf.BAUD_RATE))-1)
#define ASYNC_DOUBLE_EQU               ((st_g_USARTconf.FCPU/(4*st_g_USARTconf.BAUD_RATE))-1)
#define SYNC_EQU               ((st_g_USARTconf.FCPU/(2*st_g_USARTconf.BAUD_RATE))-1)




void MUART_init(const ST_USART_CONFIG *config)
{
	u16 UBRR_val;       //to set the value in UBRRL register
	//To Calculate the value in UBRRL & UBBRH registers
		switch(config->SYNC_MODE)
		{
			case USART_ASYNC_MODE:
			{
				if(config->SPEED_MODE == USART_NORMAL_SPEED)
				{
					UBRR_val= ASYNC_NORMAL_EQU;
				}
				else if( config->SPEED_MODE ==  USART_DOUBLE_SPEED )
				{
					UBRR_val = ASYNC_DOUBLE_EQU;
				}
				break;
			}
			case USART_SYNC_MODE:
			{
				UBRR_val = SYNC_EQU;
				break;
			}
		}
		
	UBRRL=(u8)(UBRR_val>>8);
	UBRRH=(u8)(UBRR_val);
	
	/*Set speed mode*/
	switch(config->SPEED_MODE)
	{
		case USART_NORMAL_SPEED:
		  CLEAR_BIT(UCSRA,U2X);
		  break;
	
		case USART_DOUBLE_SPEED:
		 SET_BIT(UCSRA,U2X);
		 break;
	}
	/*Set synchronization mode*/
	switch(config->SYNC_MODE)
	{
		case USART_SYNC_MODE:
		 SET_BIT(UCSRC,UMSEL);
		 break;
	
		case USART_ASYNC_MODE:
		CLEAR_BIT(UCSRC,UMSEL);
		break;
	}
	
	 /*Set Parity mode*/
	 switch(config->PARITY_MODE)
	 {
		 case USART_NO_PARITY:
		 CLEAR_BIT(UCSRC,UPM0);
		 CLEAR_BIT(UCSRC,UPM1);
		 break;
	 
		 case USART_EVEN_PARITY:
		 CLEAR_BIT(UCSRC,UPM0);
		 SET_BIT(UCSRC,UPM1);
		 break;
	 
		 case USART_ODD_PARITY:
		 SET_BIT(UCSRC,UPM0);
		 SET_BIT(UCSRC,UPM1);
		 break;
	 }
	 /*Set number of stop bits*/
	  switch(config->STOP_BIT)
	  {
		 case USART_ONE_STOP_BIT:
		 CLEAR_BIT(UCSRC,USBS);
		 break;
	 
		 case USART_TWO_STOP_BITS:
		 SET_BIT(UCSRC,USBS);
		 break;
	  }
	 /*Set Data size*/
	 switch (config->DATA_SIZE)
	 {
		 case USART_DATA_SIZE_5:
		 CLEAR_BIT(UCSRC,UCSZ0);
		 CLEAR_BIT(UCSRC,UCSZ1);
		 CLEAR_BIT(UCSRB,UCSZ2);
		 break;
	 
		case USART_DATA_SIZE_6:
		 SET_BIT(UCSRC,UCSZ0);
		 CLEAR_BIT(UCSRC,UCSZ1);
		 CLEAR_BIT(UCSRB,UCSZ2);
		 break;
	 
		 case USART_DATA_SIZE_7:
		 CLEAR_BIT(UCSRC,UCSZ0);
		 SET_BIT(UCSRC,UCSZ1);
		 CLEAR_BIT(UCSRB,UCSZ2);
		 break;
	 
		case USART_DATA_SIZE_8:
		 SET_BIT(UCSRC,UCSZ0);
		 SET_BIT(UCSRC,UCSZ1);
		 CLEAR_BIT(UCSRB,UCSZ2);
		 break;
	 
		 case USART_DATA_SIZE_9:
		 SET_BIT(UCSRC,UCSZ0);
		 SET_BIT(UCSRC,UCSZ1);
		 SET_BIT(UCSRB,UCSZ2);
		 break;
	 }
	
	/*Enable UART  receiver*/
	SET_BIT(UCSRB,RXEN);
	
	/*Enable UART  transmitter*/
	SET_BIT(UCSRB,TXEN);
	
	/*Set URSEL to write on UCSRC*/
	SET_BIT(UCSRC,URSEL);    //

}

void MUART_sendByte(u8 u8_a_data)
{
	//wait for empty transmit buffer
	while (!GET_BIT(UCSRA,UDRE));
	UDR = u8_a_data;    
}

u8 MUART_receiveByte(void)
{
	//wait until receive flag is1 ,receive complete
		while (!GET_BIT(UCSRA,RXC));
		return  UDR;

}

void MUART_sendString(u8* pdata)
{
	while(*pdata != '\0')
	{
		MUART_sendByte(*pdata);
		pdata++;
	}
}
/*
void MUART_sendByteAsynch(u8 u8_a_data)
{
	/* Set byte to be transmitted */
	/*
	UDR= u8_a_data;
}

u8 MUART_readByteAsynch (void)
{
	return UDR;
}
*/

