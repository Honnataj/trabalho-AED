#ifndef PILHA_H
#define PILHA_H

struct nodo {
  int info;
  struct nodo *prox;
};
typedef struct nodo Nodo;

struct pilha {
  Nodo *topo;
};
typedef struct pilha Pilha;

Pilha *criarPilha();
bool pilhaVazia(Pilha *p);
Pilha *empilhar(Pilha *pilha, int valor);
Pilha *desempilhar(Pilha *pilha);
int *acessarTopo(Pilha *pilha);
void destruirPilha(Pilha *pilha);
void imprimirPilha(Pilha *pilha);
void imprimirPilhaInvertida(Pilha *pilha);
bool buscar(Pilha *pilha, int elemneto);
Pilha *remover(Pilha *pilha, int elemento);
Pilha *removerPares(Pilha *pilha);
Pilha *removerRepetidos(Pilha *pilha);

#endif
