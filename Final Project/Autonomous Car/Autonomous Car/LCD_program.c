/*
 * LCD_program.c
 *
 * Created: 9/10/2022 10:21:30 AM
 *  Author: Rafik
 */ 
/* Utiles  */
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "ATMEGA32_REG.h"
/* MCAL  */
#include "DIO_interface.h"
/* HAL  */
#include "LCD_interface.h"
#include "LCD_config.h"

#define  F_CPU 16000000UL
#include <util/delay.h>

void LCD_Init(void)
{
	_delay_ms(35);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);    //RS -> 0
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);    //RW -> 0
	//get first 4 MSB
	WriteHalfPort(0b0010);
	//enable high then low
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	LCD_SendCMD(0b00101000);
	
	_delay_us(40);
	LCD_SendCMD(0b00001111);  //display on , cursor on , blink on
	
	_delay_us(40);
	LCD_SendCMD(0b00000001);  //clear display
	
	_delay_ms(2);
	LCD_SendCMD(0b00000110);
}

void LCD_SendCMD(u8 cmd)
{
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);    //RS -> 0
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);    //RW -> 0
	//get first 4 MSB
	WriteHalfPort(cmd>>4);
	//enable high then low
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);   
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	//second 4 LSB
	WriteHalfPort(cmd);
	//enable high then low
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

static void WriteHalfPort(u8 value)
{
	if(1 == GET_BIT(value,0))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
	}
	
	if(1 == GET_BIT(value,1))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	}
	
	if(1 == GET_BIT(value,2))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
	}
	
	if(1 == GET_BIT(value,3))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
	}
}

void LCD_SendChar(u8 data)
{
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);    //RS -> 1
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);    //RW -> 0
	//get first 4 MSB
	WriteHalfPort(data>>4);
	//enable high then low
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	//second 4 LSB
	WriteHalfPort(data);
	//enable high then low
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

void LCD_SendString(u8* string)
{
	if(string != NULL)
	{
		u8 counter=0;
		while(string[counter] != NULL)
		{
			LCD_SendChar(string[counter]);
			counter++;
		}
	}
}

void LCD_PinsOUTPUT(void)
{
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
}