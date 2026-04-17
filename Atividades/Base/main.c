#include <stdio.h>
#include "pilha.h"

int main(){

    int V[] = {1,2,3,4,5};
    Pilha *pilha1 = Pilha_create();

    for(int i = 0; i<5; i++){
        Pilha_push(pilha1, V[i]);
    }

    Pilha_print(pilha1);
    Pilha_print(pilha1);

    return 0;
}