/*
 * timer.c
 *
 * Created: 5/18/2021 7:07:58 PM
 *  Author: brend
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

unsigned char count;

//Init function
void TIM0_init()
{
	//Set mode to count-to-compare
	TCCR0A |= _BV(WGM01);

	//Set value to count to
	OCR0A = 0xF9;
	
	//Set the interrupt for the overflow timer
	TIMSK0 |= _BV(OCIE0A);
	
	//Set the clock select bits
	TCCR0B |= _BV(CS01);

	//Initialize the hardware count
	count = 0;
}

//Disable the timer
void TIM0_Disable()
{
	TCCR0B &= ~_BV(CS01);
}

//Enable the timer
void TIM0_Enable()
{
	TCCR0B |= _BV(CS01);
}

//Interrupt which activates on the hardware timer ticks
ISR(TIMER0_COMPA_vect)
{
	//Increment the time if it's not max value yet. Else, roll over
	count = (count != 255) ? (count + 1) : 0;
}
