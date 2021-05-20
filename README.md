# Flash_Verifier

Flash verifier is a simple example program to verify that an ATMEGA328p microcontroller can communicate with an
external flash storage unit, specifically an S71271 (datasheet included). The value written is a 
circulating count value incremented by a hardware timer, here the TIM0 of the ATMEGA328p. 

This value is sent over to flash whenever a button is pressed. 

When the sum of the values sent over to and currently in flash cause a roll over, an LED is activated to signal this to the user. When a value is sent over & there is no roll over, the LED is deactivated.

The ATMEGA328p communicates with the flash device via the SPI bus. The ATMEGA328p will issue flash commands via the bus. 

## Files

**FLASH_drv.cpp:** Commands for reading from & writing to the flash memory \
**gpio.cpp:** Controls & interrupts for output status LEDS and an interrupt handler which initiates a write to flash\
**main.cpp:** Main file \
**SPI.cpp:** Functions for sending & receiving SPI commands \
**timer.cpp:** Controls for activating, deactivating, and configuring TIM0 on the ATMEGA328p 

## Important sections of code

**timer.cpp:46:** A hardware timer tick causes a counter to increment. \
**gpio.cpp:59:** A gpio interrupt causes a value to be sent over to flash & a test is done for a roll-over \
**FLASH_drv.cpp:91:** The value sent over to flash is verified & an error is thrown if the write didn't work.

