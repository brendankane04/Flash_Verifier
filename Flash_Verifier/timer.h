/*
 * timer.h
 *
 * Created: 5/18/2021 7:08:11 PM
 *  Author: brend
 */ 


#ifndef TIMER_H_
#define TIMER_H_

extern unsigned char count;

void TIM0_init();
void TIM0_Disable();
void TIM0_Enable();

#endif /* TIMER_H_ */