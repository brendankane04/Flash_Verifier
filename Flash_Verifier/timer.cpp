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

namespace Flash_Verifier
{
	Timer TIM0 = Timer();

	//Default Constructor
	Timer::Timer()
	{
		Timer(TIM0_DEV);
	}

	Timer::Timer(char type)
	{
		this->type = type;

		if(type == TIM0_DEV)
		{//Initialize TIM0
			//Set mode to count-to-compare
			TCCR0A |= _BV(WGM01);
		
			//Set value maximum count value to 250
			OCR0A = 250;
			
			//Set the interrupt for the overflow timer
			TIMSK0 |= _BV(OCIE0A);
			
			//Initialize the hardware count
			count = 0;
			
			//Set the clock select bits to activate the clock
			TCCR0B |= _BV(CS01) | _BV(CS01);
		}
		else
		{//Initialize TIM1
			//Set the control registers to set count-to-compare mode
			TCCR1A |= 0;
			TCCR1B |= _BV(WGM12);

			//Set the maximum count value to 500, which makes TIM1 half as fast as TIM0
			OCR1A = 500;

			//Set the interrupt for the overflow timer
			TIMSK1 |= _BV(OCIE1A);

			//Initialize the hardware count
			count = 0;
			
			//Set the clock select bits to activate the clock
			TCCR1B |= _BV(CS11) | _BV(CS01);
		}
	}
	
	//Disable the timer
	 void Timer::disable()
	{
		if(type == TIM0_DEV)
		{
			TCCR0B &= ~_BV(CS01);
		}
		else
		{
			TCCR1B &= ~_BV(CS11);
		}
	}
	
	//Enable the timer
	void Timer::enable()
	{
		if(type == TIM0_DEV)
		{
			TCCR0B |= _BV(CS01);
		}
		else
		{
			TCCR0B |= _BV(CS11);
		}
	}
	
	//Increment the time if it's not max value yet. Else, roll over
	void Timer::inc_count()
	{
		count = (count != 255) ? (count + 1) : 0;
	}
	
	//Get method
	unsigned char Timer::get_count()
	{
		return count;
	}
	
	//Interrupt which activates on the hardware timer ticks
	ISR(TIMER0_COMPA_vect)
	{
		TIM0.inc_count();
	}

	/*
	 * Alias the TIM1 interrupt to the TIM0 interrupt,
	 * so both of the interrupts are the same
	 */
	ISR_ALIAS(TIMER1_COMPA_vect, TIMER0_COMPA_vect);
}
