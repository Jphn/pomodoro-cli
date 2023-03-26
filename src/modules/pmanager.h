#ifndef PMANAGER_H
#define PMANAGER_H

/**
 * @brief Array de inteiros com tamanho 4 que representa, respectivamente: tempo de foco, descanso curto, descanso longo e intervalo entre as pausas.
 */
extern int cycle[4];

/**
 * @brief Principal responsável por executar o pomodoro.
 * Realiza um loop eterno entre as demais funções e gerencia quando o descanso longo ou curto é executado.
 */
extern void manager();

/**
 * @brief Executa o timer de foco. Conforme o valo em cycle[0] em minutos.
 */
extern void focus();

/**
 * @brief Executa o timer de foco. Conforme o valo em cycle[1] em minutos.
 */
extern void shortBreak();

/**
 * @brief Executa o timer de foco. Conforme o valo em cycle[2] em minutos.
 */
extern void longBreak();

#endif