#ifndef STC89C52RC_LCD1602_H
#define STC89C52RC_LCD1602_H

#include <8052.h>

//用户调用函数：
void LCD_Init();

void LCD_ShowChar(unsigned char Line, unsigned char Column, char Char);

void LCD_ShowString(unsigned char Line, unsigned char Column, char *String);

void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);

void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char Length);

void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);

void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);

#endif
