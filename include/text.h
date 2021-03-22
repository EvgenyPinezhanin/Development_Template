#pragma once

#include<string>
#include<iostream>
#include<stack>

using namespace std;

struct Link {
    string val;
    Link *next;
    Link *down;

    Link(string _val = "", Link *_next = nullptr, Link *_down = nullptr) : val(_val), next(_next), down(_down) {};
};

class Text {
    Link *root;
    Link *curr;
    stack<Link*> path;

    void printCurrDownNext(ostream& ostr, Link* root, Link* curr, int level) const;
public:
    Text();

    void addNext(string str);
    void addDown(string str);

    void delCurr();
    void delDown();

    void next();
    void down();
    void top();

    friend ostream& operator<<(ostream& ostr, const Text& text);

};