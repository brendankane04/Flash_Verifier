/*
 * SPI.h
 *
 * Created: 5/19/2021 3:17:05 PM
 *  Author: brend
 */ 


#ifndef SPI_H_
#define SPI_H_

class SPI 
{
	public:
		static void master_init();
		static void master_Tx(unsigned char);
		static unsigned char master_Rx();
		static void select();
		static void deselect();
};

#endif /* SPI_H_ */