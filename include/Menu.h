#pragma once

#include<iostream>
#include<fstream>
#include<iomanip>
#include<text.h>

using namespace std;

class menuText {
    Text *text;
    string nameProgram;
    string nameReadFile;
    bool isSaveFile;
    bool isReadFile;

    bool saveFile();
    void loadFile();
    void menuShowText();

public:
    menuText();
    ~menuText();

    void display();
};
