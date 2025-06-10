#include "fila.h"
#include <iostream>

void buscarElementoMen(Fila *fila, int n);

int main(void) {
  Fila *fila = criarFila();

  std::cout << "\nChecando se a fila está vazia...\n";
  if (filaVazia(fila)) {
    std::cout << "A fila está vazia!\n";
  }

  std::cout << "\nInserindo alguns valores...\n";
  enfileirar(fila, 1);
  enfileirar(fila, 2);
  enfileirar(fila, 3);
  if (filaVazia(fila) == false) {
    std::cout << "A fila não está vazia!\n";
  } else {
    std::cout << "A fila está vazia!\n";
  }
  imprimirFila(fila);

  std::cout << "\nRemovendo um valor\n";
  desenfileirar(fila);
  imprimirFila(fila);

  std::cout << "\nAdicionando mais alguns valroes...\n";
  enfileirar(fila, 10);
  enfileirar(fila, 21);
  enfileirar(fila, 1812);
  imprimirFila(fila);

  std::cout << "\nConsultando o primeiro valor...\n";
  std::cout << "O primeiro valor é " << *consultarPrimeiro(fila) << std::endl;

  std::cout << "\nDestruindo a fila...\n";
  destruirFila(fila);
  if (filaVazia(fila)) {
    std::cout << "A fila está vazia!\n";
  }

  std::cout << "\nAdicionando elementos novamente...\n";
  enfileirar(fila, 1);
  enfileirar(fila, 2);
  enfileirar(fila, 3);
  enfileirar(fila, 21);
  enfileirar(fila, 1812);
  imprimirFila(fila);

  std::cout << "\nBuscando elementos...\n";
  buscarElementoMen(fila, 2);
  buscarElementoMen(fila, 21);
  buscarElementoMen(fila, 22);
  buscarElementoMen(fila, 0);
  buscarElementoMen(fila, 1);
  buscarElementoMen(fila, 1812);

  std::cout << "\nEditando elementos...\n";
  editarElemento(fila, 1812, 181224);
  editarElemento(fila, 1, 0);
  imprimirFila(fila);

  std::cout << "\nRemovendo elementos...\n";
  removerElemento(fila, 1);
  removerElemento(fila, 0);
  removerElemento(fila, 3);
  imprimirFila(fila);

  std::cout << "\nAdicionando alguns elementos repetidos...\n";
  enfileirar(fila, 21);
  enfileirar(fila, 21);
  enfileirar(fila, 1);
  enfileirar(fila, 2);
  imprimirFila(fila);

  std::cout << "\nRemovendo os repetidos...\n";
  removerRepetidos(fila);
  imprimirFila(fila);

  std::cout << "\nRemovendo os pares...\n";
  removerPares(fila);
  imprimirFila(fila);
}

void buscarElementoMen(Fila *fila, int n) {
  if (buscarElemento(fila, n)) {
    std::cout << "O elemento " << n << " foi encontrado!\n";
  } else {
    std::cout << "O elemento " << n << " não foi encontrado!\n";
  }
}
