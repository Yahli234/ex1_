#ifndef STACK_H
#define STACK_H

struct Node {
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

typedef struct Stack
{
    Node* top;
} Stack;

void push(Stack& s, unsigned int element); 
int pop(Stack& s);                      
void initStack(Stack& s);                   
void cleanStack(Stack& s);                  
bool isEmpty(Stack& s);                
bool isFull(Stack& s);                      
#endif
