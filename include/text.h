#pragma once

#include<iostream>
#include<string>
#include<TreeSearch.h>
#include<list.h>

using namespace std;

class Text {
    string text;
public:
    Text();

    void setString(string str);
    void replace();
    List<string>* split(char c);

    friend istream& operator>>(istream& istr, Text& text);
};

Text::Text() {
    text = "";
};

void Text::setString(string str) {
    text = str;
}

istream& operator>>(istream& istr, Text& text) {
    istr >> text.text;
    return istr;
}

void Text::replace() {
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] < 'a' || text[i] > 'z') && text[i] != ' ') {
            text[i] = ' ';
        }
    }
}

List<string>* Text::split(char c) {
    List<string> *list = new List<string>();
    string tmp = "";
    bool b = false;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != c) {
            if (b) {
                list->push_back(tmp);
                tmp = text[i];
                b = false;
            } else {
                tmp.push_back(text[i]);
            }
        } else {
            if (tmp != "") b = true;
        }
    }
    if (tmp != "") list->push_back(tmp);
    return list;
}