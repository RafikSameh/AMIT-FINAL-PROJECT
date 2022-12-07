/*
 * motor_interface.h
 *
 * Created: 12/7/2022 3:26:35 PM
 *  Author: Rafik
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

void Motor_PinsOutput(void);
		/************************************************************************/
		/*                     SELF DRIVING MODE                                */
		/************************************************************************/
void move_forward(void);
void move_right(void);
void move_left(void);
void move_backward(void);
void move_GoBack(void);
void motor_stop(void);
void motor_brake(void);
		/************************************************************************/
		/*                             UART MODE                                */
		/************************************************************************/
void UART_move_forward(void);
void UART_move_right(void);
void UART_move_left(void);
void UART_move_GoBack(void);



#endif /* MOTOR_INTERFACE_H_ */