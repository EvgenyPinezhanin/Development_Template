#pragma once

#include<string>
#include<iostream>
#include<fstream>
#include<stdexcept>
#include<Collection.h>
#include<list.h>

using namespace std;

enum type {
    INT, STR, BOOL
};

class IValue {
public:
    virtual type getType() const = 0;
};

class valString : public IValue {
    string val;
public:
    valString(string _val) : val(_val) {}
    type getType() const { return STR; }
    void setVal(string _val) {
        val = _val;
    }
    string getVal() const {
        return val;
    }
};

class valInt : public IValue {
    int val;
public:
    valInt(int _val) : val(_val) {}
    type getType() const { return INT; }
    void setVal(int _val) {
        val = _val;
    }
    int getVal() const {
        return val;
    }
};

class valBool : public IValue {
    bool val;
public:
    valBool(bool _val) : val(_val) {}
    type getType() const {return BOOL; }
    void setVal(bool _val) {
        val = _val;
    }
    bool getVal() const {
        return val;
    }
};

class Node {
    IValue *val;

public:
    Node(string _val = "", string _key = "", Node *_next = nullptr, Node *_down = nullptr);
    Node(int _val, string _key = "", Node *_next = nullptr, Node *_down = nullptr);
    Node(bool _val, string _key = "", Node *_next = nullptr, Node *_down = nullptr);

    string key;
    bool isDown;
    Node *next;
    Node *down;
    
    void setValue(string _val);
    void setValue(int _val);
    void setValue(bool _val);

    IValue* getValue() const;
};

class Text {
    Node *root;
    Node *curr;
    Stack<Node*> *path;

    void printCDN(ostream& ostr, Node* root, Node* curr, int level) const;
    void fprintCDN(ofstream& ofstr, Node* root, int level) const;
    void freadCDN(ifstream& ifstr, Node *&root, bool isNextLvl);
    void delBranch(Node *n);
public:
    Text();
    ~Text();

    void addNext(string _key, string _val);
    void addNext(string _key, int _val);
    void addNext(string _key, bool _val);
    void addDown(string _key, string _val);
    void addDown(string _key, int _val);
    void addDown(string _key, bool _val);

    void delCurr();
    void delDown();

    void changeCurrKey(string str) const;
    void changeCurrValue(string _val) const;
    void changeCurrValue(int _val) const;
    void changeCurrValue(bool _val) const;
    string getCurrKey() const;
    IValue* getCurrValue() const;

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