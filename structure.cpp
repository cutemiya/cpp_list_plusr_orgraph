#include "structure.h"
#include <iostream>

int count = 0;
Top* buffer[20];

Top addTop(const int _index) {
    Top top;
    top.index = _index;

    buffer[count++] = &top;

    return top;
}

void addArc(Top* first, Top* second) {
    Node* current = new Node;
    current->toTop = second;

    if (first->first == nullptr) {
        first->first = current;
        first->last = current;
        return;
    }

    count++;
    first->last->next = current;
    first->last = current;
}

void deleteTop(Top* top) {

    for (int i = 0; i < count; ++i) {

        Top* currentTop = buffer[i];
        if(!top) continue;

        Node* current = currentTop->first;

        while (current) {
            if (current->toTop == top) {
                current->toTop = nullptr;
                break;
            }
            current = current->next;
        }

        if(buffer[i] == top) {
            buffer[i] = nullptr;
        }
    }

    top = nullptr;
    delete top;
}


void print() {
    for(int i = 0; i < count; ++i) {
        Top* top = buffer[i];

        if(!top) continue;

        Node* current = top->first;

        std::cout << top->index;

        while(current) {
            if (!current->toTop) {
                current = current->next;
            } else {
                std::cout << "<" << current->toTop->index;
                current = current->next;
            }
        }
        std::cout << std::endl;
    }
}

void deleteArc(Top* first, Top* second) {
    Node* current = first->first;

    while(current) {
        if(current->toTop == second) {
            current->toTop = nullptr;
            break;
        }
        current = current->next;
    }
}

void printMatrix() {
    for(int i = 0; i < count; ++i) {
        Top* top = buffer[i];
        if (!top) continue;
        std::cout << "\t" << top->index;
    }
    std::cout << std::endl;

    for(int i = 0; i < count; ++i) {
        Top* top = buffer[i];
        if (!top) continue;
        std::cout << top->index;

        // some code

        std::cout << std::endl << std::endl;
    }
}