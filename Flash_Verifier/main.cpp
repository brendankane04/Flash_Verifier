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
#include <util/delay.h>
#include "int.h"
#include "gpio.h"
#include "timer.h"

int main(void)
{
	GPIO_init();
	TIM0_init();
	int_init();

	while(1) 
	{

	}
}

