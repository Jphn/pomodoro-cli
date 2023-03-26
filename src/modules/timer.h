#ifndef TIMER_H
#define TIMER_H

/**
 * @brief Atrasa a execução do programa em segundos conforme o valor determinado.
 *
 * @param seconds O número inteiro de segundos.
 */
extern void delay_s(int seconds);

/**
 * @brief Atrasa a execução do programa em minutos conforme o valor determinado.
 *
 * @param minutes O número inteiro de minutos.
 * @param onSecPass Função a ser executada conforme a passagem dos segundos.
 */
extern void delay_m(int minutes, void (*onSecPass)(int, int, float));

#endif