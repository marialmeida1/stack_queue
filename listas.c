#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int id;
    struct Lista* prox;
} Lista;

Lista* insere(Lista* l, int i){
    Lista* new = (Lista *) malloc(sizeof(Lista));
    new->id = i;
    new->prox = l;
    return new;
}

int main(void) {
    Lista *l = NULL;

    for(int i=1; i<=3; i++){
        l = insere(l, i);
    }
}