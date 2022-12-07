/*
 * DIO_program.c
 *
 * Created: 9/3/2022 11:38:17 AM
 *  Author: Rafik
 */ 

/* UTILES libraries*/
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "ATMEGA32_REG.h"
/* MCAL  */
#include "DIO_interface.h"

void DIO_SetPinDirection(u8 PortID , u8 PinID , u8 PinDirection)
{
	if((PortID <=3) && (PinID <=7) && ((PinDirection == DIO_PIN_OUTPUT) || (PinDirection == DIO_PIN_INPUT)))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRA,PinID);
			}
			else
			{
				CLR_BIT(DDRA,PinID);
			}
			break;
			
			case DIO_PORTB:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRB,PinID);
			}
			else
			{
				CLR_BIT(DDRB,PinID);
			}
			break;
			
			case DIO_PORTC:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRC,PinID);
			}
			else
			{
				CLR_BIT(DDRC,PinID);
			}
			break;
			
			case DIO_PORTD:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRD,PinID);
			}
			else
			{
				CLR_BIT(DDRD,PinID);
			}
			break;
		}
	} 
	
}
void DIO_SetPinValue(u8 PortID , u8 PinID , u8 PinValue)
{
	if((PortID<=3) && (PinID <=7) && ((PinValue == DIO_PIN_LOW) || (PinValue == DIO_PIN_HIGH)))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTA,PinID);
			}
			else
			{
				CLR_BIT(PORTA,PinID);
			}
			break;
			
			case DIO_PORTB:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTB,PinID);
			}
			else
			{
				CLR_BIT(PORTB,PinID);
			}
			break;
			
			case DIO_PORTC:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTC,PinID);
			}
			else
			{
				CLR_BIT(PORTC,PinID);
			}
			break;
			
			case DIO_PORTD:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTD,PinID);
			}
			else
			{
				CLR_BIT(PORTD,PinID);
			}
			break;
		}
	}
}
void DIO_GetPinValue(u8 PortID , u8 PinID , u8* PinValue)
{
	if((PortID<=3) && (PinID <=7)  && (PinValue != NULL))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			if(DIO_PIN_HIGH ==GET_BIT(PINA,PinID))
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
			
			case DIO_PORTB:
			if(DIO_PIN_HIGH ==GET_BIT(PINB,PinID))
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
			
			case DIO_PORTC:
			if(DIO_PIN_HIGH ==GET_BIT(PINC,PinID))
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
			
			case DIO_PORTD:
			if(DIO_PIN_HIGH ==GET_BIT(PIND,PinID))
			{
				*PinValue = DIO_PIN_HIGH;
			}
			else
			{
				*PinValue = DIO_PIN_LOW;
			}
			break;
		}
	}
}

void DIO_TogglePinValue(u8 PortID , u8 PinID)
{
	if((PortID<=3) && (PinID <=7))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA,PinID);
			break;
			
			case DIO_PORTB:
			TOG_BIT(PORTB,PinID);
			break;
			
			case DIO_PORTC:
			TOG_BIT(PORTC,PinID);
			break;
			
			case DIO_PORTD:
			TOG_BIT(PORTD,PinID);
			break;
		}
	}
}

void DIO_SetPortDirection(u8 PortID , u8 PortDirection)
{
	switch(PortID)
	{
		case DIO_PORTA:
		if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRA = 0xff;
		}
		else
		{
			DDRA = 0x00;
		}
		break;
		
		case DIO_PORTB:
		if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRB = 0xff;
		}
		else
		{
			DDRB = 0x00;
		}
		break;
		
		case DIO_PORTC:
		if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRC = 0xff;
		}
		else
		{
			DDRC = 0x00;
		}
		break;
		
		case DIO_PORTD:
		if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRD = 0xff;
		}
		else
		{
			DDRD = 0x00;
		}
		break;	
	}
}

void DIO_SetPortValue(u8 PortID , u8 PortValue)
{
	if(PortID<=3)
	{
		switch(PortID)
		{
			case DIO_PORTA:
			PORTA = PortValue;
			break;
			
			case DIO_PORTB:
			PORTB = PortValue;
			break;
			
			case DIO_PORTC:
			PORTC = PortValue;
			break;
			
			case DIO_PORTD:
			PORTD = PortValue;
			break;
		}
	}
}

void DIO_GetPortValue(u8 PortID , u8* PortValue)
{
	if((PortID<=3) && (PortValue != NULL))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			*PortValue = PINA;
			break;
			
			case DIO_PORTB:
			*PortValue = PINB;
			break;
			
			case DIO_PORTC:
			*PortValue = PINC;
			break;
			
			case DIO_PORTD:
			*PortValue = PIND;
			break;
		}
	}
}
void DIO_TogglePortValue(u8 PortID )
{
	if(PortID<=3)
	{
		switch(PortID)
		{
			case DIO_PORTA:
			PORTA = ~PORTA;
			break;
			
			case DIO_PORTB:
			PORTB = ~PORTB;
			break;
			
			case DIO_PORTC:
			PORTC = ~PORTC;
			break;
			
			case DIO_PORTD:
			PORTD = ~PORTD;
			break;
		}
	}
}