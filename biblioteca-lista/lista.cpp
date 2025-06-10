#include "lista.h"
#include <iostream>

Nodo *criarLista() { return NULL; }

bool listaNaoVazia(Nodo *lista) {
  if (lista) {
    return true;
  }
  return false;
}

void inserirInicio(Nodo *&lista, int n) {
  Nodo *novoNodo;
  novoNodo = new Nodo;

  novoNodo->info = n;
  novoNodo->prox = lista;

  lista = novoNodo;
}

void inserirFim(Nodo *&lista, int n) {
  if (listaNaoVazia(lista)) {
    Nodo *aux;
    aux = lista;

    while (listaNaoVazia(aux->prox)) {
      aux = aux->prox;
    }

    aux->prox = NULL;
    inserirInicio(aux->prox, n);
  } else {
    inserirInicio(lista, n);
  }
}

bool buscarElemento(Nodo *lista, int n) {
  if (listaNaoVazia(lista)) {
    Nodo *aux;
    aux = lista;

    do {
      if (aux->info == n) {
        return true;
      }
      aux = aux->prox;
    } while (listaNaoVazia(aux));
  }

  return false;
}

void removerInicio(Nodo *&lista) {
  if (listaNaoVazia(lista)) {
    Nodo *aux;
    aux = lista;

    lista = lista->prox;
    delete aux;
  }
}

void removerFim(Nodo *&lista) {
  if (listaNaoVazia(lista)) {
    Nodo *aux;
    aux = lista;

    Nodo *ant;
    ant = NULL;

    // chega no último elemento
    while (listaNaoVazia(aux->prox)) {
      ant = aux;
      aux = aux->prox;
    }
    if (listaNaoVazia(ant)) {
      ant->prox = NULL;
    } else {
      lista = NULL;
      /* ant estará vazio caso o loop while não tenha sido executado
       * nenhuma vez, ou seja, caso a lista possua apenas um elemento */
    }
    delete aux;
  }
}

void removerElemento(Nodo *&lista, int n) {
  if (listaNaoVazia(lista)) {
    Nodo *aux;
    aux = lista;

    Nodo *ant;
    ant = NULL;

    bool elementoPrimeiro = false;
    bool elementoUltimo = false;

    do {
      if (aux->info == n) {
        if (ant == NULL) {
          elementoPrimeiro = true;
        }
        if (aux->prox == NULL) {
          elementoUltimo = true;
        }

        if (!elementoPrimeiro) {
          if (!elementoUltimo) {
            // elemento no meio
            ant->prox = aux->prox;
          } else {
            // último elemento
            ant->prox = NULL;
          }
        } else {
          // primeiro elemento
          if (!elementoUltimo) {
            lista = aux->prox;
          } else {
            // único elemento
            lista = NULL;
          }
        }

        delete aux;
        break;
      }

      ant = aux;
      aux = aux->prox;
    } while (listaNaoVazia(aux));
  }
}

void imprimirLista(Nodo *lista) {
  if (listaNaoVazia(lista)) {
    Nodo *aux;
    aux = lista;

    for (int i = 1; aux != NULL; i++, aux = aux->prox) {
      std::cout << "Elemento " << i << ": " << aux->info << std::endl;
    }
  } else {
    std::cout << "A lista está vazia!" << std::endl;
  }
}

// EXERCÍCIOS

// supondo que a lista não seja vazia...
int maxLista(Nodo *lista) {
  Nodo *aux;
  aux = lista;
  int max = aux->info;

  for (; aux != NULL; aux = aux->prox) {
    if (aux->info > max) {
      max = aux->info;
    }
  }

  return max;
}

int minLista(Nodo *lista) {
  Nodo *aux;
  aux = lista;
  int min = aux->info;

  for (; aux != NULL; aux = aux->prox) {
    if (aux->info < min) {
      min = aux->info;
    }
  }

  return min;
}

float mediaLista(Nodo *lista) {
  Nodo *aux;
  aux = lista;
  int total = 0;
  int n = 0;

  for (; aux != NULL; aux = aux->prox, n++) {
    total += aux->info;
  }

  float media = (float)total / n;
  return media;
}

int lenLista(Nodo *lista) {
  Nodo *aux;
  aux = lista;
  int len = 0;

  for (; aux != NULL; aux = aux->prox, len++)
    ;

  return len;
}

Nodo *appendLista(Nodo *L1, Nodo *L2) {
  if (listaNaoVazia(L1)) {
    if (listaNaoVazia(L2)) {
      Nodo *aux;
      aux = L1;

      // chega até o último elemento
      for (; aux->prox != NULL; aux = aux->prox)
        ;

      aux->prox = L2;
    } else {
      return L1;
    }
  } else {
    // se L2 não for vazia, retorna L2. Se for vazia, L2 será nulo, então
    // "return L2" terá o mesmo efeito que um "retorn NULL" ao final
    return L2;
  }

  return L1;
}

Nodo *reverseLista(Nodo *lista) {
  Nodo *listaInvertida;
  listaInvertida = criarLista();

  Nodo *aux;
  aux = lista;

  while (aux != NULL) {
    inserirInicio(listaInvertida, aux->info);
    aux = aux->prox;
  }

  return listaInvertida;
}

// talvez seja mais próprio usar bool?
bool isSubLista(Nodo *L1, Nodo *L2) {
  /* sublista seria uma lista em que todos os elementos SÃO IGUAIS a elementos
   na primeira lista? */
  /* ou uma lista em que todos os elementos SÃO elementos da primeira lista? */
  /* vou considerar a primeira opção, em que todos os elementos devem ser
   * iguais, em ordem, aos elementos da primeira lista */
  Nodo *aux1 = L1;
  Nodo *aux2 = L2;

  // o loop acaba quando uma das listas chegar ao fim
  while (aux1 != NULL && aux2 != NULL) {
    if (aux1->info == aux2->info) {
      aux1 = aux1->prox;
      aux2 = aux2->prox;
    } else {
      aux1 = aux1->prox;
      aux2 = L2;
    }
  }

  // aux 2 será NULL se todos os elementos foram comparados
  if (aux2 == NULL) {
    return true;
  }
  return false;
}
