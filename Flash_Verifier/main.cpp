/*
 * Flash_Verifier.cpp
 *
 * Created: 5/18/2021 2:56:05 PM
 * Author : brend
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "gpio.h"
#include "timer.h"
#include "SPI.h"

int main(void)
{
	GPIO_init();
	TIM0_init();
	//SPI_Master_init();

	//Enable the interrupts
	//sei();

	
	while(1) 
	{
		
	}
}

