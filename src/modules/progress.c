#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "colorize.h"

#include "progress.h"

const int PRO_BAR_LENGTH = 30;
const int RED_PERCENTAGE = 30;
const int YEL_PERCENTAGE = 70;

char *mountProgressBar(float progress)
{
	int bars = PRO_BAR_LENGTH * progress;

	char *bar = malloc(PRO_BAR_LENGTH + 2);

	strcat(bar, "[");

	for (int b = 1; b <= bars; b++)
		strcat(bar, "#");

	for (int s = 1; s <= PRO_BAR_LENGTH - bars; s++)
		strcat(bar, " ");

	strcat(bar, "]");

	return bar;
}

char *colorHandler(float percentage)
{
	return (percentage <= RED_PERCENTAGE)
			   ? RED
		   : (percentage <= YEL_PERCENTAGE)
			   ? YELLOW
			   : GREEN;
}

void updateProgress(int second, int minute, float progress)
{
	int currentSecond = second - 60 * minute;
	float percentage = progress * 100;

	printf(BOLD "\r");

	printf("%s", colorHandler(percentage));

	printf("%s", mountProgressBar(progress));

	printf(" %.2d%% - %.2d:%.2d", (int)percentage, minute, currentSecond);

	fflush(stdout);
}