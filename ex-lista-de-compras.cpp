#include <iostream>

using namespace std;

class ItemCompra {
    public:
        string nome;
        unsigned quantidade;
        // sobrecarga do operador de comparação de igualdade
        bool operator ==(const ItemCompra& outroItem);
        // sobrecarga do operador de impressão
        friend ostream& operator <<(ostream& saida, const ItemCompra& elemento);
};

bool ItemCompra::operator==(const ItemCompra& outroItem) {
    #warning ItemCompra::operator==(const ItemCompra& outroItem) não foi implementado.
}

ostream& operator<<(ostream& saida, const ItemCompra& elemento) {
    #warning ostream& operator<<(ostream& saida, const ItemCompra& elemento) não foi implementado.
}

typedef ItemCompra Dado;

class Noh {
    friend class ListaGenerica;
    private:
        Noh* proximo;
        const Dado valor;
};

class ListaGenerica {
    private:
        Noh* primeiro;
        Noh* ultimo;

        unsigned qtdElementos;
    public:
        ListaGenerica();

        void adiciona(const Dado& valor);
        bool excluir(const Dado& elemento);
        bool procura(const Dado& procurado);

        unsigned tamanho();

        void imprime(ostream& impressora);
};

ListaGenerica::ListaGenerica() {
    #warning ListaGenerica::ListaGenerica() não foi implementado.
}

void ListaGenerica::adiciona(const Dado& valor){
    #warning ListaGenerica::adiciona(const Dado& valor) não foi implementado.
}
bool ListaGenerica::excluir(const Dado& elemento){
    #warning ListaGenerica::excluir(const Dado& elemento) não foi implementado.
}
bool ListaGenerica::procura(const Dado& procurado){
    #warning ListaGenerica::procura(const Dado& procurado) não foi implementado.
}

unsigned ListaGenerica::tamanho(){
    #warning ListaGenerica::tamanho() não foi implementado.
}

void ListaGenerica::imprime(ostream& impressora){
    #warning ListaGenerica::imprime(ostream& impressora) não foi implementado.
    if (this->qtdElementos == 0) {
        impressora << "[]" << endl;
        return;
    } 

    impressora << "[" << endl;

    Noh* iterador = this->primeiro;
    Dado& elemento;

    while (iterador) {
        elemento = iterador->valor;
        impressora << "\t" << "nome: " << 
    }

    impressora << "]" << endl;
}

int main() {
    ListaGenerica lista;
    
    char opcaoLida;
    
    do {
        cin >> opcaoLida; 

        switch(opcaoLida) {
            case 'i' : { // inserção de novo item na lista
                
            }
            case 'r' : { // remover um item presente na lista

            }
            case 'c' : { // consultar se o item está presente na lista. 
                // Formato: nome: {nome}, qtd: {qtd}.  Caso contrário, imprimir item nao existente.
            }
        };
    } while (opcaoLida != 'q');

    return 0;
}