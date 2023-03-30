#include <unistd.h>
#include <stdio.h>
#include "timer.h"

void delay_s(int seconds)
{
	sleep(seconds);
}

void delay_m(int minutes, void (*onSecPass)(int, int, float))
{
	for (int s = 0; s <= minutes * 60; s++)
	{
		if (s != 0)
			delay_s(1);

		onSecPass(s, s / 60, (float)s / (minutes * 60)); // Executa a função passando: segundo atual, minuto atual e progresso.
	}
}