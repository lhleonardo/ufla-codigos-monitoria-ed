#include <iostream>
#include "utils.hpp"

using namespace std;

typedef string Data;

class NodeABB {
    // clang-format off
  friend class BinaryTree;
    // clang-format on

  private:
    const Data value;
    unsigned occurrence;
    NodeABB* ancestor;
    NodeABB* left;
    NodeABB* right;

  public:
    NodeABB(const Data value) : value(value) {
        this->ancestor = NULL;
        this->left = NULL;
        this->right = NULL;
        this->occurrence = 1;
    }
    ~NodeABB() {
        // claro que não vou apagar o ancestor(pai), pois poderia apagar toda a BinaryTree
        delete left;
        delete right;
    }
};

class BinaryTree {
  private:
    NodeABB* root;
    int size;

    NodeABB* findPositionToAdd(const Data elemento, Position* posicao);
    NodeABB* getNodeABB(Data value, unsigned* number_of_comparisons);

    void move(NodeABB* older, NodeABB* newer);

    NodeABB* minValue(NodeABB* reference);
    NodeABB* maxValue(NodeABB* reference);

    void inOrder(NodeABB* reference, unsigned int level);
    void preOrder(NodeABB* reference, unsigned int level);
    void posOrder(NodeABB* reference, unsigned int level);

  public:
    BinaryTree();
    ~BinaryTree();
    void add(Data value);
    void remove(Data value);
    bool search(Data value, unsigned* number_of_comparisons);

    void preOrder();
    void posOrder();
    void inOrder();
};

BinaryTree::BinaryTree() {
    this->root = NULL;
    this->size = 0;
}

BinaryTree::~BinaryTree() {
    delete this->root;
}

NodeABB* BinaryTree::minValue(NodeABB* reference) {
    NodeABB* current = reference;
    NodeABB* previous;

    while (current != NULL) {
        previous = current;
        current = current->left;
    }

    return previous;
}

NodeABB* BinaryTree::maxValue(NodeABB* reference) {
    NodeABB* current = reference;
    NodeABB* previous = current;

    while (current != NULL) {
        previous = current;
        current = current->right;
    }

    return previous;
}

NodeABB* BinaryTree::findPositionToAdd(Data value, Position* position) {
    NodeABB* current = this->root;
    NodeABB* previous = current;

    while (current != NULL) {
        previous = current;
        if (value > current->value) {
            *position = RIGHT;
            current = current->right;
        } else {
            *position = LEFT;
            current = current->left;
        }
    }

    return previous;
}

void BinaryTree::add(Data value) {
    if (this->root == NULL) {
        this->root = new NodeABB(value);
        this->size++;
        return;
    }

    NodeABB* element = new NodeABB(value);
    Position position;

    NodeABB* existentNodeABB = this->getNodeABB(value, NULL);

    // busca o local onde o elemento deverá ser adicionado, trazendo junto consigo seu
    // respectivo pai
    if (existentNodeABB != NULL) {
        existentNodeABB->occurrence = existentNodeABB->occurrence + 1;
    } else {
        // nó não existe na arvore, então deverá ser criado
        NodeABB* rootElement = this->findPositionToAdd(value, &position);

        element->ancestor = rootElement;
        if (position == RIGHT) {
            rootElement->right = element;
        } else {
            rootElement->left = element;
        }
    }

    this->size++;
}

bool BinaryTree::search(Data value, unsigned *number_of_comparisons) {
    if (this->size == 0)
        return false;

    if (this->getNodeABB(value, number_of_comparisons) != NULL) {
        return true;
    }

    return false;
}

NodeABB* BinaryTree::getNodeABB(Data value, unsigned *number_of_comparisons) {
    NodeABB* current = root;
    bool found = false;
    
    unsigned comparisons_temp = 0;
    
    while (current != NULL and not found) {
        if (value < current->value) {
            current = current->left;
            comparisons_temp++;
        } else if (value > current->value) {
            current = current->right;
            comparisons_temp++;
        } else {
            comparisons_temp++;
            found = true;
        }
    }
    
    if (number_of_comparisons != NULL) *number_of_comparisons = comparisons_temp;
    

    return current;
}

void BinaryTree::move(NodeABB* oldNodeABB, NodeABB* newNodeABB) {
    if (this->root == oldNodeABB) {
        this->root = newNodeABB;
    } else {
        NodeABB* father = oldNodeABB->ancestor;

        // verifica se o antigo valor é filho a direita ou esquerda
        if (father->left == oldNodeABB) {
            father->left = newNodeABB;
        } else {
            father->right = newNodeABB;
        }

        if (newNodeABB != NULL)
            newNodeABB->ancestor = father;
    }
}

void BinaryTree::remove(Data value) {
    NodeABB* element = this->getNodeABB(value, NULL);

    // se nao for encontrado esse elemento, nao faz nada pq ele não existe
    if (element == NULL)
        return;

    if (element->occurrence > 1) {
        element->occurrence--;
    } else {
        if (element->left == NULL and element->right == NULL) {
            delete element;
        } else {
            // tem um só filho?
            // ou exclusivo = ^, ou seja, só funcionará quando apenas tiver
            // um lado verdadeiro
            if (element->left == NULL ^ element->right == NULL) {
                // sobe o filho que nao eh nulo
                this->move(element,
                           element->right == NULL ? element->left : element->right);
            } else {
                // tem os dois filhos... substituirei pelo sucessor
                NodeABB* sucessor = this->minValue(element->right);

                // cuidando do caso em que o sucessor pode ter um filho a direita
                // não tem porque dizer que o filho a direita do sucessor seja filho do nó
                // que será removido
                if (sucessor->ancestor != element) {
                    // filho a direita do sucessor agora deverá estar em seu lugar
                    this->move(sucessor, sucessor->right);
                    // sucessor assume a guarda do filho do nó que será removido
                    sucessor->right = element->right;
                    // filho do nó que será removido aceita sucessor como seu legitimo pai
                    sucessor->right->ancestor = sucessor;
                }
                // tirando o antigo nó de cena e colocando o sucessor como o novo pai
                this->move(element, sucessor);
                // o filho a esquerda não pode ser órfão
                sucessor->left = element->left;
                // definindo o pai para que tudo fique certo
                sucessor->left->ancestor = sucessor;
            }
            // fazendo isso para que, na hora de destruir,
            // não apague coisas indevidas
            element->left = NULL;
            element->right = NULL;
            delete element;
        }
    }

    this->size--;
}

void BinaryTree::preOrder(NodeABB* reference, unsigned int level) {
    if (reference != NULL) {
        this->preOrder(reference->left, level + 1);
        cout << "[" << reference->value << ":" << level << "]..";
        this->preOrder(reference->right, level + 1);
    }
}

void BinaryTree::preOrder() {
    this->preOrder(this->root, 0);
    cout << endl;
}

void BinaryTree::inOrder(NodeABB* reference, unsigned int level) {
    if (reference != NULL) {
        cout << "[" << reference->value << ":" << level << "]..";
        this->inOrder(reference->left, level + 1);
        this->inOrder(reference->right, level + 1);
    }
}

void BinaryTree::inOrder() {
    this->inOrder(this->root, 0);
    cout << endl;
}

void BinaryTree::posOrder(NodeABB* reference, unsigned int level) {
    if (reference != NULL) {
        this->posOrder(reference->left, level + 1);
        this->posOrder(reference->right, level + 1);
        cout << "[" << reference->value << ":" << level << "]..";
    }
}

void BinaryTree::posOrder() {
    this->posOrder(this->root, 0);
    cout << endl;
}
