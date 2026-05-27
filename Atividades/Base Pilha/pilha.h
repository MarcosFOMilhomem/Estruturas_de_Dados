#ifndef Pilha_H
#define Pilha_H
#include <stdbool.h>

typedef struct _Pilha Pilha;

Pilha *Pilha_create();
/**
 * Cria instâncias da pilha estática
 * de tamanho finito;
 * @return Pilha* ponteiro para a pilha
 */

bool Pilha_push(Pilha*, int);
/**
 * Tenta inserir um elemento inteiro na pilha;
 * @return bool informando sobre o sucesso da operação
 * @param Pilha* ponteiro para uma pilha
 * @param int o valor do inteiro para ser inserido na pilha
 */

bool Pilha_pop(Pilha*, int*);
/**
 * Tenta remover um elemento da pilha.
 * @return bool informando sobre o sucesso da operação
 * @param Pilha* ponteiro para a pilha
 * @param int* ponteiro para a variável que receberá o valor
 */

bool Pilha_head(Pilha*, int*);
/**
 * Tenta acessar o elemento do topo sem desempilhar;
 * @return bool informando sobre o sucesso da operação
 * @param Pilha* ponteiro para a pilha
 * @param int* ponteiro para a variável que receberá o valor
 */

void Pilha_destroy(Pilha*)
/**
 * Desaloca os recursos da pilha;
 * @param Pilha* instância de uma pilha
 */
;

//Auxiliares

unsigned int Pilha_len(Pilha*);
/**
 * Devolve a quantidade de elementos atuais da pilha.
 * @param Pilha* instância da pilha
 * @return unsigned int com a quantidade de elementos atuais da pilha;
 */

bool Pilha_is_empty(Pilha*);
/**
 * Retorna se a pilha está atualmente vazia.
 * @param Pilha* instância da pilha
 * @return bool informando se está vazia
 */

bool Pilha_is_full(Pilha*);
/**
 * Retorna se a pilha está atualmente cheia.
 * @param Pilha* instância da pilha
 * @return bool informando se está cheia
 */

void Pilha_print(Pilha*);
/**
 * Printa os dados no termilal
 * @param Pilha* instância da pilha\
 */
#endif