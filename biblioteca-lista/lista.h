#ifndef LISTA_H
#define LISTA_H

struct nodo {
  int info;
  struct nodo *prox;
};

typedef struct nodo Nodo;

Nodo *criarLista();
bool listaNaoVazia(Nodo *lista);
void inserirInicio(Nodo *&lista, int n);
void inserirFim(Nodo *&lista, int n);
bool buscarElemento(Nodo *lista, int n);
void removerInicio(Nodo *&lista);
void removerFim(Nodo *&lista);
void removerElemento(Nodo *&lista, int n);
void imprimirLista(Nodo *lista);
// funções adicionais para os exercícios
// 1. PERCURSO
int maxLista(Nodo *lista);
int minLista(Nodo *lista);
float mediaLista(Nodo *lista);
int lenLista(Nodo *lista);
// 2. CONCATENAÇÃO
Nodo *appendLista(Nodo *L1, Nodo *L2);
// 3. INVERSÃO
Nodo *reverseLista(Nodo *lista);
// 4. SUB
bool isSubLista(Nodo *L1, Nodo *L2);

#endif
