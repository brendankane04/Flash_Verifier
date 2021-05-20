/*
 * timer.c
 *
 * Created: 5/18/2021 7:07:58 PM
 *  Author: brend
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

unsigned char count;

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

	//Initialize the hardware count
	count = 0;
}

ISR(TIMER0_COMPA_vect)
{
	//Increment the time if it's not max value yet. Else, roll over
	count = (count == 255) ? 0 : (count + 1);
}
