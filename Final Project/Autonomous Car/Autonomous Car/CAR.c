/*
 * CAR.c
 *
 * Created: 11/28/2022 12:03:01 AM
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
#include "TMR_interface.h"
//HAL
#include "CAR.h"



void HCSR04Init()
{
	
	// we're setting the trigger pin as output as it will generate ultrasonic sound wave
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);		//TRIG
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_PIN_INPUT);		//ECHO
}

void HCSR04Trigger()
{   // this function will generate ultrasonic sound wave for 15 microseconds
	//Send a 10uS pulse on trigger line
	
	DIO_SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);	//high
	
	_delay_us(10);				//wait 10uS
	
	DIO_SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);	//low
}

void ServoRotation_RIGHT(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_HIGH);
	_delay_us(550);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_LOW);
	_delay_ms(20);
}

void ServoRotation_LEFT(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_HIGH);
	_delay_us(2500);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_LOW);
	_delay_ms(20);

}

void ServoRotation_MID(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_HIGH);
	_delay_us(1550);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_LOW);
	_delay_ms(20);

}


u16 GetPulseWidth()
{
	// this function will be used to measure the pulse duration. When the ultra sound echo back after hitting an object
	// the microcontroller will read the pulse using the echo pin of the ultrasonic sensor connected to it.
	
	u32 i;
	u16 result;
	

	// Section - 1: the following lines of code before the section - 2 is checking if the ultrasonic is working or not
	// it check the echo pin for a certain amount of time. If there is no signal it means the sensor is not working or not connect properly
	for(i=0;i<600000;i++)
	{
		if(!GET_BIT(PINC,1) )
		continue;	//Line is still low, so wait
		else
		break;		//High edge detected, so break.
	}

	if(i==600000)
	return US_ERROR;	//Indicates time out
	
	TMR_TIMER1_Start();
	
	for(i=0;i<600000;i++)                // the 600000 value is used randomly to denote a very small amount of time, almost 40 miliseconds
	{
		if(GET_BIT(PINC,1))
		{
			if(TCNT1L_u16 > 60000) break; else continue;   // if the TCNT1 value gets higher than 60000 it means there is not object in the range of the sensor
		}
		else
		break;
	}

	if(i==600000)
	return US_NO_OBSTACLE;	//Indicates time out

	//Falling edge found

	result=TCNT1L_u16;          // microcontroller stores the the value of the counted pulse time in the TCNT1 register. So, we're returning this value to the
	// main function for utilizing it later

	//Stop Timer
	TMR_TIMER1_Stop();

	if(result > 60000)
	return US_NO_OBSTACLE;	//No obstacle
	else
	return (result>>1);
}
