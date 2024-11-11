#include "Stack.h"
#include <iostream>

void initStack(Stack& s) {
    s.top = nullptr;  
}

void cleanStack(Stack& s) {
    while (s.top != nullptr) {
        Node* temp = s.top;
        s.top = s.top->next;
        delete temp; 
    }
}

void push(Stack& s, unsigned int element) {
    Node* newNode = new Node(element); 
    newNode->next = s.top;            
    s.top = newNode;                    
}

int pop(Stack& s) {
    if (s.top == nullptr) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1;  
    }
    int value = s.top->value;  
    Node* temp = s.top;        
    s.top = s.top->next;       
    delete temp;               
    return value;              
}

bool isEmpty(const Stack& s) {
    return s.top == nullptr;  
}

bool isFull(const Stack& s)
{
    return false;  //there is no limit for a stack
}
