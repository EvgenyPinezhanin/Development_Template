#pragma once

#include<string>
#include<iostream>
#include<fstream>
#include<stdexcept>
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
    Stack<Node*> *path;

    void printCDN(ostream& ostr, Node* root, Node* curr, int level) const;
    void fprintCDN(ofstream& ofstr, Node* root, int level) const;
    void freadCDN(ifstream& ifstr, Stack<Node*> *stack, Node* root, int level);
    void delBranch(Node *n);
public:
    Text();
    ~Text();

    void addNext(string str);
    void addDown(string str);

    void delCurr();
    void delDown();

    void changeCurrString(string str);
    string getCurrString() const;

    bool isNext() const;
    bool isDown() const;
    bool isTop() const;

    void next();
    void down();
    void top();

    friend ostream& operator<<(ostream& ostr, const Text& text);

    friend ofstream& operator<<(ofstream& ofstr, const Text& text);
    friend ifstream& operator>>(ifstream& ifstr, Text& text);
};