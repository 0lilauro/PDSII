#include "BTS.hpp"
NodeT* createNode(int data) {
    NodeT* aux = new NodeT;
    aux->data = data;
    aux->esq = nullptr;
    aux->dir = nullptr;

    return aux;
}

void BST::insertNodeHelper(NodeT* n, int data) {
    if (data< n->data) {
        if (n->esq == nullptr) {
            n->esq = createNode(data);
        } else {
            insertNodeHelper(n->esq, data);
        }
    } else if (data> n->data) {
        if (n->dir == nullptr) {
            n->dir = createNode(data);
        } else {
            insertNodeHelper(n->dir, data);
        }
    }
}

void BST::insertNode(int data) {
    if (root != nullptr) {
        insertNodeHelper(root,data);
    } else {
        root = createNode(data);
    }
}

void BST::inorder(NodeT* n) {
    if(n==nullptr) {
        return;
    }

    this->inorder(n->esq);
    cout << n->data << " ";
    this->inorder(n->dir);
}


void BST::display() {
  this->inorder(root);
  cout << endl;
}