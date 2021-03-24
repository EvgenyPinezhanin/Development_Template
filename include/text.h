#pragma once

#include<string>
#include<iostream>
#include<fstream>
#include<Collection.h>

using namespace std;

struct Node {
    string val;
    Node *next;
    Node *down;

    Node(string _val = "", Node *_next = nullptr, Node *_down = nullptr) : val(_val), next(_next), down(_down) {};
};

class Text {
    Node *root;
    Node *curr;
    Stack<Node*> path;

    void printCDN(ostream& ostr, Node* root, Node* curr, int level) const;
    void fprintCDN(ofstream& ofstr, Node* root, int level) const;
    void freadCDN(ifstream& ifstr, Stack<Node*> *stack, Node* root, int level);
    void delBranch(Node *n);
public:
    Text();

    void addNext(string str);
    void addDown(string str);

    void delCurr();
    void delDown();

    void renameCurr(string str);

    void next();
    void down();
    void top();

    friend ostream& operator<<(ostream& ostr, const Text& text);

    friend ofstream& operator<<(ofstream& ofstr, const Text& text);
    friend ifstream& operator>>(ifstream& ifstr, Text& text);
};