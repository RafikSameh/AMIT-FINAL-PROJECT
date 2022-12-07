/*
 * LCD_interface.h
 *
 * Created: 9/10/2022 10:21:50 AM
 *  Author: Rafik
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_Init(void);
void LCD_SendChar(u8 data);
void LCD_SendCMD(u8 cmd);
void LCD_SendString(u8* string);
void LCD_PinsOUTPUT(void);

static void WriteHalfPort(u8 value);

#endif /* LCD_INTERFACE_H_ */