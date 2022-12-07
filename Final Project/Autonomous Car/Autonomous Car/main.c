/*
 * Autonomous Car.c
 *
 * Created: 10/31/2022 10:50:16 PM
 * Author : Rafik
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

//UTILES
#include "STD_TYPES.h"
#include "ATMEGA32_REG.h"
#include "BITMATH.h"
//MCAL
#include "DIO_interface.h"
#include "UART_interface.h"
#include "TMR_interface.h"
//HAL
#include "CAR.h"
#include "motor_interface.h"
#include "LCD_interface.h"


int main(void)
{
	Motor_PinsOutput();
	LCD_PinsOUTPUT();
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);   //BUZZER
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);		//LED


	
#if modes == self
	//SERVO PINS
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT); //servo
	
	//ultrasonic sensor
	HCSR04Init();
	TMR_TIMER1Init();
	u16 rR ,rL ,rF;
	u8 distance =0;
	u8 distanceR=0;
	u8 distanceL=0;

#elif modes == uart
	//	Bluetooth module
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);		//Rx
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);		//Tx
	UART_init();
#endif
	
	LCD_Init();
	
	while (1) 
    {
		/************************************************************************/
		/*                     SELF DRIVING MODE                                */
		/************************************************************************/
	#if modes == self

		ServoRotation_MID();
		_delay_ms(200);
		HCSR04Trigger();
		rF = GetPulseWidth();
		distance=(rF*0.034/2.0);
		
		if(rF==US_ERROR)                // if microcontroller doesn't get any pulse then it will set the US_ERROR variable to -1
		// the following code will check if there is error then it will be displayed on the LCD screen
		{
			LCD_SendCMD(0b00000001);  //clear display
			_delay_ms(2);
			LCD_SendString("ERROR");
			_delay_ms(100);      
			continue;
		}
		if(distance < 20)
		{
			motor_brake();
			motor_stop();
			DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
			ServoRotation_LEFT();
			_delay_ms(500);
			HCSR04Trigger();
			rL = GetPulseWidth();
			distanceL=(rL*0.034/2.0);
			_delay_ms(500);
			
			ServoRotation_MID();
			_delay_ms(200);
			ServoRotation_RIGHT();
			_delay_ms(500);
			HCSR04Trigger();
			rR = GetPulseWidth();
			distanceR=(rR*0.034/2.0);
			_delay_ms(500);
			ServoRotation_MID();
			
			if(distanceL > 20 || distanceR > 20)
			{
				if(distanceL > distanceR)
				{
					move_left();
					DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
					LCD_SendCMD(0b00000001);  //clear display
					_delay_ms(2);
					LCD_SendString("Turning left");
					_delay_ms(100);
				}
				else if(distanceR > distanceL)
				{
					move_right();
					DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
					LCD_SendCMD(0b00000001);  //clear display
					_delay_ms(2);
					LCD_SendString("Turning right");
					_delay_ms(100);
				}
			}
			else
			{
				DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
				DIO_SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
				move_GoBack();
				move_backward();
				DIO_SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
				LCD_SendCMD(0b00000001);  //clear display
				_delay_ms(2);
				LCD_SendString("Turning Backward");
				_delay_ms(100);			
			}
		}
		else
		{
			move_forward();
			DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			LCD_SendCMD(0b00000001);  //clear display
			_delay_ms(2);
			LCD_SendString("Turning forward");
			
		}
		
		
		
		/************************************************************************/
		/*                             UART MODE                                */
		/************************************************************************/
				
				
	#elif modes == uart
		u8 recieved ;
		UART_RxByte(&recieved);
		if(recieved=='F')
		{
			LCD_SendCMD(0b00000001);  //clear display
			_delay_ms(2);
			
			UART_move_forward();
			LCD_SendString("Moving Forward");
			
		}
		else if(recieved=='O')
		{
			LCD_SendCMD(0b00000001);  //clear display
			_delay_ms(2);
			
			move_backward();
			LCD_SendString("Turning Backward");
		}
		else if(recieved=='R')
		{
			LCD_SendCMD(0b00000001);  //clear display
			_delay_ms(2);
			
			UART_move_right();
			LCD_SendString("Turning Right");
		}
		else if(recieved=='L')
		{
			LCD_SendCMD(0b00000001);  //clear display	
			_delay_ms(2);
			
			UART_move_left();
			LCD_SendString("Turning Left");
		}
		else if(recieved=='B')
		{
			LCD_SendCMD(0b00000001);  //clear display
			_delay_ms(2);
			
			UART_move_GoBack();
			LCD_SendString("Moving Backward");
		}
		else if((recieved=='S') || (recieved == 'l') || (recieved == 'r') || (recieved =='f') || (recieved == 'b'))
		{
			motor_stop();
		}	
		else{
			DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
			LCD_SendCMD(0b00000001);  //clear display
			_delay_ms(2);
			
			LCD_SendString("Invalid direction");
		}
	#endif
	}
}
