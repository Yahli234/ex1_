#include <iostream>
#include "LinkedList.h"

int main() {
    Node* head = nullptr;

    add(head, 1);
    add(head, 2);
    add(head, 3);

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
