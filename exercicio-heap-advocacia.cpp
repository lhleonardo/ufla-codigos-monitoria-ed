#include <iostream>

using namespace std;

class Processo {
  public:
    unsigned codigo;
    unsigned prioridade;

    // aqui deverá ter uma sobrecarga de algum operador...
};

template <class TipoElemento>
class MaxHeap {
  public:
    MaxHeap(unsigned int capacidade);

    void adiciona(TipoElemento elemento);

    bool retirarTopo(TipoElemento* retorno);

  private:
    TipoElemento *valores;
    unsigned int qtdElementos;
    unsigned int capacidade;

    inline unsigned int pai(unsigned int posicao);
    inline unsigned int filhoEsquerda(unsigned int posicao);
    inline unsigned int filhoDireita(unsigned int posicao);

    void arruma();
    void corrigeSubindo(unsigned int posicao);
    void corrigeDescendo(unsigned int posicao);

    // caso a heap fique cheia, o método redimensiona deverá ser
    // chamado. O novo tamanho do vetor *valores* fica a escolha.
    void redimensiona();
};

template <class TipoElemento>
MaxHeap<TipoElemento>::MaxHeap(unsigned int capacidade) {
  // ...
}

template <class TipoElemento>
void MaxHeap<TipoElemento>::adiciona(TipoElemento elemento) {
  // ...
}
template <class TipoElemento>
bool MaxHeap<TipoElemento>::retirarTopo(TipoElemento* retorno) {
  // ...
}
template <class TipoElemento>
inline unsigned int MaxHeap<TipoElemento>::pai(unsigned int posicao) {
  // ...
}
template <class TipoElemento>
inline unsigned int MaxHeap<TipoElemento>::filhoEsquerda(unsigned int posicao) {
  // ...
}
template <class TipoElemento>
inline unsigned int MaxHeap<TipoElemento>::filhoDireita(unsigned int posicao) {
  // ...
}
template <class TipoElemento>
void MaxHeap<TipoElemento>::arruma() {
  // ...
}
template <class TipoElemento>
void MaxHeap<TipoElemento>::corrigeSubindo(unsigned int posicao) {
  // ...
}
template <class TipoElemento>
void MaxHeap<TipoElemento>::corrigeDescendo(unsigned int posicao) {
  // ...
}
template <class TipoElemento>
void MaxHeap<TipoElemento>::redimensiona() {
  // ...
}

int main() {
  unsigned qtdInicial;
  cin >> qtdInicial;

  MaxHeap<Processo> dados(qtdInicial);

  char opcao;

  do {
    cin >> opcao;

    switch (opcao) {
      case 'i':
        Processo aux;
        cin >> aux.codigo >> aux.prioridade;

        dados.adiciona(aux);
        break;

      case 'd' :
        Processo aux;
        if (dados.retirarTopo(&aux)) {
          cout << aux.codigo << aux.prioridade << endl;
        } else {
          cout << "Nao encontrado" << endl;
        }
        break;
      default:
        break;
    }
  } while (opcao != 'q');

  return 0;
}