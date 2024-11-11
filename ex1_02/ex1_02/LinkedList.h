#ifndef LINKEDLIST_H
#define LINKEDLIST_H


struct Node {
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

void add(Node*& head, int value);

#endif
