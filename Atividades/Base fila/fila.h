#ifndef Fila_H
#define Fila_H
#include <stdbool.h>

typedef struct _Fila Fila;

Fila *Fila_Create(int);
/**
 * Cria instâncias da fila.
 * @param int informando o tamnho maximo da fila.
 * @return Fiha* ponteiro para a Fila.
 */

bool Fila_Insert(Fila*, int);
/**
 * Tenta inserir um elemento inteiro na cauda fila.
 * @return bool informando sobre o sucesso da operação.
 * @param Fila* ponteiro para uma fila.
 * @param int o valor do inteiro para ser inserido na fila.
 */

bool Fila_Remove(Fila*, int*);
/**
 * Tenta remover um elemento na cabeça da fila.
 * @return bool informando sobre o sucesso da operação.
 * @param Fila* ponteiro para a fila.
 * @param int* ponteiro para a variável que receberá o valor.
 */

bool Fila_Head(Fila*, int*);

bool Fila_Tail(Fila*, int*);

bool Fila_Empty(Fila*);

bool Fila_Full(Fila*);

void Fila_Destroyer(Fila*);

#endif