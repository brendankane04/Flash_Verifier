/*
 * FLASH_drv.cpp
 *
 * Created: 5/19/2021 7:15:26 PM
 *  Author: brend
 */ 

#include <stdio.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include "SPI.h"
#include "gpio.h"
#include "timer.h"
#include "FLASH_drv.h"

//Device Commands for the SST25VF016B
//This list of commands can be found on Page 7 of Flash_Datasheet.pdf
#define READ 0x03
#define HIGH_SPEED_READ 0x0B
#define ERASE_4K 0x20
#define ERASE_32K 0x52
#define ERASE_64K 0xD8
#define ERASE_CHIP 0x60
#define BYTE_PRGM 0x02
#define AAI_WORD_PRGM 0xAD
#define RDSR 0x05
#define EWSR 0x50
#define WRSR 0x01
#define WREN 0x06
#define WRDI 0x04
#define RDID 0x90
#define JEDEC_ID 0x9F
#define EBSY 0x70
#define DBSY 0x80

//Init function
void FLASH::init()
{
	SPI::master_init();
}

//Internal function to be used for commands which have addresses
//WARNING: Does not select/deselect the device on its own
void FLASH::CMD_ADDR(unsigned char cmd, uint32_t addr)
{
	SPI::master_Tx(cmd);
	SPI::master_Tx((unsigned char) (addr >>  0));
	SPI::master_Tx((unsigned char) (addr >>  8));
	SPI::master_Tx((unsigned char) (addr >> 16));
}

//Read in 1 byte from the flash memory
unsigned char FLASH::read(uint32_t addr)
{
	unsigned char output;

	//Ensure address is in range
	if(addr > 0x1FFFFF)
		return -1;

	SPI::select();

	//Interface with the device
	FLASH::CMD_ADDR(READ, addr);

	output = SPI::master_Rx();

	//Deselecting the device will end the stream of information coming in
	SPI::deselect();

	return output;
}

//Write in 1 byte to the flash memory
void FLASH::write(uint32_t addr, unsigned char data)
{
	//Ensuring address is compatible
	if(addr > 0x1FFFFF)
		return;

	SPI::select();

	//It's necessary to set write enable before any writing operation
	SPI::master_Tx(WREN);

	//Send over the instruction, the address, then the data
	CMD_ADDR(BYTE_PRGM, addr);
	SPI::master_Tx(data);

	//Deselecting will also  end the write
	SPI::deselect();

	//Verify the data sent over is correct
	if(FLASH::read(addr) != data)
	{//The data didn't write properly
		//Disable the timer, shutdown all interrupts, and display that the program has ended
		TIM0.disable();
		cli();
		GPIO::terminal_blink();
	}
}
