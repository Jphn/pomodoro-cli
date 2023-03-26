#ifndef NOTIFY_H
#define NOTIFY_H

/**
 * @brief Emite uma notificação que será exibida na tela do usuário.
 *
 * @param title Título que será exibido na notificação.
 * @param message Mensagem contida no corpo da notificação.
 * @param urgency Nível de importância da notificação, pode variar de 1 à 3.
 */
extern void notify(char *title, char *message, int urgency);

#endif