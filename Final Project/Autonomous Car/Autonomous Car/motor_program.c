/*
 * motor_program.c
 *
 * Created: 12/7/2022 3:26:11 PM
 *  Author: Rafik
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

//UTILES
#include "STD_TYPES.h"
#include "ATMEGA32_REG.h"
#include "BITMATH.h"
//MCAL
#include "DIO_interface.h"
//HAL
#include "motor_interface.h"

void Motor_PinsOutput(void)
{
	//motors pins
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
}


/************************************************************************/
/*                          SELF DRIVING CAR                            */
/************************************************************************/


void move_forward(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
}

void move_right(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	
	_delay_ms(600);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
}

void move_left(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
	
	_delay_ms(600);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
}

void move_backward(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
	
	_delay_ms(1050);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	
}

void move_GoBack(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
	
	_delay_ms(500);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
}
void motor_brake(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
	
	_delay_ms(200);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);

}
void motor_stop(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
}

/************************************************************************/
/*                        UART MOTION                                   */
/************************************************************************/
void UART_move_forward(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
}
void UART_move_right(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
}
void UART_move_left(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
}
void UART_move_GoBack(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
}




