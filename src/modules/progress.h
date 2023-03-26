#ifndef PROGRESS_H
#define PROGRESS_H

extern const int PRO_BAR_LENGTH;

extern char *mountProgressBar(float progress);

extern char *colorHandler(float percentage);

extern void updateProgress(int second, int minute, float progress);

#endif