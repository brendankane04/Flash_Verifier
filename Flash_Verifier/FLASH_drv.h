/*
 * FLASH_drv.h
 *
 * Created: 5/19/2021 7:15:42 PM
 *  Author: brend
 */ 


#ifndef FLASH_DRV_H_
#define FLASH_DRV_H_

void FLASH_init();
unsigned char FLASH_Read();
void FLASH_Write(unsigned char);

#endif /* FLASH_DRV_H_ */