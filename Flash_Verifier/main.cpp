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
#include "GPIO.h"
#include "TIMER.h"
#include "SPI.h"
#include "FLASH_DRV.h"

using namespace std;

int main(void)
{
	Flash_Verifier::GPIO::init();
	Flash_Verifier::TIM0.init();
	Flash_Verifier::SPI::master_init();
	Flash_Verifier::FLASH::init();

	//Enable the interrupts
	sei();

	while(1) 
	{

	}
}
