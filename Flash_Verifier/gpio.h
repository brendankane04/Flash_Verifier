/*
 * gpio.h
 *
 * Created: 5/18/2021 7:11:03 PM
 *  Author: brend
 */ 


#ifndef GPIO_H_
#define GPIO_H_

void GPIO_init();
void activate_LED(char);
void deactivate_LED(char);
void terminal_blink();

#endif /* GPIO_H_ */