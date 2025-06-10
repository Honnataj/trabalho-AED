#include "fila.h"
#include <iostream>

Fila *criarFila() {
  Fila *fila = new Fila;
  fila->inicio = NULL;
  fila->fim = NULL;
  return fila;
}

bool filaVazia(Fila *fila) {
  if (fila->inicio == NULL)
    return true;
  return false;
}

void enfileirar(Fila *fila, int elemento) {
  Nodo *novo = new Nodo;
  novo->info = elemento;
  novo->prox = NULL;
  if (filaVazia(fila)) {
    fila->inicio = novo;
    fila->fim = novo;
  } else {
    fila->fim->prox = novo;
    fila->fim = novo;
  }
}

void desenfileirar(Fila *fila) {
  if (!filaVazia(fila)) {
    Nodo *aux;
    aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    delete aux;
    // se a lista ficar vazia,
    // fila será nula
  }
}

int *consultarPrimeiro(Fila *fila) {
  if (!filaVazia(fila)) {
    return &fila->inicio->info;
  }
  return NULL;
}

void destruirFila(Fila *fila) {
  while (!filaVazia(fila)) {
    desenfileirar(fila);
  }
}

void imprimirFila(Fila *fila) {
  Fila *filaAux = criarFila();
  while (!filaVazia(fila)) {
    int elemento = fila->inicio->info;
    enfileirar(filaAux, elemento);
    desenfileirar(fila);
  }
  while (!filaVazia(filaAux)) {
    int elemento = filaAux->inicio->info;
    std::cout << elemento << std::endl;
    enfileirar(fila, elemento);
    desenfileirar(filaAux);
  }
}

bool buscarElemento(Fila *fila, int elemento) {
  bool encontrado = false;
  Fila *filaAux = criarFila();

  while (!filaVazia(fila)) {
    int infoAux = *consultarPrimeiro(fila);
    enfileirar(filaAux, infoAux);
    desenfileirar(fila);
    if (infoAux == elemento) {
      encontrado = true;
    }
  }
  while (!filaVazia(filaAux)) {
    int infoAux = *consultarPrimeiro(filaAux);
    enfileirar(fila, infoAux);
    desenfileirar(filaAux);
  }

  return encontrado;
}

void editarElemento(Fila *fila, int elemento, int novoElemento) {
  Fila *filaAux = criarFila();

  while (!filaVazia(fila)) {
    int infoAux = *consultarPrimeiro(fila);
    desenfileirar(fila);
    if (infoAux == elemento) {
      enfileirar(filaAux, novoElemento);
    } else {
      enfileirar(filaAux, infoAux);
    }
  }
  while (!filaVazia(filaAux)) {
    int infoAux = *consultarPrimeiro(filaAux);
    enfileirar(fila, infoAux);
    desenfileirar(filaAux);
  }
}

void removerElemento(Fila *fila, int elemento) {
  Fila *filaAux = criarFila();

  while (!filaVazia(fila)) {
    int infoAux = *consultarPrimeiro(fila);
    desenfileirar(fila);
    if (infoAux != elemento) {
      enfileirar(filaAux, infoAux);
    }
  }
  while (!filaVazia(filaAux)) {
    int infoAux = *consultarPrimeiro(filaAux);
    enfileirar(fila, infoAux);
    desenfileirar(filaAux);
  }
}

void removerRepetidos(Fila *fila) {
  Fila *filaAux = criarFila();

  while (!filaVazia(fila)) {
    int infoAux = *consultarPrimeiro(fila);
    desenfileirar(fila);
    if (!buscarElemento(fila, infoAux)) {
      enfileirar(filaAux, infoAux);
    }
  }
  while (!filaVazia(filaAux)) {
    int infoAux = *consultarPrimeiro(filaAux);
    desenfileirar(filaAux);
    enfileirar(fila, infoAux);
  }
}

void removerPares(Fila *fila) {
  Fila *filaAux = criarFila();

  while (!filaVazia(fila)) {
    int infoAux = *consultarPrimeiro(fila);
    desenfileirar(fila);
    if (infoAux % 2 != 0) {
      enfileirar(filaAux, infoAux);
    }
  }
  while (!filaVazia(filaAux)) {
    int infoAux = *consultarPrimeiro(filaAux);
    desenfileirar(filaAux);
    enfileirar(fila, infoAux);
  }
}
