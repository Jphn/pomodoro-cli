#include "timer.h"
#include "progress.h"
#include "notify.h"
#include <stdlib.h>

#include "pmanager.h"

int cycle[4] = {25, 5, 15, 4};

void manager()
{
	int i = 1;

	do
	{
		focus();

		i++;

		if (i == cycle[3])
		{
			i = 1;
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