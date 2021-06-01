/*
 * timer.h
 *
 * Created: 5/18/2021 7:08:11 PM
 *  Author: brend
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#define TIM0_DEV 0
#define TIM1_DEV 1

namespace Flash_Verifier
{
	class Timer
	{
		char type;
		unsigned char count;
	
		public:
			Timer();
			Timer(char type);
			void disable();
			void enable();
			void inc_count();
			unsigned char get_count();
	};

	extern Timer TIM0;
}

#endif /* TIMER_H_ */