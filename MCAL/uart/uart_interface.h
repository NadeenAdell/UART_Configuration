/*
 * uart_interface.h
 *
 * Created: 10/15/2023 12:53:39 PM
 *  Author: nadeen.adel
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "uart_linkingconfig.h"
/***********************************Prototypes***********************************/

void MUART_init(const ST_USART_CONFIG *config);

void MUART_sendByte(u8 u8_a_data);

u8 MUART_receiveByte(void);

void MUART_sendString(u8* pdata);







#endif /* UART_INTERFACE_H_ */