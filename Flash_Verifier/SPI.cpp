/*
 * SPI.cpp
 *
 * Created: 5/19/2021 3:16:53 PM
 *  Author: brend
 */ 

#include <stdio.h>
#include <avr/io.h>

#define DDR_SPI DDRC
#define DD_MOSI 5
#define DD_MISO 4
#define DD_SCK 3

void SPI_Master_init()
{
	//Initialize the MOSI & SCK pins on PORT C
	DDR_SPI |= _BV(DD_MOSI) | _BV(DD_SCK);

	//Enable SPI in master mode & set clock rate to fck/16
	SPCR |= _BV(SPE) | _BV(MSTR) | _BV(SPR0);
}

void SPI_Slave_init()
{
	//Set MISO to output & all others to input
	DDR_SPI = _BV(DD_MISO);

	//Enable SPI & set clock rate to fck/16
	SPCR |= _BV(SPE) | _BV(SPR0);
}

void SPI_Master_Transmit(char data)
{
	//Start the transmission
	SPDR = data;
	
	//Wait until the transmission is over
	while(!(SPSR & _BV(SPIF))) {}
}

char SPI_Slave_Receive()
{
	//Wait until data is received
	while(!(SPSR & _BV(SPIF))) {}

	return SPDR;
}
