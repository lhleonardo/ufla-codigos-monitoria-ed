#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// observação quanto a implementação:
// não precisa usar friend class, basta usar os métodos disponíveis
// para acesso a atributos nas classes.

class Atividade {
    private:
        unsigned nota;
        unsigned tentativas;
    public:
        Atividade(unsigned nota, unsigned tentativas);
        unsigned getNota();
        unsigned getTentativas();
};

Atividade::Atividade(unsigned nota, unsigned tentativas) {
    this->nota = nota;
    this->tentativas = tentativas;
}

unsigned Atividade::getNota() { return this->nota; }

unsigned Atividade::getTentativas() { return this->tentativas; }

class Aluno {
    private:
        unsigned matricula;
        string nome;
        list<Atividade> atividades;
    public:
        Aluno(unsigned matricula, string nome);
        Aluno(const Aluno& umAlunoJaExistente);
        
        unsigned getMatricula();
        string getNome();
        
        void adicionarAtividade(unsigned nota, unsigned tentativas);

        float mediaAtividades();

        bool operator>(const Aluno& outroAluno);
};

Aluno::Aluno(unsigned matricula, string nome) {
    this->matricula = matricula;
    this->nome = nome;

    // não precisa inicializar a lista...
}

Aluno::Aluno(const Aluno& umAlunoJaExistente) {
    #warning construtor de cópia Aluno::Aluno(const Aluno& umAlunoJaExistente) não foi implementado.
}

unsigned Aluno::getMatricula() {
    return this->matricula;
}

string Aluno::getNome() {
    return this->nome;
}

void Aluno::adicionarAtividade(unsigned nota, unsigned tentativas) {
    // sempre inserindo no final da lista...
    // para saber mais, leia a documentação de list da biblioteca stl
    this->atividades.push_back(Atividade(nota, tentativas));
}

float Aluno::mediaAtividades() {
    float media = 0.0;
    list<Atividade>::iterator iterador;

    for (iterador = this->atividades.begin(); 
        iterador != this->atividades.end(); 
        ++iterador) {
        
        media += iterador->getNota();
    }

    return media / float(this->atividades.size());
}

// método necessário para que o objeto possa sofrer comparações
// de forma específica.
// critérios de comparações devem ser definidos aqui.
bool Aluno::operator>(const Aluno& outroAluno) {
    #warning sobrecarga do operador > não foi implementada.
}

typedef Aluno TipoDado;

class Heap {
    private:
        unsigned capacidadeMaxima;
        unsigned qtdElementos;
        // vetor de ponteiros para evitar desperdício de memória
        // e garantir a construção de elementos válidos
        // (sem o uso de construtor padrão)
        TipoDado** elementos;

        void corrigeSubindo(unsigned indice);
        void corrigeDescendo(unsigned indice);

        unsigned descobreFilhoDireita(unsigned indice);
        unsigned descobreFilhoESquerda(unsigned indice);

        unsigned descobrePai(unsigned filhoQualquer);

    public:
        Heap(unsigned capacidade);
        ~Heap();

        void adiciona(TipoDado& elemento);

        TipoDado retiraRaiz();
};

Heap::Heap(unsigned capacidade) {
    this->capacidadeMaxima = capacidade;
    this->qtdElementos = 0;

    this->elementos = new TipoDado*[this->capacidadeMaxima];
    // inicializa os indices com null
    for(unsigned indice = 0; indice < this->capacidadeMaxima; indice++) {
        this->elementos[indice] = nullptr;
    }
}

Heap::~Heap() {
    // apaga os indices com elementos
    for (unsigned indice = 0; indice < capacidadeMaxima; indice++) {
        if (this->elementos[indice] != nullptr) {
            delete this->elementos[indice];
        }
    }

    delete this->elementos;
}

void Heap::adiciona(TipoDado& elemento) {
    #warning Heap::adiciona(TipoDado& elemento) não foi implementado.
}

TipoDado Heap::retiraRaiz() {
    #warning Heap::retiraRaiz() não foi implementado.
}

void Heap::corrigeSubindo(unsigned indice) {
    #warning Heap::corrigeSubindo(unsigned indice) não foi implementado.
}
void Heap::corrigeDescendo(unsigned indice) {
    #warning Heap::corrigeDescendo(unsigned indice) não foi implementado.
}

unsigned Heap::descobreFilhoDireita(unsigned indice) {
    #warning Heap::descobreFilhoDireita(unsigned indice) não foi implementado.
}
unsigned Heap::descobreFilhoESquerda(unsigned indice) {
    #warning Heap::descobreFilhoESquerda(unsigned indice) não foi implementado.
}

unsigned Heap::descobrePai(unsigned filhoQualquer) {
    #warning Heap::descobrePai(unsigned filhoQualquer) não foi implementado.
}

int main() {
    unsigned qtdAlunos;
    unsigned atividadesPorAluno;
    
    cin >> qtdAlunos;
    cin >> atividadesPorAluno;

    unsigned matricula;
    string nome;
    unsigned nota, tentativas;

    Heap heapAlunos(qtdAlunos);
    
    for (unsigned indiceAluno = 0; indiceAluno < qtdAlunos; indiceAluno++) {
        cin >> matricula;
        cin >> nome;

        Aluno temporario(matricula, nome);
        for(unsigned indiceAtividade = 0; indiceAtividade < atividadesPorAluno; indiceAtividade++) {
            cin >> nota;
            cin >> tentativas;

            temporario.adicionarAtividade(nota, tentativas);
        }

        heapAlunos.adiciona(temporario);
    }

    Aluno destaque = heapAlunos.retiraRaiz();

    cout << destaque.getMatricula() << " " << destaque.getNome() << endl;

    return 0;
}