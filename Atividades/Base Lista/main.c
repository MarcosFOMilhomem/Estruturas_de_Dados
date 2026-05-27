#include <stdio.h>
#include "Lista.h"

int main(){

    Lista *lista1 = Lista_Create();

    int V[] = {5,3,2,1,7,4,6};

    for(int i = 0; i < 7; i++){
        Lista_Insert(lista1, V[i]);
    }

    Lista_Print(lista1);
    
    Lista_Remove(lista1, 7);

    Lista_Print(lista1);

    Lista_Remove(lista1, 5);

    Lista_Print(lista1);
    
    Lista_Remove(lista1, 1);

    Lista_Print(lista1);

    return 0;
}