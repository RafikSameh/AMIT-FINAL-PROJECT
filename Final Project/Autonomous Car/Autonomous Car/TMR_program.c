/*
 * TMR_program.c
 *
 * Created: 10/1/2022 1:20:05 AM
 *  Author: Rafik
 */ 

/* UTILES libraries*/
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "ATMEGA32_REG.h"
/* MCAL  */
#include "TMR_interface.h"

/* TIMER 1*/

void TMR_TIMER1Init(void)
{
	//normal mode
	TCCR1A=0X00;	
}
void TMR_TIMER1_Start(void)
{
	//Select Prescalar value = 8
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,2);
	TCNT1L_u16=0x00;
}
void TMR_TIMER1_Stop(void)
{
	//STOP TIMER0
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}
