#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _Fila{
    unsigned int qty;
    int max;
    TNo *head;
    TNo *tail;
};

Fila *Fila_Create(int max){
    Fila *novo = malloc(sizeof(Fila));
    if(novo!=NULL){
        novo->qty = 0;
        novo->max = max;
        novo->head = NULL;
        novo->tail = NULL;
    }
    printf("fila criada");
    return novo;
}

bool Fila_Empty(Fila *fila){
    if(fila->qty==0)return true;
    return false;
}

bool Fila_Full(Fila *fila){
    if(fila->qty>=fila->max){
        printf("\nFila está cheia");
        return true;
    }
    return false;
}

bool Fila_Insert(Fila *fila, int num){
    if(Fila_Full(fila))return false;

    TNo *novo = malloc(sizeof(TNo));
    if(novo==NULL)return false;

    novo->info = num;
    novo->prox = NULL;

    if(Fila_Empty(fila)){
        fila->head = novo;
        fila->tail = novo;
    }
    else{
        fila->tail->prox = novo;
        fila->tail = novo;
    }
    fila->qty++;
    printf("\n%d Inserido", num);
    return true;
}

bool Fila_Remove(Fila *fila, int *num){
    if(Fila_Empty(fila)){
        printf("\nFila já está vazia");
        return false;
    }

    *num = fila->head->info;

    TNo *temp = fila->head;

    fila->head = fila->head->prox;

    if(fila->head == NULL)fila->tail = NULL;

    free(temp);

    fila->qty--;

    return true;
}

bool Fila_Head(Fila *fila, int *num){
    if(Fila_Empty(fila))return false;
    *num = fila->head->info;
    return true;
}

bool Fila_Tail(Fila *fila, int *num){
    if(Fila_Empty(fila))return false;
    *num = fila->tail->info;
    return true;
}

void Fila_Destroyer(Fila *fila){
    int temp;
    while(!Fila_Empty(fila)){
        Fila_Remove(fila, &temp);
    }
    free(fila);
    printf("\nFila apagada");
}