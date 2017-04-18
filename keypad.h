/********************************************************************
*
*   Author: Dan Kass
*	Class: CE 2811
*	Assinment: Lab 3
*	Date: 12/17/12
*	Filename: keypad.h
*
*	This is the header file for the keypad API
*
********************************************************************/

#ifndef keypad_h
#define keypad_h

	#define KEYPAD_DDR  DDRA
	#define KEYPAD_PORT PORTA
	#define KEYPAD_PIN  PINA

	#define COL_COUNT 4
	#define ROW_COUNT 4
	#define TOTAL_KEYS (COL_COUNT * ROW_COUNT)

	//Pin Layout
	#define KEYPAD_ROW1 0b10000000
    #define KEYPAD_ROW2 0b00000001
    #define KEYPAD_ROW3 0b00000010
    #define KEYPAD_ROW4 0b00001000
    #define KEYPAD_COL1 0b00000100
    #define KEYPAD_COL2 0b00010000
    #define KEYPAD_COL3 0b00100000
    #define KEYPAD_COL4 0b01000000

	#define KEYPAD_ROWS (KEYPAD_ROW1 | KEYPAD_ROW2 | KEYPAD_ROW3 | KEYPAD_ROW4)
	#define KEYPAD_COLS (KEYPAD_COL1 | KEYPAD_COL2 | KEYPAD_COL3 | KEYPAD_COL4)

	//PINA CONVERSTIONS
	#define ZERO	0xE7 
	#define ONE 	0x7B
	#define TWO 	0x6F
	#define THREE 	0x5F
	#define FOUR	0xFA
	#define FIVE	0xEE
	#define SIX		0xDE
	#define SEVEN   0xF9
	#define EIGHT	0xED
	#define NINE	0xDD
	#define LET_A	0x3F
	#define LET_B	0xBE
	#define	LET_C	0xBD
	#define LET_D	0xB7
	#define STAR	0xF3
	#define POUND	0xD7

	//ASCII CODES
	#define ASCII_ZERO	0x30
	#define ASCII_ONE 	0x31
	#define ASCII_TWO 	0x32
	#define ASCII_THREE	0x33
	#define ASCII_FOUR	0x34
	#define ASCII_FIVE	0x35
	#define ASCII_SIX	0x36
	#define ASCII_SEVEN 0x37
	#define ASCII_EIGHT	0x38
	#define ASCII_NINE	0x39
	#define ASCII_LET_A	0x41
	#define ASCII_LET_B	0x42
	#define	ASCII_LET_C	0x43
	#define ASCII_LET_D	0x44
	#define ASCII_STAR	0x2A
	#define ASCII_POUND	0x23

	//does the initalization for the keypad
	void keypad_init(void);

	//a private function that this file uses to read the keypad
	static uint8_t scan(void);

	//returns numeric single keypress ASCII code
	uint8_t getkey(void);


#endif
