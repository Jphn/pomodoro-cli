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
	int bars = PRO_BAR_LENGTH * progress; // Número de barras a serem mostradas.

	char *bar = malloc(PRO_BAR_LENGTH + 2); // Barra de progresso a ser montada.

	strcat(bar, "["); // Concatena o colchete no começo.

	for (int b = 1; b <= bars; b++)
		strcat(bar, "#"); // Executa o loop adicionado o número de barras.

	for (int s = 1; s <= PRO_BAR_LENGTH - bars; s++)
		strcat(bar, "."); // Executa o loop adicionando o número de pontos para completar o tamanho da barra.

	strcat(bar, "]"); // Concatena o colchete no final da barra.

	return bar;
}

char *colorHandler(float percentage)
{
	return (percentage <= RED_PERCENTAGE)		// Se a porcentagem atual <= porcentagem limite do vermelho.
			   ? RED							// Retorna o código do vermelho.
			   : (percentage <= YEL_PERCENTAGE) // Se a porcentagem atual <= porcentagem limite do amarelo.
					 ? YELLOW					// Retorna o código do amarelo.
					 : GREEN;					// Senão, retorna o código do verde.
}

void updateProgress(int second, int minute, float progress)
{
	int currentSecond = second - 60 * minute; // Calcula o segundo atual, dentro do limite de 0 à 60.
	float percentage = progress * 100;		  // Transforma a taxa de progresso em porcentagem.

	printf(BOLD "\r"); // Transforma as saídas a seguir em negrito e declara que a linha será reescrita com o \r.

	printf("%s", colorHandler(percentage)); // Colore a saída, de acordo com a porcentagem atual.

	printf("%s", mountProgressBar(progress)); // Mostra a barra de progresso posteriormente montada.

	printf(" %.2d%% - %.2d:%.2d", (int)percentage, minute, currentSecond); // Mostra respectivamente, com duas casas decimais: porcentagem, minuto atual e segundo atual.

	fflush(stdout); // Libera a saída montada.
}