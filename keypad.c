/********************************************************************
*
*   Author: Dan Kass
*	Class: CE 2811
*	Assinment: Lab 3
*	Date: 12/17/12
*	Filename: keypad.c
*	Purpose: This is the C file for the keypad API
*
********************************************************************/

#include <avr/io.h>
#include <inttypes.h>
#include <stdio.h>

#include "keypad.h"
#include "lcd.h"
#include <MSOE/delay.c>



/*******************************************************************
*
*	Author: Dan Kass
*	Purpose: Sets up PORTA for the Keypad
*	Parameters: Void
*	Returns: Void
*	
*******************************************************************/
void keypad_init(void) {

	KEYPAD_PORT = (KEYPAD_ROWS | KEYPAD_COLS);
	KEYPAD_DDR = KEYPAD_ROWS;

}

/*******************************************************************
*
*	Author: Dan Kass
*	Purpose: a private function that this file uses to read what 
*				key was pressed on the keypad
*	Parameters: Void
*	Returns: uint8_t
*	
*******************************************************************/
static uint8_t scan(void) {
	uint8_t row[ROW_COUNT]; 
		row[0] = KEYPAD_ROW1;
		row[1] = KEYPAD_ROW2;
		row[2] = KEYPAD_ROW3; 
		row[3] = KEYPAD_ROW4;
	
	uint8_t scanCode = 0;
	for(int i = 0; i < ROW_COUNT; i++) {
		KEYPAD_PORT = 0b11111111 ^ row[i];
		delay_ms(10);
		
		scanCode = KEYPAD_PIN;
		delay_ms(5);
	
		//this gets what column is pressed
		uint8_t col = scanCode | row[i];
		//now the column is '0' everything else is '1'

		//if something was pressed
		if(!(col == 0xFF)){
			return scanCode;
		}
	}
		

	return -1;
}

/*******************************************************************
*
*	Author: Dan Kass
*	Purpose: returns numeric single keypress ASCII code for the
*				key that was press ont he keypad
*	Parameters: Void
*	Returns: uint8_t
*	
*******************************************************************/
uint8_t getkey(void) {

	uint8_t test = 1;
	uint8_t returnValue;
	while (test){
		uint8_t key = scan();
		delay_ms(500);
		
		switch(key) {

			case ZERO:
				test = 0;
				returnValue = ASCII_ZERO;
				break;

			case ONE:
				test = 0;
				returnValue = ASCII_ONE;
				break;

			case TWO:
				test = 0;
				returnValue = ASCII_TWO;
				break;

			case THREE:
				test = 0;
				returnValue = ASCII_THREE;
				break;

			case FOUR:
				test = 0;
				returnValue = ASCII_FOUR;
				break;

			case FIVE:
				test = 0;
				returnValue = ASCII_FIVE;
				break;
				
			case SIX:
				test = 0;
				returnValue = ASCII_SIX;
				break;
				
			case SEVEN:
				test = 0;
				returnValue = ASCII_SEVEN;
				break;
				
			case EIGHT:
				test = 0;
				returnValue = ASCII_EIGHT;
				break;
				
			case NINE:
				test = 0;
				returnValue = ASCII_NINE;
				break;

				
			case LET_A:
				test = 0;
				returnValue = ASCII_LET_A;
				break;
				
			case LET_B:
				test = 0;
				returnValue = ASCII_LET_B;
				break;
				
			case LET_C:
				test = 0;
				returnValue = ASCII_LET_C;
				break;
				
			case LET_D:
				test = 0;
				returnValue = ASCII_LET_D;
				break;
				
			case STAR:
				test = 0;
				returnValue = ASCII_STAR;
				break;
				
			case POUND:
				test = 0;
				returnValue = ASCII_POUND;
				break;
			//keeps scanning for a button press
			defalut:
		 		test = 1;
				break;
		}
	}
	delay_ms(100);
	
	return returnValue;

}


