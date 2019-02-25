#include <iostream>

using namespace std;

typedef string FormatoExpressao;

// outros métodos privados podem ser criados...
class Noh {
    friend class ArvoreExpressao;
    public:
        Noh(FormatoExpressao d);
    private:
        FormatoExpressao dado;
        Noh* filhoEsquerdo;
        Noh* filhoDireito;
};

// outros métodos privados podem ser criados...
class ArvoreExpressao {
    public:
        ArvoreExpressao();
        
        void PrepararExpressao(FormatoExpressao valor);

        float Resolver();

        Noh* raiz;
};

Noh::Noh(FormatoExpressao d): 
            dado(d), filhoDireito(nullptr), filhoEsquerdo(nullptr) {}


ArvoreExpressao::ArvoreExpressao(): raiz(nullptr) {}

/**
 * Método para criar a árvore a partir da expressão recebida.
 * */
void ArvoreExpressao::PrepararExpressao(FormatoExpressao valor) {
    #warning ArvoreExpressao::PrepararExpressao não foi implementado
}

/**
 * Método para resolver a expressão presente na árvore.
 * 
 * Pode lançar excessões que o main já espera este comportamento.
 * 
 * As exceções podem ser utilizadas para falhas, i.e divisões por zero.
 * */
float ArvoreExpressao::Resolver() {
    #warning ArvoreExpressao::Resolver não foi implementado
}

int main() {
    string entrada;
    cin >> entrada;

    ArvoreExpressao resolvedora;
    resolvedora.PrepararExpressao(entrada);
    
    try {
        cout << resolvedora.Resolver() << endl;
    } catch(const exception& e) {
        cout << "invalido" << endl;
    }

    return 0;
}