#include "timer.h"
#include "progress.h"
#include "notify.h"
#include <stdlib.h>

#include "pmanager.h"

int cycle[4] = {25, 5, 15, 4};

void manager()
{
	int c = 0;

	do
	{
		system("clear");

		focus();
		c++;

		system("clear");

		if (c == cycle[3]) // Confere se deve executar o descanso longo
		{
			c = 0;
			longBreak();
		}
		else
			shortBreak();
	} while (1);
}

void focus()
{
	notify("Pomo CLI - Focus", "Time to work!", 2);

	delay_m(cycle[0], updateProgress);
}

void shortBreak()
{
	notify("Pomo CLI - Break", "Take a short break...", 2);

	delay_m(cycle[1], updateProgress);
}

void longBreak()
{
	notify("Pomo CLI - Long Break", "You can rest a lite more now...", 2);

	delay_m(cycle[2], updateProgress);
}