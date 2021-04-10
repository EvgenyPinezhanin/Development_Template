#pragma once

#include<iostream>
#include<string>

using namespace std;

int compString(string str1, string str2);

struct Node {
    string key;
    int count;
    Node* left;
    Node* right;
    Node* parent;

    Node(string _key, Node* _parent = nullptr, Node* _left = nullptr, Node* _right = nullptr) 
        : key(_key), left(_left), right(_right), parent(_parent), count(0) {};
};

class TreeSearch {
    Node* root;
public:
    TreeSearch();
    void insert(string _key);
    int search(string _key);
};

int compString(string str1, string str2) {
    int length = str1.length();
    if (str2.length() > length) length = str2.length();
    for (int i = 0; i < length; i++) {
        if (str1[i] > str2[i]) return 1;
        if (str1[i] < str2[i]) return -1;
    }
    if (str1.length() > str2.length()) {
        return -1;
    } else if (str1.length() < str2.length()) {
        return 1;
    }
    return 0;
}

TreeSearch::TreeSearch() : root(nullptr) {};

void TreeSearch::insert(string _key) {
    if (root == nullptr) {
        Node *tmp = new Node(_key);
        return;
    }
    Node *tmp = root;
    while(true) {
        if (compString(_key, tmp->key) == 1) {
            if (tmp->right != nullptr) {
                tmp = tmp->right;
            } else {
                Node *newt = new Node(_key);
                tmp->right = newt;
                return;
            }
        } else if (compString(_key, tmp->key) == -1) {
            if (tmp->left != nullptr) {
                tmp = tmp->left;
            } else {
                Node *newt = new Node(_key);
                tmp->left = newt;
                return;
            }
        } else {
            tmp->count++;
        }
    }
}

int TreeSearch::search(string _key) {
    int count = 0;
    if (root == nullptr) {
        return 0;
    }
    Node *tmp = root;
    while(true) {
        if (compString(_key, tmp->key) == 1) {
            if (tmp->right != nullptr) {
                tmp = tmp->right;
            } else {
                return 0;
            }
        } else if (compString(_key, tmp->key) == -1) {
            if (tmp->left != nullptr) {
                tmp = tmp->left;
            } else {
                return 0;
            }
        } else {
            return tmp->count;
        }
    }
}


