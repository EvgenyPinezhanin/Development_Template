#pragma once

#include <list.h>

const int maxPower = 21;

class monomial {
    int coefficient;
    int S;
public:
    monomial(int coeff = 0, int x = 0, int y = 0, int z = 0);

    int getX() const;
    int getY() const;
    int getZ() const;

    monomial operator*(const int& val);
    monomial& operator*=(const int& val);

    monomial operator+(const monomial& m);
    monomial& operator+=(const monomial& m);
    monomial operator-(const monomial& m);
    monomial& operator-=(const monomial& m);
    monomial operator*(const monomial& m); 
    monomial& operator*=(const monomial& m); 

    friend ostream& operator<<(ostream &ostr, const monomial &m);
};

class polynomial {
private:
    List<monomial> *listMonom;
    void addMonom(int coeff, int x, int y, int z);
public:
    polynomial();
    ~polynomial();
};