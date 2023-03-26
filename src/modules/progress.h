#ifndef PROGRESS_H
#define PROGRESS_H

/**
 * @brief Tamanho da barra de progresso.
 */
extern const int PRO_BAR_LENGTH;

/**
 * @brief Porcentagem até onde a cor vermelha deve ser apresentada.
 */
extern const int RED_PERCENTAGE;

/**
 * @brief Porcentagem até onde a cor amarela deve ser apresentada.
 */
extern const int YEL_PERCENTAGE;

/**
 * @brief Monta e retorna a barra de progresso para ser devidamente exibida na tela.
 *
 * @param progress Progresso atual do processo efetuado.
 *
 * @return Uma string da barra montada.
 */
extern char *mountProgressBar(float progress);

/**
 * @brief Responsável por lidar com a coloração da barra, conforme as variáveis globais estabelecidas e a mudança do porcentagem do processo executado.
 *
 * @param percentage Porcentagem atual do processo sendo efetuado.
 *
 * @return Caracteres responsáveis por colorir a saída do programa.
 */
extern char *colorHandler(float percentage);

/**
 * @brief Realiza o processo de atualização da barra de progresso exibida na tela.
 *
 * @param second Segundo atual.
 * @param minute Minutagem atual.
 * @param progress Taxa do progresso atual.
 */
extern void updateProgress(int second, int minute, float progress);

#endif