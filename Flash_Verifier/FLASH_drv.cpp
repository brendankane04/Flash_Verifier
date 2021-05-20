/*
 * FLASH_drv.cpp
 *
 * Created: 5/19/2021 7:15:26 PM
 *  Author: brend
 */ 

#include "SPI.h"

//Device Commands for the SST25VF016B
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

void FLASH_init()
{
	SPI_Master_init();
}

char FLASH_Read()
{
	
}

void FLASH_Write(char data)
{
	
}
