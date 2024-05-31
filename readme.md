# Listas, Pilhas e Filas em C

Sou estudante do curso "Algoritmos e Estruturas de Dados 1" e, como parte dos meus estudos, estou explorando tópicos avançados que normalmente são abordados em "Algoritmos e Estruturas de Dados 2". Este repositório contém minhas notas de estudo, exercícios e exemplos de código relacionados à implementação e manipulação de pilhas e filas usando a linguagem de programação C.

## Lista

É um estrutura conhecida como lista encadeada, no qual o primeiro elemento referencia o próximo por meio de um ponteiro em sua estrutura struct. Seu último elemento e ponteiro armazenam um resultado igual a null, destacando assim o fim do procedimento. São armazenados em nós individuais, aonde o ponteiro aponta para o próximo da lista.

![alt text](/assets/image.png)

#### O primeiro da lista é o último adicionado! As listas não seguem ordem de retirada.

```c
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

    for(int i=1; i<=3; i++>){
        l = insere(l, i);
    }
}
```

#### Apontamento:

O primeiro nó da lista criado foi o de id igual 1, entretando é o último a ser apontado pela estrutura.

![alt text](/assets/image-1.png)

## Pilhas

Considerada uma estrutura de dados simples, seu acesso é dado pelo topo dos elementos. Desse modo, "o último a chamar, é o primeiro a sair" (LIFO = Last in, first out).

![alt text](/assets/image-2.png)

#### O último adicionado é o primeiro retirado!

```c
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
```

A estrutura Pilha funciona de modo muito similar com uma Lista até a função pop. Visto que, cria nós os quais chamam os outros nós criados anteriormente. Entretando, na função pop, é retirado o último elemento adicionado a pilha. Dessa maneira, é criado dentro de pop um elemento auxiliar que aponta para o último elemento, fazendo com que ele seja liberado e que p, aponte para o outro elemento da pilha.

#### Apontamento - Função PUSH

![alt text](/assets/image-3.png)

#### Apontamento - Função POP

![alt text](/assets/image-4.png)

## Filas

Em filas a estrutura também seguem regras. Com as filas podemos somente adicionar no final da lista e returar os valores somente no início.

```c
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
```

Para a criação de uma fila temos que ter uma struct auxiliar que possa servir de referência sobre qual é o início e fim da fila. Quando
Em enqueue a primeira função é alocar o fim sempre para um novo nó enquanto que início somente é alocado se a fila estiver vazia, sendo assim, invariável. Já em dequeue pega-se o primeiro valor inserido, ou seja, na struct Fila Encadeada e adiciona a um valor temporário, para que assim ele possa ser excluído. Após atualiza o inicio para outro ponto da fila, desse modo, se tornando variável.

#### Apontamento - Função enqueue

![alt text](/assets/image-5.png)

#### Apontamento - Função dequeue

![alt text](/assets/image-6.png)
