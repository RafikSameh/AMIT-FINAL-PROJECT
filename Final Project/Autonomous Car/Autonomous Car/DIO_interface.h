/*
 * DIO_interface.h
 *
 * Created: 9/3/2022 11:38:51 AM
 *  Author: Rafik
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0

#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT 0x00

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

//PIN Apis
void DIO_SetPinDirection(u8 PortID , u8 PinID , u8 PinDirection);
void DIO_SetPinValue(u8 PortID , u8 PinID , u8 PinValue);
void DIO_GetPinValue(u8 PortID , u8 PinID , u8* PinValue);
void DIO_TogglePinValue(u8 PortID , u8 PinID);

//Port Apis
void DIO_SetPortDirection(u8 PortID , u8 PortDirection);
void DIO_SetPortValue(u8 PortID , u8 PortValue);
void DIO_GetPortValue(u8 PortID , u8* PortValue);
void DIO_TogglePortValue(u8 PortID );


#endif /* DIO_INTERFACE_H_ */