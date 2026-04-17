#include <stdio.h>
#include "fila.h"

int main(){

    int V[] = {1,2,3,4,5}; 
    int valor;

    Fila *fila1 = Fila_Create(5);

    // Inserindo
    for(int i = 0; i < 5; i++){
        Fila_Insert(fila1, V[i]);
    }

    // Testando head
    if(Fila_Head(fila1, &valor)){
        printf("\nHead: %d\n", valor);
    }

    // Testando tail
    if(Fila_Tail(fila1, &valor)){
        printf("Tail: %d\n", valor);
    }

    Fila_Insert(fila1, 10);

    // Removendo tudo
    printf("\nRemovendo elementos:\n");
    while(Fila_Remove(fila1, &valor)){
        printf("%d ", valor);
    }

    printf("\n");

    // Destruindo fila
    Fila_Destroyer(fila1);

    return 0;
}