/*
 * UART_program.c
 *
 * Created: 10/15/2022 8:43:08 AM
 *  Author: Rafik
 */ 
/* UTILES libraries*/
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "ATMEGA32_REG.h"
/* MCAL  */
#include "UART_interface.h"

void UART_init(void)
{
	//Writing the UCSRC , Asynchronous mode , No parity , char size = 8 , stop bits =1
	UCSRC = 0x86;	//0b10000110
	CLR_BIT(UCSRB,2);
	//Set Baud Rate = 9600
	UBRRL=103;
	
	//Enable reciever and transmitter
	SET_BIT(UCSRB,3);	//Enable Tx
	SET_BIT(UCSRB,4);	//Enable Rx
}

void UART_TxByte(u8 data)
{
	UDR = data;
	while(0 == GET_BIT(UCSRA,5));
}

void UART_RxByte(u8* returnedData)
{
	if(returnedData != NULL)
	{
		while(0 == GET_BIT(UCSRA,7));
		*returnedData = UDR;
	}
}

void UART_RxString(u8* string)
{
	if(string != NULL)
	{
		u8 counter=0;
		while(0 == GET_BIT(UCSRA,7));
		while(string[counter] != NULL)
		{
			UART_RxByte(string[counter]);
			counter++;
		}
	}
}
void UART_TxString(u8* string)
{
	if(string != NULL)
	{
		u8 counter=0;
		while(string[counter] != '\0')
		{
			UART_TxByte(string[counter]);
			counter++;
		}
	}
	else
	{
		//Do Nothing
	}
}

