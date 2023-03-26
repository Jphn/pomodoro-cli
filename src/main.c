#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./modules/pmanager.h"

void handleArgs(int argc, char **argv);

int main(int argc, char **argv)
{
	handleArgs(argc, argv);

	manager();

	return 0;
}

void handleArgs(int argc, char **argv)
{
	for (int c = 1; c < argc; c++)
		switch (argv[c][1])
		{
		case 'f':
			cycle[0] = atoi(argv[++c]);
			break;

		case 's':
			cycle[1] = atoi(argv[++c]);
			break;

		case 'l':
			cycle[2] = atoi(argv[++c]);
			break;

		case 'i':
			cycle[3] = atoi(argv[++c]);
			break;
		}
}