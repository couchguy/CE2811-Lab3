/********************************************************************
*
*   Author: Dan Kass
*	Class: CE 2811
*	Assinment: Lab 3
*	Date: 12/17/12
*	Filename: lab3.h
*
*	This is the tester program for the keypad and LCD API
*
********************************************************************/

#include <avr/io.h>
#include <inttypes.h>
#include <stdio.h>

#include "keypad.h"
#include "lcd.h"

int main(void)
{

	
	lcd_init(); 	//initalizes the LCD Screen
	keypad_init(); 	//initalizes the keypad
	uint8_t counter = 0;
	
	while(1)
	{
		uint8_t digit = getkey();
		delay_ms(100);
		lcd_char(digit);
		counter++;
		if(counter == 16)
		{
			counter = 0;
			lcd_char(CR);
		}
		
	
	}//while loop
	
} //main
