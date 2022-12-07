/*
 * ATMEGA32_REG.h
 *
 * Created: 9/3/2022 11:57:17 AM
 *  Author: Rafik
 */ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

#define PORTA (*(volatile u8*)0x3B)
#define DDRA (*(volatile u8*)0x3A)
#define PINA (*(volatile u8*)0x39)

#define PORTB (*(volatile u8*)0x38)
#define DDRB (*(volatile u8*)0x37)
#define PINB (*(volatile u8*)0x36)

#define PORTC (*(volatile u8*)0x35)
#define DDRC (*(volatile u8*)0x34)
#define PINC (*(volatile u8*)0x33)

#define PORTD (*(volatile u8*)0x32)
#define DDRD (*(volatile u8*)0x31)
#define PIND (*(volatile u8*)0x30)

//External Interrupts Registers
#define MCUCR (*(volatile u8*)0x55) 
#define MCUCSR (*(volatile u8*)0x54)
#define GICR (*(volatile u8*)0x5B)
#define GIFR (*(volatile u8*)0x5A) 
#define SREG (*(volatile u8*)0x5F) 

//ADC REGISTERS
#define ADMUX (*(volatile u8*)0x27)		//ADC multiplexer
#define ADCSRA (*(volatile u8*)0x26)	//ADC Control and Status Register A

#define ADCL (*(volatile u8*)0x24)		//ADC Data Register
#define ADCH (*(volatile u8*)0x25)
#define ADC_u16 (*(volatile u16*)0x24)	//ADC Data Register For Both Registers

#define SFIOR (*(volatile u8*)0x50)		//Special FunctionIO Register

		/* TIMERS REGISTERS */
		
#define TIMSK    (*(volatile u8*)0x59)
#define TIFR     (*(volatile u8*)0x58)
//TMR0 REGISTERS

#define TCCR0    (*(volatile u8*)0x53)
#define TCNT0    (*(volatile u8*)0x52)
#define OCR0     (*(volatile u8*)0x5C)


//TMR1 REGISTERS
#define TCCR1A		(*(volatile u8*)0x4F)
#define TCCR1B		(*(volatile u8*)0x4E)

#define TCNT1H		(*(volatile u8*)0x4D)
#define TCNT1L		(*(volatile u8*)0x4C)
#define TCNT1L_u16	(*(volatile u16*)0x4C)

#define OCR1AH		(*(volatile u8*)0x4B)
#define OCR1AL		(*(volatile u8*)0x4A)
#define OCR1A_u16	(*(volatile u16*)0x4A)

#define OCR1BH		(*(volatile u8*)0x49)
#define OCR1BL		(*(volatile u8*)0x48)
#define OCR1B_u16	(*(volatile u16*)0x48)

#define ICR1H		(*(volatile u8*)0x47)
#define ICR1L		(*(volatile u8*)0x46)
#define ICR1_u16	(*(volatile u16*)0x46)


/*		UART REGISTERS		*/
//USART I/O Data Register
#define UDR		(*(volatile u8*)0x2C)
//USART Control and Status Register A
#define UCSRA	(*(volatile u8*)0x2B)
//USART Control and Status Register B
#define UCSRB	(*(volatile u8*)0x2A)
//USART Control and Status Register C
#define UCSRC	(*(volatile u8*)0x40)
//USART Baud Rate Registers
#define UBRRL	(*(volatile u8*)0x29)
#define UBRRH	(*(volatile u8*)0x40)


/*		SPI REGISTERS		*/
//SPI Control Register
#define SPCR	(*(volatile u8*)0x2D)
//SPI Status Register
#define SPSR	(*(volatile u8*)0x2E)
//SPI Data Register
#define SPDR	(*(volatile u8*)0x2F)


/*		I2S (Two Wire Serial Interface) REGISTERS	*/
//TWI Bit Rate Register
#define TWBR	(*(volatile u8*)0x20)
//TWI Status Register
#define TWSR	(*(volatile u8*)0x21)
//TWI (Slave) Address Register
#define TWAR	(*(volatile u8*)0x22)
//TWI Data Register
#define TWDR	(*(volatile u8*)0x23)
//TWI Control Register
#define TWCR	(*(volatile u8*)0x56)













#endif /* ATMEGA32_REG_H_ */