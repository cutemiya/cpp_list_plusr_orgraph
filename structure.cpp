#include <iostream>
#include "structure.h"

using namespace std;

void list::addTop(const int _val) {
    Node *current = new Node(_val);

    if (first == nullptr) {
        first = current;
        last = current;
        return;
    }

    last->next = current;
    last = current;
}

void list::removeTop() {
    if (first == nullptr) {
        return;
    }

    if (first == last) {
        first = first->next;
        first = nullptr;
        delete first;
        return;
    }

    Node *current = first;
    while (current->next != last) {
        current = current->next;
    }
    current->next = nullptr;
    delete last;
    last = current;
}

void list::print() {
    if (first == nullptr) {
        return;
    }
    Node *current = first;

    cout << "[ ";
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << "]\n";
}

Node* list::operator[](const int index) {
    if (first == nullptr) {
        return nullptr;
    }

    Node *current = first;
    for (int i = 0; i < index; i++) {
        current = current->next;
        if (!current) return nullptr;
    }
    return current;
}

void list::addArc(const int _val, Node *node) {
    Node *current = first;
    while (current && current->val != _val) {
        current = current->next;
    }
    if (current && current->val == _val) {
        current->buffer[current->count++] = node;
    } else {
        std::cout << "This top is not defined" << std::endl;
    }
}

void list::removeArc(const int _val, Node *node) {
    Node *current = first;
    while (current && current->val != _val) {
        current = current->next;
    }
    if (current && current->val == _val) {
        for (int i = 0; i < current->count; ++i) {
            if (current->buffer[i]->val == node->val) {
                current->buffer[i] = nullptr;
            }
        }
    } else {
        cout << "This top is not defined" << endl;
    }
}

void list::printArcs() {
    Node *current = first;
    while (current) {
        cout << current->val << " -> ";
        for (int i = 0; i < current->count; ++i) {
            if ((current->buffer[i] != nullptr) && (current->buffer[i]->val != 0)) {
                cout << current->buffer[i]->val << " -> ";
            }
        }
        cout << "end\n";
        current = current->next;
    }
}
