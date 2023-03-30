#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notify.h"

void notify(char *title, char *message, int urgencyLevel)
{
	char *urgency, command[300]; // Nível de urgência; Comando a ser montado

	switch (urgencyLevel)
	{
	case 1:
		urgency = "low";
		break;

	default:
		urgency = "normal";
		break;

	case 3:
		urgency = "critical";
		break;
	}

	sprintf(command, "notify-send -u %s \"%s\" \"%s\"", urgency, title, message); // Monta a string do comando de notificação

	system(command); // Executa o comando previamente montado
}