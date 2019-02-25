#include <iostream>
#include <fstream>
#include <cstdlib>

#include "abb.cpp"
#include "avl.cpp"

using namespace std;

int main() {
    string nomeArquivo;

    cin >> nomeArquivo;

    ifstream leitor(nomeArquivo.c_str());

    // arquivo não encontrado
    if (not leitor) {
        cerr << "Não foi possível abrir o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

    AVLTree avl;
    BinaryTree abb;

    string palavraLida;

    while(leitor >> palavraLida) {
        avl.add(palavraLida);
        abb.add(palavraLida);
    }

    unsigned qtdConsultas, qtdVerificacoes;

    cin >> qtdConsultas;

    bool encontrouPalavra;

    // avl.inOrder();
    // abb.inOrder();

    while(qtdConsultas > 0) {
        cin >> palavraLida;

        qtdVerificacoes = 0;

        encontrouPalavra = avl.search(palavraLida, &qtdVerificacoes);
        cout << (encontrouPalavra ? "sim ": "nao ") << qtdVerificacoes << endl;

        encontrouPalavra = abb.search(palavraLida, &qtdVerificacoes);
        cout << (encontrouPalavra ? "sim ": "nao ") << qtdVerificacoes << endl;

        --qtdConsultas;
    }

    return 0;
}