#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
  int id;
  struct Pilha* prox;
} Pilha;

Pilha* push(Pilha* p, int i){
  Pilha* new = (Pilha *) malloc(sizeof(Pilha));
  if(new == NULL){
    return;
  }
  new->id= i;
  new->prox = p;
  return new;
}

Pilha* pop(Pilha* p){
  if(p == NULL){
    return;
  }

  Pilha* temp = p;
  p = p->prox;
  free(temp);
  return p;
}

int main(void){

  Pilha* p = NULL;

  for(int i=0; i<3; i++){
    p = push(p, i);
  }

  p = pop(p);
}