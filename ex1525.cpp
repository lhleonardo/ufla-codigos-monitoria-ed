#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

typedef string TipoDado;

class NohABB {
    friend class ArvoreBinaria;
    public:
        NohABB(TipoDado d);
    private:
        TipoDado dado;
        NohABB* filhoEsquerdo;
        NohABB* filhoDireito;

        void InserirRecursivo(NohABB* novoNoh);

        bool Buscar(TipoDado valor, unsigned *qtdPassos);
};

class ArvoreBinaria {
    public:
        ArvoreBinaria();
        
        void Inserir(TipoDado valor);

        bool Buscar(TipoDado valor, unsigned *qtdPassos);
    private:
        NohABB* raiz;
};

class NohAVL {
    friend class AVL;
    public:
        NohAVL(TipoDado valor);
    private:
        TipoDado dado;

        NohAVL* filhoEsquerdo;
        NohAVL* filhoDireito;

        unsigned altura; // nós folha possuem altura 1

        NohAVL* InserirRecursivo(NohAVL* novoNoh);
        NohAVL* ArrumarBalanceamento();
        
        int FatorBalanceamento();
        
        void AtualizarAltura();
        
        NohAVL* RotacionarEsquerda();
        NohAVL* RotacionarDireita();
        
        bool Buscar(TipoDado elemento, unsigned* qtdPassos);
};

class AVL {
    public:
        void Inserir(TipoDado valor);

        bool Buscar(TipoDado elemento, unsigned *qtdOperacoes);
    private:
        NohAVL* raiz;
};

/**
 * ****************************************************************
 *                      MÉTODOS DO NÓ DA ABB
 * ****************************************************************
 * */
NohABB::NohABB(TipoDado d): 
            dado(d), filhoDireito(nullptr), filhoEsquerdo(nullptr) {}

/**
 * Método que deverá inserir um nó de forma recursiva, encontrando o local
 * correto para inserir entre as sub-árvores presentes
 * 
 * Diferente do método InserirRecursivo da AVL, esse método não há retorno
 * pois a árvore não sofre alterações (como rotações) no momento de uma 
 * inserção.
 * */
void NohABB::InserirRecursivo(NohABB *novoNoh) {
    #warning NohABB::InserirRecursivo não foi implementado
}

/**
 * Método que deverá verificar se existe um determinado elemento nos nós
 * da sub-árvore que o nó atual (this) possui.
 * 
 * Caso o elemento seja encontrado na árvore, o retorno do método será true 
 * e a variável qtdPassos assumirá o valor de quantas passadas (esquerda e
 * direita) foram necessárias para encontrar o elemento.
 * */
bool NohABB::Buscar(TipoDado valor, unsigned *qtdPassos) {
    #warning NohABB::Buscar não foi implementado
}

/**
 * ****************************************************************
 *                       MÉTODOS DA ABB
 * ****************************************************************
 * */


ArvoreBinaria::ArvoreBinaria(): raiz(nullptr) {}

/**
 * Método para inserir um valor dentro da árvore.
 * 
 * Deverá chamar o InserirRecursivo do NohABB. 
 * 
 * Não poderão haver elementos repetidos na árvore.
 * */
void ArvoreBinaria::Inserir(TipoDado valor) {
    #warning ArvoreBinaria::Inserir não foi implementado
}

/**
 * Deverá verificar se existe determinado elemento em toda a árvore.
 * 
 * Chama o método Buscar em NohABB.
 * 
 * Mais detalhes ver a função Buscar em NohABB.
 * */
bool ArvoreBinaria::Buscar(TipoDado elemento, unsigned* qtdPassos) {
    #warning ArvoreBinaria::Buscar não foi implementado
}

/**
 * ****************************************************************
 *                      MÉTODOS DO NÓ DA AVL
 * ****************************************************************
 * */

NohAVL::NohAVL(TipoDado valor): 
        dado(valor), filhoDireito(nullptr), filhoEsquerdo(nullptr), altura(1) {}

/**
 * Método que deverá inserir um nó de forma recursiva, encontrando
 * seu local correto dentro das sub-árvores.
 * 
 * Diferente do método InserirRecursivo da ABB, este conta com o 
 * retorno para um próprio NohAVL, pois no momento de inserção pode 
 * ocorrer de acontecer modificação da raiz da sub-árvore, resultante
 * de possíveis operações de rotação.
 * 
 * Deverá usar os métodos:
 *  - ArrumarBalanceamento para corrigir eventuais problemas após
 * inserção;
 *  - 
 * */
NohAVL* NohAVL::InserirRecursivo(NohAVL* novoNoh){
    #warning NohAVL::InserirRecursivo não foi implementado.
}

/**
 * Método que deverá realizar análises dos fatores de balanceamento
 * da sub-árvore que se encontra e, se necessário, realizar as rotações
 * e atualizações de alturas. 
 * 
 * Utilizado após a inserção de um nó.
 * 
 * Este método deverá utilizar:
 *   - AtualizarAltura
 *   - FatorBalanceamento
 *   - RotacionarEsquerda
 *   - RotacionarDireita
 * */
NohAVL* NohAVL::ArrumarBalanceamento(){
    #warning NohAVL::ArrumarBalanceamento não foi implementado.
}

void  NohAVL::AtualizarAltura(){
    #warning NohAVL::AtualizarAltura não foi implementado.
}
int  NohAVL::FatorBalanceamento(){
    #warning NohAVL::FatorBalanceamento não foi implementado.
}

NohAVL* NohAVL::RotacionarEsquerda(){
    #warning NohAVL::RotacionarEsquerda não foi implementado.
}
NohAVL* NohAVL::RotacionarDireita(){
    #warning NohAVL::RotacionarDireita não foi implementado.
}

bool  NohAVL::Buscar(TipoDado elemento, unsigned* qtdPassos){
    #warning NohAVL::Buscar não foi implementado.
}

/**
 * ****************************************************************
 *                      MÉTODOS DA AVL
 * ****************************************************************
 * */

void AVL::Inserir(TipoDado valor) {
    NohAVL* novoNoh = new NohAVL(valor);
    
    if (this->raiz == nullptr) {
        this->raiz = novoNoh;
    } else {
        // atualizar as raízes em caso de rotações e balanceamentos
        this->raiz = this->raiz->InserirRecursivo(novoNoh);
    }
}

bool AVL::Buscar(TipoDado elemento, unsigned *qtdOperacoes) {
    return this->raiz->Buscar(elemento, qtdOperacoes);
}

int main() {
    string nomeArquivo;

    cin >> nomeArquivo;

    ifstream leitor(nomeArquivo.c_str());

    // arquivo não encontrado
    if (not leitor) {
        cerr << "Não foi possível abrir o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

    AVL avl;
    ArvoreBinaria abb;

    string palavraLida;

    while(leitor >> palavraLida) {
        avl.Inserir(palavraLida);
        abb.Inserir(palavraLida);
    }

    unsigned qtdConsultas, qtdVerificacoes;

    cin >> qtdConsultas;

    bool encontrouPalavra;

    while(qtdConsultas > 0) {
        cin >> palavraLida;

        qtdVerificacoes = 0;

        encontrouPalavra = avl.Buscar(palavraLida, &qtdVerificacoes);
        cout << (encontrouPalavra ? "sim ": "nao ") << qtdVerificacoes << endl;

        encontrouPalavra = abb.Buscar(palavraLida, &qtdVerificacoes);
        cout << (encontrouPalavra ? "sim ": "nao ") << qtdVerificacoes << endl;

        --qtdConsultas;
    }

    return 0;
}