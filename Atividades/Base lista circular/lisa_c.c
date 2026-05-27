#include "Lista_c.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _Lista{
    TNo* inicio;
};

Lista *Lista_Create(){
    Lista *novo = malloc(sizeof(Lista));
    if(novo!=NULL){
        novo->inicio = NULL;
    }
    return novo;
}

bool Lista_Insert(Lista *lista, int num){

    TNo *novo = malloc(sizeof(TNo));

    if(novo == NULL)
        return false;

    novo->info = num;

    if(Lista_Empty(lista)){
        lista->inicio = novo;
        novo->prox = novo;
        return true;
    }

    TNo *aux = lista->inicio;

    while(aux->prox != lista->inicio){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->prox = lista->inicio;

    return true;
}

bool Lista_Remove(Lista *lista, int num){

    if(Lista_Empty(lista))return false;

    TNo *aux = lista->inicio;
    TNo *ant = NULL;

    if(aux->info == num){
        if(aux->prox == lista->inicio){

            free(aux);
            lista->inicio = NULL;

            return true;
        }

        TNo *ultimo = lista->inicio;

        while(ultimo->prox != lista->inicio){
            ultimo = ultimo->prox;
        }

        ultimo->prox = aux->prox;
        lista->inicio = aux->prox;

        free(aux);

        return true;
    }

    ant = aux;
    aux = aux->prox;

    while(aux != lista->inicio && aux->info != num){

        ant = aux;
        aux = aux->prox;
    }

    if(aux == lista->inicio)return false;

    ant->prox = aux->prox;

    free(aux);

    return true;
}

void Lista_Print(Lista *lista){
    TNo *aux = lista->inicio;

    if(aux!=NULL){
        printf("\n////////////////");
        do{
            printf("\n%d",aux->info);
            aux = aux->prox;
        }while(aux!=lista->inicio);
    }
    
}

bool Lista_Empty(Lista *lista){
    if(lista->inicio==NULL)return true;
    return false;
}

bool Lista_EDMundo(Lista *lista, int total, int num){
    if(Lista_Empty(lista))return false;

    TNo *aux = lista->inicio;

    while(total!=1){
        for(int i = 0; i<num; i++){
            aux = aux->prox;
        }
        Lista_Remove(lista,aux->info);
        total--;
        aux = aux->prox;
        Lista_Print(lista);
    }

    printf("\n%d vencedor", aux->info);
    
    return true;
}