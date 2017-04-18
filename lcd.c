   /****************************************************************
	* FILENAME: lcd.c								               *
	* AUTHOR: Dan Kass kassd@msoe.edu    			               *
	* DATE: December 6, 2012						               *
	* CLASS: CE-2811 Lab 2 Professor Barnicki		               *
	* Provdies: 									               *
	*		Funtion for the lcd					 	               *
	*		provides output to the lcd				               *
	*		and funtion control to the lcd screen 	               *
	*												               *
	****************************************************************/

#include <avr/io.h>
#include <inttypes.h>

#include "lcd.h"

/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu 
*	Purpose: Initializes the serial communications
*	Parameters: void
*	Returns: void
*	
*******************************************************************/
void lcd_init(void)
{
	UBRRH = 0;
	UBRRL = UBRR_VAL; 					// 9600 baud
	UCSRB = (1<<TXEN)|(1<<RXEN);	// Enable Tx and Rx
}

/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Prints a character out to the lcd
*	Parameters: char. The character that is to be printed
*	Returns: void
*	
*******************************************************************/	
void lcd_char(char x)
{
		while(!(UCSRA&(1<<UDRE)));	// Wait for UDR empty
		UDR = x;					// Send char
}

/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Prints a string out to the lcd
*	Parameters: char. The point to the character array for the 
*		string
*	Returns: void
*	
*******************************************************************/
void lcd_string(char *c)
{
	for(int i=0; c[i] != 0; i++)
	{
		lcd_char(c[i]);
	}
	lcd_char(CR);
	lcd_char(LF);
}

 /*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Puts the lcd curser in the correct x, y corrdinate spot
*	Parameters: uint8_t, uint8_t. row, column
*		(0,0) is the upper left, 0 <= x or y <= 15
*	Returns: void
*	
*******************************************************************/
void lcd_gotoxy(uint8_t x, uint8_t y)
{
	uint8_t output = 128; //cursor at line 0 position 0
	//makes sure the x and y corridnates fit within the lcd screen
	if((x <= 1) && (y <= 15))
	{
		//0 line is 128 + y for each position
		//1 line is 148 + y for each position
		output += (x*20) + y;
	}
	lcd_char(output);
}

/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Clears the lcd and returns the curser to (0,0)
*	Parameters: void
*	Returns: void
*	
*******************************************************************/
void lcd_clear(void)
{
	lcd_ff();
}

/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Sends a form feed to the lcd
*	Parameters: void
*	Returns: void
*	
*******************************************************************/
void lcd_ff(void)
{
	lcd_char(FF);
}

/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Sends a backspace to the lcd
*	Parameters: void
*	Returns: void
*	
*******************************************************************/
void lcd_left(void)
{
	lcd_char(BS);
}

/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Turns the lcdbacklight on or off
*	Parameters: char. Either "ON" or "OFF" #define 1 and 0
*	Returns: void
*	
*******************************************************************/
void lcd_backlight(char state)
{
	// sets the light to ON as default
	uint8_t backlight = LIGHTON;
	if ( state == '0' )
	{
		// sets the light to off
		backlight = LIGHTOFF;
	}
	lcd_char(backlight);
}
 
/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Puts the lcd curser in the correct x, y corrdinate spot
*	Parameters: char. Either "ON" or "OFF" #define 1 and 0
*	Returns: void
*	
*******************************************************************/
void lcd_switch(char state)
{
	// sets the power to OFF as default
	uint8_t power = DISPLAYOFF;
	if ( state == '1' )
	{
		//turns the back light on then turns on the display
		lcd_backlight(ON);
		// sets the display on cursor on and character blink
		power = DISPLAYON;
	}
	else
	{
		//When the Display goes off the back light will also go off.
		lcd_backlight(OFF);
	}
	lcd_char(power);
}

/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: assigns character array to a custom character spot in
*		the lcd
*	Parameters: uint8_t, char*.0 to 7 custom character 
*		spot,char pointer to custom character
*	Returns: void
*	
*******************************************************************/
void lcd_define_char(uint8_t num, char *data)
{
	lcd_char(num+247);
	for(int i=0; i < 8; i++)
	{
		lcd_char(data[i]);
	}
}
  
/*******************************************************************
*
*	Author: Dan Kass kassd@msoe.edu
*	Purpose: Prints the custom character out to the lcd
*	Parameters: uint8_t. 0 to 7 custom character spot
*	Returns: void
*	
*******************************************************************/
void lcd_custom(uint8_t num)
{
	if(num <= 8)
	//num works becasue the custom chars codes are 0-7
	//and will be stored in the same style
	lcd_char(num-1);
}
