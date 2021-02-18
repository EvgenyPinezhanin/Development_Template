#pragma once

#include<string>
#include<iostream>
#include<fstream>
#include<converter.h>

using namespace std;

class menuConverter {
private:
    string nameProgram;
    string text;
    string textOut;

    void romanToArabic();
    void arabicToRoman();
    void searchRomanInText();
    void enterText();
    void readFile();
    void convText();

public:
    menuConverter();

    void display();

};