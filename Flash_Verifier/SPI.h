/*
 * SPI.h
 *
 * Created: 5/19/2021 3:17:05 PM
 *  Author: brend
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_Master_init();
void SPI_Master_Tx(char);
char SPI_Master_Rx();
void SPI_Select();
void SPI_Deselect();

#endif /* SPI_H_ */