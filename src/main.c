#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./modules/pmanager.h"
#include "./modules/colorize.h"

/**
 * @brief Lida com os argumentos passados na execução do binário.
 *
 * @param argc Contador de argumentos que foram passados.
 * @param argv Vetor contendo todos os argumentos.
 */
void handleArgs(int argc, char **argv);

/**
 * @brief Mostra a tela de inicialização.
 */
void startupScreen();

int main(int argc, char **argv)
{
	handleArgs(argc, argv);

	startupScreen();

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

void startupScreen()
{
	char *logo[4][8] = {
		{
			"██████   ██████  ███    ███  ██████  ██████   ██████  ██████   ██████       ██████ ██      ██",
			"██   ██ ██    ██ ████  ████ ██    ██ ██   ██ ██    ██ ██   ██ ██    ██     ██      ██      ██",
			"██████  ██    ██ ██ ████ ██ ██    ██ ██   ██ ██    ██ ██████  ██    ██     ██      ██      ██",
			"██      ██    ██ ██  ██  ██ ██    ██ ██   ██ ██    ██ ██   ██ ██    ██     ██      ██      ██",
			"██       ██████  ██      ██  ██████  ██████   ██████  ██   ██  ██████       ██████ ███████ ██",
		},
		{
			"ooooooooo.     .oooooo.   ooo        ooooo   .oooooo.   oooooooooo.     .oooooo.   ooooooooo.     .oooooo.          .oooooo.   ooooo        ooooo",
			"`888   `Y88.  d8P'  `Y8b  `88.       .888'  d8P'  `Y8b  `888'   `Y8b   d8P'  `Y8b  `888   `Y88.  d8P'  `Y8b        d8P'  `Y8b  `888'        `888'",
			" 888   .d88' 888      888  888b     d'888  888      888  888      888 888      888  888   .d88' 888      888      888           888          888 ",
			" 888ooo88P'  888      888  8 Y88. .P  888  888      888  888      888 888      888  888ooo88P'  888      888      888           888          888 ",
			" 888         888      888  8  `888'   888  888      888  888      888 888      888  888`88b.    888      888      888           888          888 ",
			" 888         `88b    d88'  8    Y     888  `88b    d88'  888     d88' `88b    d88'  888  `88b.  `88b    d88'      `88b    ooo   888       o  888 ",
			"o888o         `Y8bood8P'  o8o        o888o  `Y8bood8P'  o888bood8P'    `Y8bood8P'  o888o  o888o  `Y8bood8P'        `Y8bood8P'  o888ooooood8 o888o",
		},
		{
			"   ▄███████▄  ▄██████▄    ▄▄▄▄███▄▄▄▄    ▄██████▄  ████████▄   ▄██████▄     ▄████████  ▄██████▄        ▄████████  ▄█        ▄█ ",
			"  ███    ███ ███    ███ ▄██▀▀▀███▀▀▀██▄ ███    ███ ███   ▀███ ███    ███   ███    ███ ███    ███      ███    ███ ███       ███ ",
			"  ███    ███ ███    ███ ███   ███   ███ ███    ███ ███    ███ ███    ███   ███    ███ ███    ███      ███    █▀  ███       ███▌",
			"  ███    ███ ███    ███ ███   ███   ███ ███    ███ ███    ███ ███    ███  ▄███▄▄▄▄██▀ ███    ███      ███        ███       ███▌",
			"▀█████████▀  ███    ███ ███   ███   ███ ███    ███ ███    ███ ███    ███ ▀▀███▀▀▀▀▀   ███    ███      ███        ███       ███▌",
			"  ███        ███    ███ ███   ███   ███ ███    ███ ███    ███ ███    ███ ▀███████████ ███    ███      ███    █▄  ███       ███ ",
			"  ███        ███    ███ ███   ███   ███ ███    ███ ███   ▄███ ███    ███   ███    ███ ███    ███      ███    ███ ███▌    ▄ ███ ",
			" ▄████▀       ▀██████▀   ▀█   ███   █▀   ▀██████▀  ████████▀   ▀██████▀    ███    ███  ▀██████▀       ████████▀  █████▄▄██ █▀  ",
		},
		{
			"`7MM\"\"\"Mq.   .g8\"\"8q. `7MMM.     ,MMF' .g8\"\"8q. `7MM\"\"\"Yb.     .g8\"\"8q. `7MM\"\"\"Mq.   .g8\"\"8q.         .g8\"\"\"bgd `7MMF'      `7MMF'",
			"  MM   `MM..dP'    `YM. MMMb    dPMM .dP'    `YM. MM    `Yb. .dP'    `YM. MM   `MM..dP'    `YM.     .dP'     `M   MM          MM  ",
			"  MM   ,M9 dM'      `MM M YM   ,M MM dM'      `MM MM     `Mb dM'      `MM MM   ,M9 dM'      `MM     dM'       `   MM          MM  ",
			"  MMmmdM9  MM        MM M  Mb  M' MM MM        MM MM      MM MM        MM MMmmdM9  MM        MM     MM            MM          MM  ",
			"  MM       MM.      ,MP M  YM.P'  MM MM.      ,MP MM     ,MP MM.      ,MP MM  YM.  MM.      ,MP     MM.           MM      ,   MM  ",
			"  MM       `Mb.    ,dP' M  `YM'   MM `Mb.    ,dP' MM    ,dP' `Mb.    ,dP' MM   `Mb.`Mb.    ,dP'     `Mb.     ,'   MM     ,M   MM  ",
			".JMML.       `\"bmmd\"' .JML. `'  .JMML. `\"bmmd\"' .JMMmmmdP'     `\"bmmd\"' .JMML. .JMM. `\"bmmd\"'         `\"bmmmd'  .JMMmmmmMMM .JMML.",
		}};

	srand(time(NULL));

	int r = rand() % 4;

	printf(BOLD);

	for (int i = 0; i < 8; i++)
		if (logo[r][i] != NULL)
			puts(logo[r][i]);

	printf(REGULAR "\nPressione ENTER para iniciar...");
	getchar();
}