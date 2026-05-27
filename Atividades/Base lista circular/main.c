#include <stdio.h>
#include "Lista_c.h"

int main(){

    Lista *lista1 = Lista_Create();

    int V[] = {1,2,3,4};

    for(int i = 0; i < 4; i++){
        Lista_Insert(lista1, V[i]);
    }

    Lista_Print(lista1);

    Lista_EDMundo(lista1, 4, 2);

    return 0;
}