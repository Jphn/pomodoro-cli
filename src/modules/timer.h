#ifndef TIMER_H
#define TIMER_H

extern void delay_s(int seconds);
extern void delay_m(int minutes, void (*onSecPass)(int, int, float));

#endif