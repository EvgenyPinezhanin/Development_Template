#pragma once

#include<iostream>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int v = 0, Node * n = nullptr) : value(v), next(n) {};
};

class List {
    Node *first;
    int size;
public:
    List();
    void addNode(Node *nd);
    Node* getPointer(int pos);
    bool CheckLoop1();
    bool CheckLoop2();
    bool CheckLoop3();

    friend ostream& operator<<(ostream& ostr, const List& l);
};