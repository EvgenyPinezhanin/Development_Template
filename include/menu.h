#pragma once

#include<string>
#include<iostream>
#include<converter.h>

using namespace std;

class menuConverter {
private:
    string nameProgram;

    void romanToArabic();
    void arabicToRoman();
    void convText();

public:
    menuConverter();

    void display();

};