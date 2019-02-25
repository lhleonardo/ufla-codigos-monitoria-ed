#include <iostream>
#include <iomanip>
#include "utils.hpp"

using namespace std;

typedef string Data;

class NodeAVL {
    // clang-format off
  friend class AVLTree;
    // clang-format on

  private:
    const Data value;

    int level;

    NodeAVL* ancestor;
    NodeAVL* left;
    NodeAVL* right;

  public:
    NodeAVL(const Data value) : value(value) {
        this->ancestor = NULL;
        this->left = NULL;
        this->right = NULL;
        this->level = 1;
    }
    ~NodeAVL() {
        // obviosly i don't delete the ancestor, because this break the tree;
        delete left;
        delete right;
    }
};

class AVLTree {
  private:
    NodeAVL* root;
    int size;

    NodeAVL* getNodeAVL(Data value, unsigned* nunberOfOccurrences);

    // balance the NodeAVLs from the reference
    NodeAVL* balance(NodeAVL* reference);

    // return the actual root, if its changed
    NodeAVL* addAndBalance(NodeAVL* reference, Data value);

    void move(NodeAVL* older, NodeAVL* newer);

    // to process NULL NodeAVLs
    int getLevel(NodeAVL* reference);
    int balanceCoefficent(NodeAVL* reference);

    NodeAVL* minValue(NodeAVL* reference);
    NodeAVL* maxValue(NodeAVL* reference);

    void inOrder(NodeAVL* reference, unsigned int level);
    void preOrder(NodeAVL* reference, unsigned int level);
    void posOrder(NodeAVL* reference, unsigned int level);

    NodeAVL* leftRotation(NodeAVL* reference);
    NodeAVL* rightRotation(NodeAVL* reference);

  public:
    AVLTree();
    ~AVLTree();
    void add(Data value);
    void remove(Data value);
    bool search(Data value, unsigned* numberOfOccurrences);

    void preOrder();
    void posOrder();
    void inOrder();
};

AVLTree::AVLTree() {
    this->root = NULL;
    this->size = 0;
}

AVLTree::~AVLTree() {
    delete this->root;
}

NodeAVL* AVLTree::minValue(NodeAVL* reference) {
    NodeAVL* current = reference;
    NodeAVL* previous;

    while (current != NULL) {
        previous = current;
        current = current->left;
    }

    return previous;
}

NodeAVL* AVLTree::maxValue(NodeAVL* reference) {
    NodeAVL* current = reference;
    NodeAVL* previous = current;

    while (current != NULL) {
        previous = current;
        current = current->right;
    }

    return previous;
}

int AVLTree::getLevel(NodeAVL* reference) {
    if (reference == NULL) {
        return 0;
    }
    return reference->level;
}

int AVLTree::balanceCoefficent(NodeAVL* reference) {
    if (reference == NULL) {
        return 0;
    }
    return this->getLevel(reference->left) - this->getLevel(reference->right);
}

void AVLTree::add(Data value) {
    this->root = addAndBalance(this->root, value);
}

NodeAVL* AVLTree::balance(NodeAVL* reference) {
    reference->level =
        1 + max(this->getLevel(reference->left), this->getLevel(reference->right));

    int factor = this->balanceCoefficent(reference);

    // everything is fine
    if (factor >= -1 and factor <= 1) {
        return reference;
    }
    // right rotation
    if ((factor > 1) and (this->balanceCoefficent(reference->left) >= 0)) {
        return rightRotation(reference);
    }

    // left and right rotation
    if ((factor > 1) and (this->balanceCoefficent(reference->left) < 0)) {
        // correct the left son before rotation
        reference->left = leftRotation(reference->left);

        return rightRotation(reference);
    }

    // right and left rotation
    if ((factor < -1) and (this->balanceCoefficent(reference->right) > 0)) {
        // correct the right son before rotation
        reference->right = rightRotation(reference->right);

        return leftRotation(reference);

    }

    // only left rotation
    if ((factor < -1) and (this->balanceCoefficent(reference->left) <= 0)) {
        return leftRotation(reference);
    }

    // it should happen?
    return reference;
}

NodeAVL* AVLTree::rightRotation(NodeAVL* reference) {
    // getting left son from NodeAVL
    NodeAVL* aux = reference->left;

    // defines that left son of reference is now left son of aux
    // because aux should be the "root" of this subtree
    reference->left = aux->right;

    // setting correct ancestor of hierarchical
    if (reference->left != NULL) {
        reference->left->ancestor = reference;
    }

    // ancestor of aux is ancestor of reference
    aux->ancestor = reference->ancestor;

    // if reference have ancestor (reference is root?)
    if (reference->ancestor != NULL) {
        // setting correct ancestor of hierarchical
        if (reference->ancestor->left == reference) {
            reference->ancestor->left = aux;
        } else {
            reference->ancestor->right = aux;
        }
    }

    // reference will be the right child of aux
    aux->right = reference;
    aux->right->ancestor = aux;

    // update levels...
    reference->level = 1 + max(this->balanceCoefficent(reference->left),
                               this->balanceCoefficent(reference->right));
    aux->level =
        1 + max(this->balanceCoefficent(aux->left), this->balanceCoefficent(aux->right));

    // return the new root of this subtree
    return aux;
}

NodeAVL* AVLTree::leftRotation(NodeAVL* reference) {
    // getting right son from NodeAVL
    NodeAVL* aux = reference->right;

    // defines that right son of reference is now left son of aux
    // because aux should be the "root" of this subtree
    reference->right = aux->left;

    // setting correct ancestor of hierarchical
    if (reference->right != NULL) {
        reference->right->ancestor = reference;
    }

    // ancestor of aux is ancestor of reference
    aux->ancestor = reference->ancestor;

    // if reference have ancestor (reference is root?)
    if (reference->ancestor != NULL) {
        // setting correct ancestor of hierarchical
        if (reference->ancestor->left == reference) {
            reference->ancestor->left = aux;
        } else {
            reference->ancestor->right = aux;
        }
    }

    // reference will be the left child of aux
    aux->left = reference;
    aux->left->ancestor = aux;

    // update levels...
    reference->level = 1 + max(this->balanceCoefficent(reference->left),
                               this->balanceCoefficent(reference->right));
    aux->level =
        1 + max(this->balanceCoefficent(aux->left), this->balanceCoefficent(aux->right));

    // return the new root of this subtree
    return aux;
}

NodeAVL* AVLTree::addAndBalance(NodeAVL* reference, Data value) {
    // it's here in two cases: empty tree or correct position was found
    if (reference == NULL) {
        return new NodeAVL(value);
    }

    if (value < reference->value) {
        // recursive adding and found where it should be added
        reference->left = addAndBalance(reference->left, value);
        // indicates who is the father of the value
        reference->left->ancestor = reference;
    } else if (value > reference->value) {
        // recursive adding and found where it should be added
        reference->right = addAndBalance(reference->right, value);
        // indicates who is the father of the value
        reference->right->ancestor = reference;
    } else {
        // duplicate elements is not allowed
        // cerr << "Duplicate elements: " << value << endl;
        return reference;
    }

    // balance after insertion
    return balance(reference);
}

bool AVLTree::search(Data value, unsigned* numberOfOccurrences) {
    if (this->getNodeAVL(value, numberOfOccurrences) != NULL) {
        return true;
    }

    return false;
}

NodeAVL* AVLTree::getNodeAVL(Data value, unsigned* numberOfOccurrences) {
    NodeAVL* current = root;
    bool found = false;

    unsigned occurrencesTemp = 0;

    while (current != NULL and not found) {
        if (value < current->value) {
            occurrencesTemp++;
            current = current->left;
        } else if (value > current->value) {
            occurrencesTemp++;
            current = current->right;
        } else {
            occurrencesTemp++;
            found = true;
        }
    }

    if (numberOfOccurrences != NULL){
        *numberOfOccurrences = occurrencesTemp;
    }

    return current;
}

void AVLTree::move(NodeAVL* oldNodeAVL, NodeAVL* newNodeAVL) {
    if (this->root == oldNodeAVL) {
        this->root = newNodeAVL;
    } else {
        NodeAVL* father = oldNodeAVL->ancestor;

        // check if old value is right or left son
        if (father->left == oldNodeAVL) {
            father->left = newNodeAVL;
        } else {
            father->right = newNodeAVL;
        }

        if (newNodeAVL != NULL)
            newNodeAVL->ancestor = father;
    }
}

void AVLTree::preOrder(NodeAVL* reference, unsigned int level) {
    if (reference != NULL) {
        this->preOrder(reference->left, level + 1);
        cout  << "[" << setw(2) << reference->value << ":" << setw(2) << level << "]..";
        this->preOrder(reference->right, level + 1);
    }
}

void AVLTree::preOrder() {
    this->preOrder(this->root, 0);
    cout << endl;
}

void AVLTree::inOrder(NodeAVL* reference, unsigned int level) {
    if (reference != NULL) {
        cout  << "[" << setw(2) << reference->value << ":" << setw(2) << level << "]..";
        this->inOrder(reference->left, level + 1);
        this->inOrder(reference->right, level + 1);
    }
}

void AVLTree::inOrder() {
    this->inOrder(this->root, 0);
    cout << endl;
}

void AVLTree::posOrder(NodeAVL* reference, unsigned int level) {
    if (reference != NULL) {
        this->posOrder(reference->left, level + 1);
        this->posOrder(reference->right, level + 1);
        cout  << "[" << setw(2) << reference->value << ":" << setw(2) << level << "]..";
    }
}

void AVLTree::posOrder() {
    this->posOrder(this->root, 0);
    cout << endl;
}