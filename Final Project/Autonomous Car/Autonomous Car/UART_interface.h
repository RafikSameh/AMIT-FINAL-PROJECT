/*
 * UART_interface.h
 *
 * Created: 10/15/2022 8:43:27 AM
 *  Author: Rafik
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_init(void);
void UART_TxByte(u8 data);
void UART_RxByte(u8* returnedData);
void UART_TxString(u8* string);
void UART_RxString(u8* string);





#endif /* UART_INTERFACE_H_ */