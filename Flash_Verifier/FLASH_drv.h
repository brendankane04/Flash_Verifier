/*
 * FLASH_drv.h
 *
 * Created: 5/19/2021 7:15:42 PM
 *  Author: brend
 */ 


#ifndef FLASH_DRV_H_
#define FLASH_DRV_H_

void FLASH_init();
unsigned char FLASH_Read(uint32_t);
void FLASH_Write(uint32_t, unsigned char);

#endif /* FLASH_DRV_H_ */