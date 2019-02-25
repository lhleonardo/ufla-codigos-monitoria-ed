#include <iostream>

using namespace std;

typedef int Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(Dado dado);
        void insere(Dado dado, int pos);
        void remove(int posicao);
        int procura(Dado valor);
        void imprime();
        inline bool vazia();
};

// constr�i uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

// m�todo b�sico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

// insere por padr�o no final da lista
void lista::insere(Dado dado) {
    noh* novo = new noh(dado);
    if (vazia()) {
		primeiro = novo;
		ultimo = novo;
	} else {
		ultimo->proximo = novo;
		ultimo = novo;
	}
	++tamanho;
}

// insere um dado em uma determinada posi��o da lista
void lista::insere(Dado dado, int posicao) {
    if ((posicao >= 0) and (posicao < tamanho)) {
		noh* novo = new noh(dado);
		if (vazia()) {
			primeiro = novo;
			ultimo = novo;
		} else {
			if (posicao == 0) {
				novo->proximo = primeiro;
				primeiro = novo;
			} else {
				noh* aux = primeiro;
				noh* antAux;
				int contPos = 0;
				while (contPos != posicao) {
					antAux = aux;
					aux = aux->proximo;
					++contPos;
				}
				
				if (aux == ultimo) {
					aux->proximo = novo;
					ultimo = novo;
				} else {
					antAux->proximo = novo;
					novo->proximo = aux;
				}
			}
		}
		++tamanho;
	}	
}

// remove o item da posi��o passada por par�metro
// Aten��o - o c�digo deve tratar de posi��o inv�lidas
void lista::remove(int posicao) {
    if ((posicao >= 0) and (posicao < tamanho)) {
		noh* aux = primeiro;
		if (posicao == 0) {
			primeiro = primeiro->proximo;
			aux->proximo = NULL;
		} else {
			noh* antAux;
			int contPos = 0;
			while (aux != NULL and contPos != posicao) {
				antAux = aux;
				aux = aux->proximo;
				++contPos;
			}
            if (contPos == posicao) {
                if (aux == ultimo) {
                    antAux->proximo = NULL;
                    ultimo = antAux;
                } else {
                    antAux->proximo = aux->proximo;
                    aux->proximo = NULL;
                }
            }
		}
		delete aux;
		--tamanho;
	}
}

// procura por um elemento e retorna a posi��o ou -1 se n�o encontrado
int lista::procura(Dado valor) {
    if (not vazia()) {
		noh* aux = primeiro;
		int pos = 0;
		while (aux != NULL and (aux->dado != valor)) { 
			aux = aux->proximo;
			++pos;
		}
		if (not aux)
			return -1;
		else
			return pos;
	} else 
		return -1;
}

// verifica se a lista est� vazia
inline bool lista::vazia() {
    return (primeiro==NULL);
}

int main() { // N�O MODIFIQUE!
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}
