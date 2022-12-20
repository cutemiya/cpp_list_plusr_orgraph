#include <iostream>
using namespace std;

struct Node {
    int val;
    int count;
    Node* next = nullptr;
    Node* buffer[10];
    Node(int _val) : val(_val), count(0) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    void addTop(const int _val);
    void removeTop();
    void addArc(const int _val, Node* node);
    void removeArc(const int _val, Node* node);

    void print();
    void printArcs();

    Node* operator[] (const int index);

};