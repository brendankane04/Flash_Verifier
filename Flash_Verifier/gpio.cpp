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
#include "FLASH_drv.h"
#include "timer.h"
#include "gpio.h"

namespace Flash_Verifier
{
	#define ASSERT_LED PORTB0
	#define ERROR_LED PORTB1
	
	//Init function
	void GPIO::init()
	{
		//Initialize the port for blinking as output
		DDRB |= _BV(ASSERT_LED);
		DDRB |= _BV(ERROR_LED);
	
		//Enable the GPIO pin-change interrupt on pin 28
		PCMSK1 |= _BV(PCINT13);
		PCICR |= _BV(PCIE1);
		DDRC &= ~_BV(PORTC5);
	}
	
	//Assert the signal LED
	void GPIO::activate_LED(char pin)
	{
		PORTB |= _BV(pin);
	}
	
	//Deassert the signal LED
	void GPIO::deactivate_LED(char pin)
	{
		PORTB &= ~_BV(pin);
	}
	
	//Display to the user that a terminal error has occurred 
	void GPIO::terminal_blink()
	{
		while(1)
		{
			activate_LED(ERROR_LED);
			_delay_ms(100);
			deactivate_LED(ERROR_LED);
			_delay_ms(100);
		}
	}
	
	//GPIO interrupt which sends over the global count to the flash device
	ISR(PCINT1_vect)
	{
		unsigned char old_val = 0;
		unsigned char new_val = 0;
		unsigned char sum = 0;
	
		//Run only when the signal changes to high
		if(PORTC & _BV(PORTC5))
		{
			old_val = FLASH::read(0xBEEF);	
			new_val = TIM0.get_count();
			sum = old_val + new_val;
	
			if(sum < old_val || sum < new_val)
			{//If the new value rolls over the value in flash
				//Signal a roll-over
				GPIO::activate_LED(ASSERT_LED);
			}
			else
			{//If the new value doesn't roll over the value in flash
				//Signal a lack of a roll-over
				GPIO::deactivate_LED(ASSERT_LED);
			}
	
			FLASH::write(0xBEEF, new_val);
		}
	}
}
