#ifndef PROGRESS_H
#define PROGRESS_H

const int PRO_BAR_LENGTH;
const int RED_PERCENTAGE;
const int YEL_PERCENTAGE;

char *mountProgressBar(float progress);

char *colorHandler(float percentage);

void updateProgress(int second, int minute, float progress);

#endif