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

    void saveFile();
    void loadFile();
    void createNewFile();
    void menuShowText();

public:
    menuText();
    ~menuText();

    void display();
};
