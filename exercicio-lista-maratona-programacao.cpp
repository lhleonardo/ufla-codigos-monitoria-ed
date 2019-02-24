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
    // o parâmetro *valorParaBusca* será comparado com todos os elementos
    // da lista, logo é necessária a sobrecarga do operador de comparação
    // para que funcione corretamente.
    // Caso alguma comparação seja de sucesso, o método retornará True
    // e o elemento desejado estará presente no ponteiro *elementoExistente*
    bool procura(tipo_elemento valorParaBusca, tipo_elemento *elementoExistente);

    // deverá retornar nullptr se índice estiver fora do intervalo
    tipo_elemento* acessa_posicao(unsigned indice);

    // tamanho da lista
    unsigned tamanho();

  private:
    noh<tipo_elemento> *inicio;
    noh<tipo_elemento> *fim;

    unsigned qtdElementos;
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
bool lista_generica<tipo_elemento>::procura(tipo_elemento valorParaBusca, tipo_elemento *elementoExistente) {
    // procurar valorParaBusca na lista. Caso exista algum destes que atenda o critério
    // de igualdade, o mesmo deverá ser feito uma cópia e destinado para
    // elementoExistente.
}

template <class tipo_elemento>
unsigned lista_generica<tipo_elemento>::tamanho() { return this->qtdElementos }

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
    return this->lider == outro.lider == true;
}

class equipe {
  public:
    equipe(string nome, string linguagem);
    ~equipe();

    string acessar_nome();
    string acessar_linguagem();

    void adicionar_integrante(integrante novoMembro, bool definirComoLider);

    unsigned qtd_integrantes();

    void imprimir(ostream& saida);
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
void equipe::adicionar_integrante(integrante novoMembro, bool isLider) {
    if (isLider) novoMembro.define_como_lider();

    if (not this->integrantes->procura(novoMembro, NULL)) {
        this->integrantes->adiciona(novoMembro);
        this->qtd_integrantes++;
    }
}

unsigned equipe::qtd_integrantes() {
    return this->integrantes->tamanho();
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
                // deverá imprimir a lista
            default:
                break;
        }
    } while (leitura != 's');

    delete equipes;
}