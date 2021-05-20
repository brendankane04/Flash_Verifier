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
#include <util/delay.h>

void GPIO_init()
{
	DDRB |= _BV(PORTB0);
}

void blink()
{
	PORTB = ~PORTB;
	_delay_ms(100);
}
