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
    int getS() const;
    int getCoeff() const;

    bool operator==(const monomial& m) const;
    bool operator!=(const monomial& m) const;
    bool operator>(const monomial& m) const;
    bool operator>=(const monomial& m) const;
    bool operator<(const monomial& m) const;
    bool operator<=(const monomial& m) const;

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
    listIterator<monomial> iter;

    //void addMonom(int coeff, int x, int y, int z);
public:
    polynomial();
    ~polynomial();

    void addMonom(int coeff, int x, int y, int z);

    polynomial operator*(const int& val);
    polynomial& operator*=(const int& val);

    polynomial operator+(const polynomial& m);
    polynomial& operator+=(const polynomial& m);
    polynomial operator-(const polynomial& m);
    polynomial& operator-=(const polynomial& m);
    polynomial operator*(const polynomial& m);
    polynomial& operator*=(const polynomial& m);

    friend ostream& operator<<(ostream &ostr, polynomial &m);
};