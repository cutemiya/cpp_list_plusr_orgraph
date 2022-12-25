#pragma once

struct Top;

struct Node {
    Top* toTop = nullptr;
    Node* next = nullptr;
};

struct Top {
    Node* first = nullptr;
    Node* last = nullptr;
    unsigned int index;
};

Top addTop(const int _index);
void addArc(Top* first, Top* second);
void print();
void deleteTop(Top* top);
void deleteArc(Top* first, Top* second);
void printMatrix();