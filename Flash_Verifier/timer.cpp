/*
 * timer.c
 *
 * Created: 5/18/2021 7:07:58 PM
 *  Author: brend
 */ 

#include <avr/io.h>

void TIM0_init()
{
	//Set mode to count-to-compare
	TCCR0A |= 0x02;

	//Set value to count to
	OCR0A = 0xF9;
	
	//Set the interrupt for the overflow timer
	TIMSK0 |= 0x02;
	
	//Set the clock select bits
	TCCR0B |= 0x02;
}
