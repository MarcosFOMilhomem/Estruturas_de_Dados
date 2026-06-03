#ifndef Lista_du_H
#define Lista_du_H
#include <stdbool.h>

typedef struct _Lista Lista;

Lista *Lista_Create();

bool TDList_insert_begin(Lista*, int);

bool TDList_insert_end(Lista*, int);

void TDList_print(Lista*);

void TDList_reverse_print(Lista*);

void TDList_printaz(Lista*);

bool Lista_Empty(Lista*);

#endif