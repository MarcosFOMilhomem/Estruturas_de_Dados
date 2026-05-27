#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _Lista{
    TNo* inicio;
};

Lista* Lista_Create(){
    Lista* novo = malloc(sizeof(Lista));
    if(novo!=NULL){
        novo->inicio = NULL;
    }
    return novo;
}

bool Lista_Insert(Lista *lista, int num){
    TNo *novo = malloc(sizeof(TNo));

    if(novo==NULL)return false;

    novo->info = num;
    novo->prox = NULL;

    if(Lista_Empty(lista) || num < lista->inicio->info){
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return true;
    }

    TNo *ant = lista->inicio;
    TNo *aux = lista->inicio->prox;

    while(aux != NULL && aux->info < num){
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = novo;
    novo->prox = aux;

    return true;
}

void Lista_Print(Lista *lista){
    TNo *aux = lista->inicio;
    printf("\n////////////////");
    while(aux != NULL){
        printf("\n%d",aux->info);
        aux = aux->prox;
    }
}

bool Lista_Empty(Lista *lista){
    if(lista->inicio==NULL)return true;
    return false;
}

bool Lista_Remove(Lista *lista, int num){
    if(Lista_Empty(lista))return false;
    
    if(lista->inicio->info == num){
        lista->inicio = lista->inicio->prox;
        free(lista->inicio);
        return true;
    }

    TNo *ant = lista->inicio;
    TNo *aux = lista->inicio->prox;

    while (aux != NULL && aux->info != num){
        ant = aux;
        aux = aux->prox;
    }
    
    ant->prox = aux->prox;

    free(aux);

    return true;
}