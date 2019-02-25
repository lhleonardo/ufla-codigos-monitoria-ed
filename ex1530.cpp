#include <iostream>

using namespace std;

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

ostream& operator<< (ostream& stream, const Aluno& elemento) {
    stream << elemento._matricula << " - " << elemento._nome;
    return stream;
}

// tipo genérico para que a lista armazene qualquer informação
typedef Aluno Dado;

class Noh {
    friend class ListaEncadeada;
    private:
        Dado _valor;
        Noh* _proximo;
    public:
        Noh(Dado d): _valor(d), _proximo(nullptr) {} 
};

class ListaEncadeada {
    private:
        Noh* _primeiro;
        Noh* _ultimo;

        unsigned _qtd_elementos;
        
        void adicionar(Noh* novo_noh);
        void inverter_aux(Noh* elemento_atual);
    public:
        ListaEncadeada();

        void adicionar(Dado elemento);
        void imprimir(ostream& impressor);

        void inverter();
};

ListaEncadeada::ListaEncadeada(): 
        _primeiro(nullptr), _ultimo(nullptr), _qtd_elementos(0) {}

void ListaEncadeada::adicionar(Noh* novo_noh) {
    if (_qtd_elementos == 0) {
        _primeiro = _ultimo = novo_noh;
    } else {
        _ultimo->_proximo = novo_noh;
        _ultimo = novo_noh;
    }
    ++_qtd_elementos;
}

void ListaEncadeada::adicionar(Dado elemento) {
    this->adicionar(new Noh(elemento));
}

void ListaEncadeada::imprimir(ostream& impressora) {
    impressora << "[";
    for (Noh* iterador = _primeiro; iterador != nullptr; iterador = iterador->_proximo) {
        impressora << iterador->_valor;

        if (iterador != _ultimo)
            impressora << ", ";
    }
    impressora << "]" << endl;
}

void ListaEncadeada::inverter() {
    if (_qtd_elementos > 1) {
        Noh* atual = _primeiro;
        _primeiro = _primeiro->_proximo;

        _qtd_elementos--;

        inverter_aux(atual);

        atual->_proximo = nullptr;
        adicionar(atual);
    }
}

void ListaEncadeada::inverter_aux(Noh* elemento_atual) {
    if (_qtd_elementos > 0) {
        Noh* atual = _primeiro;
        _primeiro = _primeiro->_proximo;

        _qtd_elementos--;

        inverter_aux(atual);

        atual->_proximo = nullptr;
        adicionar(atual);
    } else {
        _primeiro = nullptr;
        _ultimo = nullptr;
    }
}

int main() {
    int qtd_elementos;
    cin >> qtd_elementos;

    int matricula, periodo;
    string nome;

    ListaEncadeada lista;

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