#pragma once

#include<iostream>
#include<fstream>
#include<iomanip>
#include<set>
#include<text.h>

using namespace std;

class menuText {
    Text *text;
    string nameProgram;
    string nameReadFile;
    bool isSaveFile;
    bool isReadFile;

    void readingKeys(set<string> *setKey, Text *text);
    string getKey(set<string> *setKey, int& count);

    void addNext(Text& text, string val, string key);
    void addDown(Text& text, string val, string key);
    void changeCurrVal(Text& text, string val);

    void saveFile();
    void loadFile();
    void createNewFile();
    void menuShowText(bool mode);
    void menuSelectModeShow();

public:
    menuText();
    ~menuText();

    void display();
};
