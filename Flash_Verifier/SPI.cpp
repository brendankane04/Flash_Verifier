/*
 * SPI.cpp
 *
 * Created: 5/19/2021 3:16:53 PM
 *  Author: brend
 */ 

#include <stdio.h>
#include <avr/io.h>
#include "SPI.h"

namespace Flash_Verifier
{
	#define DDR_SPI DDRB
	#define CS_FLASH PORTB2
	#define DD_MOSI PORTB3
	#define DD_MISO PORTB4
	#define DD_SCK PORTB5
	
	//Init function
	void SPI::master_init()
	{
		//Initialize the MOSI & SCK pins on PORT C
		DDR_SPI |= _BV(DD_MOSI) | _BV(DD_SCK) ;
	
		//Enable SPI in master mode & set clock rate to f_clk/16
		//Both this device & the flash memory will operate in SPI mode 0
		SPCR |= _BV(SPE) | _BV(MSTR) | _BV(SPR0);
	}
	
	//Send over a byte of data 
	void SPI::master_Tx(unsigned char data)
	{
		//Start the transmission
		SPDR = data;
		
		//Wait until the transmission is over
		while(!(SPSR & _BV(SPIF))) {}
	}
	
	//Receive a byte of data
	unsigned char SPI::master_Rx()
	{
		//Send a dummy byte
		SPDR = 0xFF;
	
		//Wait until data is received
		while(!(SPSR & _BV(SPIF))) {}
	
		return (unsigned char) SPDR;
	}
	
	//Pull the 1 CS line low & select a device & begin communication
	void SPI::select()
	{
		DDR_SPI &= ~_BV(CS_FLASH);
	}
	
	//Pull the 1 CS line high to deselect a device & end communication
	void SPI::deselect()
	{
		DDR_SPI |= _BV(CS_FLASH);
	}
}
