#include <iostream>

using std::string;
using std::cin;
using std::cout;

template <class TipoElemento>
class Noh {
    friend class ListaGenerica;

  private:
    TipoElemento dado;
    Noh *proximo;
};

// lista com encadeamento simples
template <class TipoElemento>
class ListaGenerica {
  public:
    ListaGenerica();
    ~ListaGenerica();

    // adiciona um novo elemento na lista
    void adiciona(TipoElemento valor);

    // percorre a lista e devolve o elemento presente
    // o parâmetro *valorParaBusca* será comparado com todos os elementos
    // da lista, logo é necessária a sobrecarga do operador de comparação
    // para que funcione corretamente.
    // Caso alguma comparação seja de sucesso, o método retornará True
    // e o elemento desejado estará presente no ponteiro *elementoExistente*
    bool procura(TipoElemento valorParaBusca, TipoElemento *elementoExistente);

    // tamanho da lista
    unsigned tamanho();

  private:
    Noh<TipoElemento> *inicio;
    Noh<TipoElemento> *fim;

    unsigned qtdElementos;
};

template <class TipoElemento>
ListaGenerica<TipoElemento>::ListaGenerica() {
    // iniciar atributos
}

template <class TipoElemento>
ListaGenerica<TipoElemento>::~ListaGenerica() {
    // desalocar valores em memória
}

template <class TipoElemento>
void ListaGenerica<TipoElemento>::adiciona(TipoElemento valor) {
    // adicionar elemento na lista
}

template <class TipoElemento>
bool ListaGenerica<TipoElemento>::procura(TipoElemento valorParaBusca, TipoElemento *elementoExistente) {
    // procurar valorParaBusca na lista. Caso exista algum destes que atenda o critério
    // de igualdade, o mesmo deverá ser feito uma cópia e destinado para
    // elementoExistente.
}

template <class TipoElemento>
unsigned ListaGenerica<TipoElemento>::tamanho() { return this->qtdElementos }

class Integrante {
  public:
    Integrante(string nome, string nickname);

    void defineComoLider();

    string getNome();
    string getNickname();

    bool operator==(const Integrante& outro);

  private:
    string nome;
    string nickname;

    bool lider;
};

Integrante::Integrante(string nome, string nickname) {
    // inicializar as variáveis
}

string Integrante::getNome() {
    return this->nome;
}

string Integrante::getNickname() {
    return this->nickname;
}

void Integrante::defineComoLider() {
    this->lider = true;
}

bool Integrante::operator==(const Integrante& outro) {
    return this->lider == outro.lider == true;
}

class Equipe {
  public:
    Equipe(string nome, string linguagem);
    ~Equipe();

    string getNome();
    string getLinguagem();

    void adicionarIntegrante(Integrante novoMembro, bool definirComoLider);

    unsigned qtdIntegrantes();
  private:
    string nome;
    string linguagem;

    // uma lista de integrantes...
    ListaGenerica<Integrante> *integrantes;
};

Equipe::Equipe(string nome, string linguagem) {
    // inicializar as variáveis...
}

Equipe::~Equipe() {
    // destruir alocações caso realizadas
}

string Equipe::getNome() {
    return this->nome;
}

string Equipe::getLinguagem() {
    return this->linguagem;
}

// deve verificar se já existe algum lider da equipe antes...
void Equipe::adicionarIntegrante(Integrante novoMembro, bool isLider) {
    if (isLider) novoMembro.defineComoLider();

    if (not this->integrantes->procura(novoMembro, NULL)) {
        this->integrantes->adiciona(novoMembro);
        this->qtdIntegrantes++;
    }
}

unsigned Equipe::qtdIntegrantes() {
    return this->integrantes->tamanho();
}

int main() {
    char leitura;

    ListaGenerica<Equipe>* equipes = new ListaGenerica<Equipe>();

    do {
        cin >> leitura;

        switch (leitura)
        {
            case 'i':
                // fazer a leitura dos dados de uma equipe e inserir na lista
                break;
        
            default:
                break;
        }
    } while (leitura != 's');

    delete equipes;
}