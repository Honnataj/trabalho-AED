#include "pilha.h"
#include <iostream>

void pilhaVaziaDc(Pilha *pilha);
void buscarDc(Pilha *pilha, int elemento);

int main(void) {
  Pilha *pilha = criarPilha();

  std::cout << "\nChecando se a pilha está vazia...\n";
  pilhaVaziaDc(pilha);

  std::cout << "\nEmpilhando um item na pilha...\n";
  pilha = empilhar(pilha, 7);
  pilhaVaziaDc(pilha);
  imprimirPilha(pilha);

  std::cout << "\nDesempilhando...\n";
  pilha = desempilhar(pilha);
  pilhaVaziaDc(pilha);
  imprimirPilha(pilha);

  std::cout << "\nEmpilhando três itens na pilha...\n";
  pilha = empilhar(pilha, 1);
  pilha = empilhar(pilha, 2);
  pilha = empilhar(pilha, 3);
  imprimirPilhaInvertida(pilha);

  std::cout << "\nDesempilhando o primeiro item...\n";
  pilha = desempilhar(pilha);
  pilhaVaziaDc(pilha);
  imprimirPilhaInvertida(pilha);

  std::cout << "\nDesempilhando os outros dois itens...\n";
  pilha = desempilhar(pilha);
  pilha = desempilhar(pilha);
  pilhaVaziaDc(pilha);
  imprimirPilhaInvertida(pilha);

  std::cout << "\nEmpilhando alguns valores e fazendo buscas...\n";
  pilha = empilhar(pilha, 10);
  pilha = empilhar(pilha, 21);
  pilha = empilhar(pilha, 32);
  pilha = empilhar(pilha, 50);
  buscarDc(pilha, 21);
  buscarDc(pilha, 43);
  imprimirPilhaInvertida(pilha);

  std::cout << "\nRemovendo um elemento específico da pilha\n";
  buscarDc(pilha, 32);
  pilha = remover(pilha, 32);
  buscarDc(pilha, 32);
  imprimirPilhaInvertida(pilha);

  std::cout
      << "\nRemovendo todos os elementos através da função remover()...\n";
  pilha = remover(pilha, 10);
  pilha = remover(pilha, 21);
  pilha = remover(pilha, 51); // elemento não presente para testar a função
  pilha = remover(pilha, 50);
  imprimirPilhaInvertida(pilha);
  pilhaVaziaDc(pilha);

  std::cout
      << "\nAdicionando valores de 1 a 20 na pilha e removendo os pares...\n";
  for (int i = 1; i <= 20; i++) {
    pilha = empilhar(pilha, i);
  }
  imprimirPilhaInvertida(pilha);
  std::cout << "Removendo pares...\n";
  pilha = removerPares(pilha);
  imprimirPilhaInvertida(pilha);

  std::cout << "\nAdicionando algumas cópias...\n";
  for (int i = 1; i < 20; i += 2) {
    pilha = empilhar(pilha, i);
  }
  for (int i = 0; i < 7; i++) {
    pilha = empilhar(pilha, 21);
  }
  pilha = empilhar(pilha, 1);
  pilha = empilhar(pilha, 7);
  imprimirPilhaInvertida(pilha);
  std::cout << "\nRemovendo as duplicatas...\n";
  pilha = removerRepetidos(pilha);
  imprimirPilhaInvertida(pilha);

  std::cout << "\nDestruindo pilha...\n";
  destruirPilha(pilha);
  imprimirPilhaInvertida(pilha);
  pilhaVaziaDc(pilha);

  std::cout << "\nTestando remoção de duplicatas com conjunto de elementos "
               "reduzido...\n";
  pilha = empilhar(pilha, 1);
  pilha = empilhar(pilha, 2);
  pilha = empilhar(pilha, 3);
  pilha = empilhar(pilha, 1);
  imprimirPilhaInvertida(pilha);
  std::cout << "Removendo duplicatas...\n";
  pilha = removerRepetidos(pilha);
  imprimirPilhaInvertida(pilha);

  return 0;
}

void pilhaVaziaDc(Pilha *pilha) {
  bool vazia = pilhaVazia(pilha);

  if (vazia) {
    std::cout << "A pilha está vazia.\n";
  } else {
    std::cout << "A pilha não está vazia.";
  }
}

void buscarDc(Pilha *pilha, int elemento) {
  bool encontrado = buscar(pilha, elemento);

  if (encontrado) {
    std::cout << "Elemento " << elemento << " encontrado!" << std::endl;
  } else {
    std::cout << "Elemento " << elemento << " não encontrado!" << std::endl;
  }
}
