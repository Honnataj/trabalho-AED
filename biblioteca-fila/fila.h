#ifndef FILA_H
#define FILA_H

struct nodo {
  int info;
  struct nodo *prox;
};
typedef struct nodo Nodo;

struct fila {
  Nodo *inicio;
  Nodo *fim;
};
typedef struct fila Fila;

Fila *criarFila();
bool filaVazia(Fila *fila);
void enfileirar(Fila *fila, int elemento);
void desenfileirar(Fila *fila);
int *consultarPrimeiro(Fila *fila);
void destruirFila(Fila *fila);
void imprimirFila(Fila *fila);
bool buscarElemento(Fila *fila, int elemento);
void editarElemento(Fila *fila, int elemento, int novoElemento);
void removerElemento(Fila *fila, int elemento);
void removerRepetidos(Fila *fila);
void removerPares(Fila *fila);

#endif
