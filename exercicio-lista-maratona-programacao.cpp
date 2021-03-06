#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::ostream;

template <class tipo_elemento>
class noh {
    friend class lista_generica;

  private:
    tipo_elemento dado;
    noh *proximo;
};

// lista com encadeamento simples
template <class tipo_elemento>
class lista_generica {
  public:
    lista_generica();
    ~lista_generica();

    // adiciona um novo elemento na lista
    void adiciona(tipo_elemento valor);

    // percorre a lista e devolve o elemento presente
    // o parâmetro *valor_para_busca* será comparado com todos os elementos
    // da lista, logo é necessária a sobrecarga do operador de comparação
    // para que funcione corretamente.
    // Caso alguma comparação seja de sucesso, o método retornará True
    // e o elemento desejado estará presente no ponteiro *elemento_existente*
    bool procura(tipo_elemento valor_para_busca, tipo_elemento *elemento_existente);

    // deverá retornar nullptr se índice estiver fora do intervalo
    tipo_elemento* acessa_posicao(unsigned indice);

    // tamanho da lista
    unsigned tamanho();

  private:
    noh<tipo_elemento> *inicio;
    noh<tipo_elemento> *fim;

    unsigned qtd_elementos;
};

template <class tipo_elemento>
lista_generica<tipo_elemento>::lista_generica() {
    // iniciar atributos
}

template <class tipo_elemento>
lista_generica<tipo_elemento>::~lista_generica() {
    // desalocar valores em memória
}

template <class tipo_elemento>
void lista_generica<tipo_elemento>::adiciona(tipo_elemento valor) {
    // adicionar elemento na lista
}

template <class tipo_elemento>
bool lista_generica<tipo_elemento>::procura(tipo_elemento valor_para_busca, tipo_elemento *elemento_existente) {
    // procurar valor_para_busca na lista. Caso exista algum destes que atenda o critério
    // de igualdade, o mesmo deverá ser feito uma cópia e destinado para
    // elemento_existente.
}

template <class tipo_elemento>
unsigned lista_generica<tipo_elemento>::tamanho() { return this->qtd_elementos }

class integrante {
  public:
    integrante(string nome, string nickname);

    void define_como_lider();

    string acessar_nome();
    string acessar_nickname();

    bool operator==(const integrante& outro);

  private:
    string nome;
    string nickname;

    bool lider;
};

integrante::integrante(string nome, string nickname) {
    // inicializar as variáveis
}

string integrante::acessar_nome() {
    return this->nome;
}

string integrante::acessar_nickname() {
    return this->nickname;
}

void integrante::define_como_lider() {
    this->lider = true;
}

bool integrante::operator==(const integrante& outro) {
    // critério para comparação entre dois integrantes: nickname
}

class equipe {
  public:
    equipe(string nome, string linguagem);
    ~equipe();

    string acessar_nome();
    string acessar_linguagem();

    void adicionar_integrante(integrante novo_membro, bool is_lider);

    unsigned qtd_integrantes();

    void imprimir(ostream& saida);

    bool operator ==(const equipe& outra_equipe);
  private:
    string nome;
    string linguagem;

    // uma lista de integrantes...
    lista_generica<integrante> *integrantes;
};

equipe::equipe(string nome, string linguagem) {
    // inicializar as variáveis...
}

equipe::~equipe() {
    // destruir alocações caso realizadas
}

string equipe::acessar_nome() {
    return this->nome;
}

string equipe::acessar_linguagem() {
    return this->linguagem;
}

void equipe::imprimir(ostream& saida){
    // ...
}

// deve verificar se já existe algum lider da equipe antes...
void equipe::adicionar_integrante(integrante novo_membro, bool is_lider) {
    // ...
}

unsigned equipe::qtd_integrantes() {
    return this->integrantes->tamanho();
}

bool equipe::operator==(const equipe& outra_equipe) {
    // critério de comparação entre equipes: nome
}

int main() {
    char leitura;

    lista_generica<equipe>* equipes = new lista_generica<equipe>();

    do {
        cin >> leitura;

        switch (leitura)
        {
            case 'i':
                // fazer a leitura dos dados de uma equipe e inserir na lista
                break;
            case 'p':
                // deverá imprimir a lista no formato especificado
                break;
            case 'b':
                // deverá procurar por uma equipe a partir de seu nome
                break;
            case 'a':
                // deverá retirar uma equipe da lista
                break;
            default:
                break;
        }
    } while (leitura != 's');

    delete equipes;
}