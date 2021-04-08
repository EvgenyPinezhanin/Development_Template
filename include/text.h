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

/* class IValue {
public:
    virtual type getType() const = 0;
};

class valString : public IValue {
    string val;
public:
    type getType() const { return STR; }
    string getVal() const {
        return val;
    }
};

class valInt : public IValue {
    int val;
public:
    type getType() const { return INT; }
    int getVal() const {
        return val;
    }
};

class valBool : public IValue {
    bool val;
public:
    type getType() const {return BOOL; }
    bool getVal() const {
        return val;
    }
};
 */
struct Value {
    friend class Node;
    Value() {
        typeVal = STR;
        strVal = "";
    }

    Value(string val) {
        typeVal = STR;
        strVal = val;
    }

    Value(int val) {
        typeVal = INT;
        intVal = val;
    }

    Value(bool val) {
        typeVal = BOOL;
        boolVal = val;
    }

    type getType() const {
        return typeVal;
    }

    string getString() const {
        return strVal;
    }

    int getInt() const {
        return intVal;
    }

    bool getBool() const {
        return boolVal;
    }

    void setString(string val) {
        typeVal = STR;
        strVal = val;
    }

    void setInt(int val) {
        typeVal = INT;
        intVal = val;
    }

    void setBool(bool val) {
        typeVal = BOOL;
        boolVal = val;
    }

    ~Value() {};
private:
    string strVal;
    type typeVal;
    union {
        int intVal;
        bool boolVal;
    };
};

class Node {
    List<Value> *val;

public:
    Node(string _key = "", string _val = "", Node *_next = nullptr, Node *_down = nullptr);

    string key;
    bool isDown;
    Node *next;
    Node *down;

    bool isList() const;

    List<Value>& getList();

    listIterator<Value> begin() const;
    
    void setValue(string _val);
    void setValue(int _val);
    void setValue(bool _val);
};

class Text {
    Node *root;
    Node *curr;
    Stack<Node*> *path;

    void printCDN(ostream& ostr, Node* root, Node* curr, int level) const;
    void freadArray(ifstream& ifstr, Node *&root);
    void fprintCDN(ofstream& ofstr, Node* root, int level) const;
    void freadCDN(ifstream& ifstr, Node *&root, bool isNextLvl);
    void delBranch(Node *n);
public:
    Text();
    ~Text();

    void addNext(string _key, string _val);
    void addDown(string _key, string _val);

    void delCurr();
    void delDown();

    void changeCurrKey(string str) const;
    void changeCurrValue(string str) const;
    string getCurrKey() const;
    string getCurrValue() const;

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