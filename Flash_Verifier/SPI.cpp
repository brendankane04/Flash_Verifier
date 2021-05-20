/*
 * SPI.cpp
 *
 * Created: 5/19/2021 3:16:53 PM
 *  Author: brend
 */ 

#include <stdio.h>
#include <avr/io.h>

#define DDR_SPI DDRB
#define CS_FLASH PORTB2
#define DD_MOSI PORTB3
#define DD_MISO PORTB4
#define DD_SCK PORTB5

void SPI_Master_init()
{
	//Initialize the MOSI & SCK pins on PORT C
	DDR_SPI |= _BV(DD_MOSI) | _BV(DD_SCK) ;

	//Enable SPI in master mode & set clock rate to f_clk/16
	//Both this device & the flash memory will operate in SPI mode 0
	SPCR |= _BV(SPE) | _BV(MSTR) | _BV(SPR0);
}

void SPI_Master_Tx(unsigned char data)
{
	//Start the transmission
	SPDR = data;
	
	//Wait until the transmission is over
	while(!(SPSR & _BV(SPIF))) {}
}

unsigned char SPI_Master_Rx()
{
	//Send a dummy byte
	SPDR = 0xFF;

	//Wait until data is received
	while(!(SPSR & _BV(SPIF))) {}

	return (unsigned char) SPDR;
}

void SPI_Select()
{
	DDR_SPI &= ~_BV(CS_FLASH);
}

void SPI_Deselect()
{
	DDR_SPI |= _BV(CS_FLASH);
}
