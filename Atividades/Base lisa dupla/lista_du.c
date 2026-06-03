#include "lista_du.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
    struct _no *ante;
    
}TNo;

struct _Lista{
    TNo* inicio;
    TNo* fim;
};

Lista *Lista_Create(){
    Lista *novo = malloc(sizeof(Lista));
    if(novo!=NULL){
        novo->inicio = NULL;
        novo->fim = NULL;
    }
    return novo;
}

bool TDList_insert_begin(Lista *lista, int num){

    TNo *novo = malloc(sizeof(TNo));

    if(novo == NULL)
        return false;

    novo->info = num;

    if(Lista_Empty(lista)){
        lista->fim = novo;
        novo->prox = NULL;
        novo->ante = NULL;
    }
    else{
        novo->ante = NULL;
        lista->inicio->ante = novo;
        novo->prox = lista->inicio;
    }

    lista->inicio = novo;

    return true;
}

bool TDList_insert_end(Lista *lista, int num){
    TNo *novo = malloc(sizeof(TNo));

    if(novo == NULL)
        return false;

    novo->info = num;

    if(Lista_Empty(lista)){
        lista->inicio = novo;
        novo->prox = NULL;
        novo->ante = NULL;
        return true;
    }
    else{
        novo->prox = NULL;
        lista->fim->prox = novo;
        novo->ante = lista->fim;
    }

    lista->fim = novo;

    return true;
}

void TDList_print(Lista *lista){
    if(Lista_Empty(lista)) return;

    TNo *aux = lista->inicio;

    printf("\n////////////////");

    while(aux != NULL){
        printf("\n%d", aux->info);
        aux = aux->prox;
    }

}

void TDList_reverse_print(Lista *lista){
    if(Lista_Empty(lista)) return;

    TNo *aux = lista->fim;

    printf("\n////////////////");

    while(aux != NULL){
        printf("\n%d", aux->info);
        aux = aux->ante;
    }
}

void TDList_printaz(Lista *lista){
    if(Lista_Empty(lista)){
        printf("Lista vazia\n");
        return;
    }

    printf("%d->%d\n", lista->inicio->info, lista->fim->info);
}

bool Lista_Empty(Lista *lista){
    if(lista->inicio==NULL&&lista->fim==NULL)return true;
    return false;
}