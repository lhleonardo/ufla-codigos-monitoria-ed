#include <iostream>

using namespace std;

// Representação de um aluno
class Aluno {
    private:
        int _matricula;
        string _nome;
        int _periodo;
    public:
        Aluno(int matricula, string nome, int periodo);

        friend ostream& operator<< (ostream& stream, const Aluno& elemento);
};

Aluno::Aluno(int matricula, string nome, int periodo): 
    _matricula(matricula), _nome(nome), _periodo(periodo) {}

// Operador de escrita sobrescrito para facilitar processo de impressão
ostream& operator<< (ostream& stream, const Aluno& elemento) {
    stream << elemento._matricula << " - " << elemento._nome;
    return stream;
}

// tipo genérico para que a lista armazene qualquer informação
typedef Aluno Dado;

class Noh {
    friend class ListaGenerica;
    private:
        Dado _valor;
        Noh* _proximo;
    public:
        Noh(Dado d): _valor(d), _proximo(nullptr) {} 
};

class ListaGenerica {
    // métodos privados podem ser criados...
    private:
        Noh* _primeiro;
        Noh* _ultimo;

        unsigned _qtd_elementos;

        void adicionar(Noh* novo_noh);
    public:
        ListaGenerica();

        void adicionar(Dado elemento);
        void imprimir(ostream& impressor);

        void inverter();
};

ListaGenerica::ListaGenerica(): 
        _primeiro(nullptr), _ultimo(nullptr), _qtd_elementos(0) {}

void ListaGenerica::adicionar(Noh* novo_noh) {
    if (_qtd_elementos == 0) {
        _primeiro = _ultimo = novo_noh;
    } else {
        _ultimo->_proximo = novo_noh;
        _ultimo = novo_noh;
    }
    ++_qtd_elementos;
}

void ListaGenerica::adicionar(Dado elemento) {
    this->adicionar(new Noh(elemento));
}

// NÃO MODIFICAR! UTILIZADO PARA CORREÇÃO DO DREDD
void ListaGenerica::imprimir(ostream& impressora) {
    impressora << "[";
    for (Noh* iterador = _primeiro; iterador != nullptr; iterador = iterador->_proximo) {
        impressora << iterador->_valor;

        if (iterador != _ultimo)
            impressora << ", ";
    }
    impressora << "]" << endl;
}

// DICA: você pode usar um método auxiliar *privado*, caso necessário
void ListaGenerica::inverter() {
    #warning ListaGenerica::inverter não foi implementado.
}

int main() {
    int qtd_elementos;
    cin >> qtd_elementos;

    int matricula, periodo;
    string nome;

    ListaGenerica lista;

    for (int i = 0; i < qtd_elementos; i++) {
        
        cin >> matricula >> nome >> periodo;
        
        Aluno x(matricula, nome, periodo);

        lista.adicionar(x);
    }

    lista.imprimir(cout);

    lista.inverter();

    lista.imprimir(cout);

    return 0;
}