#include "pilha.h"
#include <iostream>

Pilha *criarPilha() {
  Pilha *p = new Pilha;
  p->topo = NULL;
  return p;
}

bool pilhaVazia(Pilha *p) {
  if (p->topo == NULL)
    return true;
  return false;
}

Pilha *empilhar(Pilha *pilha, int valor) {
  Nodo *novo = new Nodo;
  novo->info = valor;
  novo->prox = pilha->topo;
  pilha->topo = novo;
  return pilha;
}

Pilha *desempilhar(Pilha *pilha) {
  Nodo *temp = pilha->topo;
  if (temp != NULL) {
    pilha->topo = temp->prox;
    delete temp;
  }
  return pilha;
}

int *acessarTopo(Pilha *pilha) { return &(pilha->topo->info); }

void destruirPilha(Pilha *pilha) {
  while (pilhaVazia(pilha) == false) {
    pilha = desempilhar(pilha);
  }
}

void imprimirPilha(Pilha *pilha) {
  Pilha *aux = criarPilha();
  while (pilhaVazia(pilha) == false) {
    int infoAux = pilha->topo->info;
    aux = empilhar(aux, infoAux);
    pilha = desempilhar(pilha);
  }
  while (pilhaVazia(aux) == false) {
    int infoAux = aux->topo->info;
    // imprime os valores antes de devolvê-los à pilha
    std::cout << infoAux << std::endl;
    pilha = empilhar(pilha, infoAux);
    aux = desempilhar(aux);
  }
}

// função para iprimir a pilha invertida, na ordem real em que é implementada
void imprimirPilhaInvertida(Pilha *pilha) {
  Pilha *aux = criarPilha();
  while (pilhaVazia(pilha) == false) {
    int infoAux = pilha->topo->info;
    // desta vez, imprime os valores enquanto os coloca na pilha auxiliar
    std::cout << infoAux << std::endl;
    aux = empilhar(aux, infoAux);
    pilha = desempilhar(pilha);
  }
  while (pilhaVazia(aux) == false) {
    int infoAux = aux->topo->info;
    pilha = empilhar(pilha, infoAux);
    aux = desempilhar(aux);
  }
}

bool buscar(Pilha *pilha, int elemento) {
  bool encontrado = false;
  Pilha *aux = criarPilha();
  while (pilhaVazia(pilha) == false) {
    int infoAux = pilha->topo->info;
    if (infoAux == elemento) {
      encontrado = true;
      break;
    }
    aux = empilhar(aux, infoAux);
    pilha = desempilhar(pilha);
  }
  while (pilhaVazia(aux) == false) {
    int infoAux = aux->topo->info;
    pilha = empilhar(pilha, infoAux);
    aux = desempilhar(aux);
  }

  return encontrado;
}

// todos os itens encontrados serão removidos
Pilha *remover(Pilha *pilha, int elemento) {
  Pilha *aux = criarPilha();
  while (pilhaVazia(pilha) == false) {
    int infoAux = pilha->topo->info;
    // apenas adiciona o elemento se ele não for o elemento procurado
    if (infoAux != elemento) {
      aux = empilhar(aux, infoAux);
    }
    pilha = desempilhar(pilha);
  }
  while (pilhaVazia(aux) == false) {
    int infoAux = aux->topo->info;
    pilha = empilhar(pilha, infoAux);
    aux = desempilhar(aux);
  }

  return pilha;
}

Pilha *removerPares(Pilha *pilha) {
  Pilha *aux = criarPilha();
  while (pilhaVazia(pilha) == false) {
    int infoAux = pilha->topo->info;
    if (infoAux % 2 != 0) {
      aux = empilhar(aux, infoAux);
    }
    pilha = desempilhar(pilha);
  }
  while (pilhaVazia(aux) == false) {
    int infoAux = aux->topo->info;
    pilha = empilhar(pilha, infoAux);
    aux = desempilhar(aux);
  }

  return pilha;
}

Pilha *removerRepetidos(Pilha *pilha) {
  Pilha *aux = criarPilha();
  while (pilhaVazia(pilha) == false) {
    int infoAux = pilha->topo->info;

    pilha = desempilhar(pilha);
    if (!buscar(pilha, infoAux)) {
      aux = empilhar(aux, infoAux);
    }
  }
  while (pilhaVazia(aux) == false) {
    int infoAux = aux->topo->info;
    pilha = empilhar(pilha, infoAux);
    aux = desempilhar(aux);
  }

  return pilha;
}
