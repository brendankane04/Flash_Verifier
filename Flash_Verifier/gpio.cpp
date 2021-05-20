/*
 * gpio.c
 *
 * Created: 5/18/2021 7:10:44 PM
 *  Author: brend
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void GPIO_init()
{
	//Initialize the port for blinking as output
	DDRB |= _BV(PORTB0);

	//Enable the GPIO pin-change interrupt
	PCMSK1 |= _BV(PCINT13);
	PCICR |= _BV(PCIE1);
	DDRC &= ~_BV(PORTC5);
}

void blink()
{
	PORTB = ~PORTB;
	_delay_ms(100);
}

//GPIO interrupt which sends over the global count to the flash device
ISR(PCINT13_vect)
{
	//Run only when the signal changes to high
	if(PORTC & _BV(PORTC5))
	{

	}
}
