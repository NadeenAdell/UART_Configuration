/*
 * uart_private.h
 *
 * Created: 10/15/2023 12:54:28 PM
 *  Author: nadeen.adel
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/***********Registers Addresses************/
#define  UBRRL	     (*(volatile u8*)(0x29))
#define  UBRRH	     (*(volatile u8*)(0x40))
#define  UCSRA	     (*(volatile u8*)(0x2B))
#define  UCSRB	     (*(volatile u8*)(0x2A))
#define UCSRC        (*(volatile u8*)(0x40)) 
#define  UDR	     (*(volatile u8*)(0x2C))





/*******UCSRA Register bits*******/
#define MPCM    0
#define U2X     1
#define PE      2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

/*******UCSRB Register bits*******/
#define TXB8     0
#define RXB8     1
#define UCSZ2    2
#define TXEN     3
#define RXEN     4
#define UDRIE    5
#define TXCIE    6
#define RXCIE    7

/*******UCSRC Register bits*******/
#define UCPOL    0
#define UCSZ0    1 
#define UCSZ1    2
#define USBS     3
#define UPM0     4
#define UPM1     5
#define UMSEL    6
#define URSEL    7
 /*
#define ASYNC_NORMAL_EQU               ((USART_SET_FCPU/(16*USART_SET_BAUD_RATE))-1)
#define ASYNC_DOUBLE_EQU               ((USART_SET_FCPU/(4*USART_SET_BAUD_RATE))-1)
#define SYNC_EQU               ((USART_SET_FCPU/(2*USART_SET_BAUD_RATE))-1)
*/

#endif /* UART_PRIVATE_H_ */