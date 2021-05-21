/*
 * FLASH_drv.h
 *
 * Created: 5/19/2021 7:15:42 PM
 *  Author: brend
 */ 


#ifndef FLASH_DRV_H_
#define FLASH_DRV_H_

class FLASH
{
	static void CMD_ADDR(unsigned char, uint32_t);

	public:
		static void init();
		static unsigned char read(uint32_t);
		static void write(uint32_t, unsigned char);
};

#endif /* FLASH_DRV_H_ */