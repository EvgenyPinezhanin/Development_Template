#pragma once

#include<string>
#include<cctype>
#include<stdexcept>
#include<iostream>

using namespace std;

const int sizeArr = 7;

enum romanNumeral {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M  = 1000};

struct arabic {
    int value;

    arabic(const int& num = 0) : value(num) {};
};

struct roman {
    string value;

    roman(const string& num = "") : value(num) {};
};

class converter {
private:
    arabic arabicNumber;
    bool isReadyArabic;
    roman romanNumber;
    bool isReadyRoman;

    void toArabic();
    void toRoman();
    bool checkRoman();

public:
    converter();
    converter(const arabic& ar);
    converter(const roman& rom);

    void setArabic(const arabic& num);
    void setRoman(const roman& num);

    arabic getArabic() const;
    roman getRoman() const;
};
