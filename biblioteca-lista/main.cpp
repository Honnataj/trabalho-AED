#include "lista.h"
#include <iostream>

// para adicionar mensagens às funções
void buscarElementoMen(Nodo *lista, int elemento);
void isSubListaMen(Nodo *L1, Nodo *L2);

int main(void) {
  std::cout << "\nCriando lista...\n";
  Nodo *lista;
  lista = criarLista();
  imprimirLista(lista);

  std::cout << "\nChecando se a lista está vazia...\n";
  if (!listaNaoVazia(lista)) {
    std::cout << "A lista está vazia!\n";
  }

  std::cout << "\nInserindo números no início...\n";
  inserirInicio(lista, 3);
  inserirInicio(lista, 2);
  inserirInicio(lista, 1);
  imprimirLista(lista);

  std::cout << "\nInserindo números no final...\n";
  inserirFim(lista, 7);
  inserirFim(lista, 8);
  inserirFim(lista, 9);
  imprimirLista(lista);

  std::cout << "\nBuscando alguns elementos na lista...\n";
  buscarElementoMen(lista, 3);
  buscarElementoMen(lista, 7);
  buscarElementoMen(lista, 21);
  buscarElementoMen(lista, 0);
  buscarElementoMen(lista, 1);

  std::cout << "\nRemovendo o primeiro elemento da lista...\n";
  removerInicio(lista);
  imprimirLista(lista);

  std::cout << "\nRemovendo o último elemento da lista...\n";
  removerFim(lista);
  imprimirLista(lista);

  std::cout << "\nRemovendo um elemento específico...\n";
  removerElemento(lista, 3);
  imprimirLista(lista);

  std::cout << "\nTentando remover um elemento que não está na lista...\n";
  removerElemento(lista, 21);
  imprimirLista(lista);

  inserirFim(lista, 21);

  std::cout << "\nLista: \n";
  imprimirLista(lista);
  std::cout << "\nMenor elemento: " << minLista(lista)
            << "\nMaior elemento: " << maxLista(lista)
            << "\nMédia: " << mediaLista(lista)
            << "\nTamanho da lista: " << lenLista(lista) << " elementos\n";

  Nodo *lista2;
  lista2 = criarLista();
  inserirInicio(lista2, 80);
  inserirInicio(lista2, 90);
  inserirInicio(lista2, 1812);
  std::cout << "\nLista 2: \n";
  imprimirLista(lista2);

  std::cout << "\nConcatenando as listas\n";
  imprimirLista(appendLista(lista, lista2));

  std::cout << "\nInvertendo as listas...\n";
  imprimirLista(reverseLista(lista));

  std::cout << "\nChecando se lista2 é sublista de lista...\n";
  isSubListaMen(lista, lista2);

  std::cout << "\nChecando se lista é sublista de lista2...\n";
  isSubListaMen(lista2, lista);

  return 0;
}

void buscarElementoMen(Nodo *lista, int elemento) {
  if (buscarElemento(lista, elemento)) {
    std::cout << "Elemento " << elemento << " encontrado!\n";
  } else {
    std::cout << "Elemento " << elemento << " não encontrado!\n";
  }
}

void isSubListaMen(Nodo *L1, Nodo *L2) {
  if (isSubLista(L1, L2)) {
    std::cout << "A lista 2 é uma sublista da lista 1.\n";
  } else {
    std::cout << "A lista 2 NÃO é uma sublista da lista 1.\n";
  }
}
