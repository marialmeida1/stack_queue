#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
  int id;
  struct Fila* prox;
} Fila;

typedef struct {
    Fila* inicio;
    Fila* fim;
} FilaEncadeada;

void enqueue(FilaEncadeada* f, int i) {
    Fila* novo = (Fila *)malloc(sizeof(Fila));
    if (novo == NULL) {
        printf("Falha na alocação de memória\n");
        exit(1);
    }
    novo->id = i;
    novo->prox = NULL;
    if (f->fim != NULL) {
        f->fim->prox = novo;
    }
    f->fim = novo;
    if (f->inicio == NULL) {
        f->inicio = novo;
    }
}

int dequeue(FilaEncadeada* f) {
    if (f->inicio == NULL) {
        printf("Fila vazia\n");
        return -1;
    }
    Fila* temp = f->inicio;
    int id = temp->id;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return id;
}

int main(void){

  FilaEncadeada* f = {NULL, NULL};

  for(int i=0; i<5; i++){
    enqueue(&f, i);
  }

  int id = dequeue(&f);
}