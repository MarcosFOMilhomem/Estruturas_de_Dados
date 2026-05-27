#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _Pilha{
    unsigned int qty;
    TNo* topo;
};

Pilha* Pilha_create(){
    Pilha* novo = malloc(sizeof(Pilha));
    if(novo!=NULL){
        novo->qty = 0;
        novo->topo = NULL;
    }
    return novo;
}

bool Pilha_push(Pilha *pilha, int num){
    TNo *novo = malloc(sizeof(TNo));

    if(novo==NULL)return false;

    novo->info = num;
    novo->prox = pilha->topo;

    pilha->topo = novo;
    pilha->qty++;

    printf("\n%d inserido", pilha->topo->info);
    return true;
}

bool Pilha_pop(Pilha *pilha, int *pilha_num){
    if(pilha->topo == NULL)return false;

    *pilha_num = pilha->topo->info;

    TNo *topo_temp = pilha->topo;

    pilha->topo = pilha->topo->prox;

    free(topo_temp);

    pilha->qty--;

    return true;
}

bool Pilha_head(Pilha *pilha, int *pilha_num){
    if(pilha->topo == NULL)return false;

    *pilha_num = pilha->topo->info;
    return true;
}

void Pilha_destroy(Pilha *pilha){
    int temp;

    while(Pilha_pop(pilha,&temp));
    
    free(pilha);
}

unsigned int Pilha_len(Pilha *pilha){
    if(pilha==NULL)return 0;
    return pilha->qty;
}

bool Pilha_is_empty(Pilha *pilha){
    if(pilha->qty==0)return true;
    return false;
}

bool Pilha_is_full(Pilha *pilha){
    return false;
}

void Pilha_print(Pilha *pilha){
    if (pilha==NULL || pilha->qty==0){
        printf("\nPilha está vazia");
    }
    else{
        printf("\nTopo qty=%d", pilha->qty);
        for(int i = pilha->qty; i!=0; i--){
            printf("\nline%d: %d", pilha->qty,pilha->topo->info);
            pilha->topo = pilha->topo->prox;
        }
    }
}