/*
 * timer.h
 *
 * Created: 5/18/2021 7:08:11 PM
 *  Author: brend
 */ 


#ifndef TIMER_H_
#define TIMER_H_

class Timer
{
	unsigned char count;

	public:
		void init();
		void disable();
		void enable();
		void inc_count();
		unsigned char get_count();
};

extern Timer TIM0;

#endif /* TIMER_H_ */