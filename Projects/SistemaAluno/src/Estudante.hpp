
#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <iostream>
using namespace std;

struct Estudante {
    in
    NodeT* root = nullptr;

    void insertNodeHelper(NodeT* root, int data);
    void inorder(NodeT* root);
    void insertNode(int data);
    void removeNode(int data);
    void display();
};

#endif