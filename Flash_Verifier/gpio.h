/*
 * gpio.h
 *
 * Created: 5/18/2021 7:11:03 PM
 *  Author: brend
 */ 


#ifndef GPIO_H_
#define GPIO_H_

class GPIO 
{
	public:
		static void init();
		static void activate_LED(char);
		static void deactivate_LED(char);
		static void terminal_blink();
};

#endif /* GPIO_H_ */