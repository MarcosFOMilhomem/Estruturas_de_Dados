#ifndef Lista_H
#define Lista_H
#include <stdbool.h>

typedef struct _Lista Lista;

Lista *Lista_Create();
/**
 * Cria instâncias da Lista.
 * @return Lista* ponteiro para a Lista.
 */

bool Lista_Insert(Lista*, int);
/**
 * Tenta inserir um elemento inteiro na cauda Lista.
 * @return bool informando sobre o sucesso da operação.
 * @param Lista* ponteiro para uma Lista.
 * @param int o valor do inteiro para ser inserido na Lista.
 */

bool Lista_Remove(Lista*, int);

void Lista_Print(Lista*);

bool Lista_Empty(Lista*);

#endif