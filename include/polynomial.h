#pragma once

#include <list.h>
#include <cmath>

const int maxPower = 21;

class monomial {
    int coefficient;
    int S;

public:
    monomial(int coeff, int x, int y, int z);
    monomial(int coeff, int S = 0);

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

    monomial operator+(const monomial& m) const;
    monomial& operator+=(const monomial& m);
    monomial operator-(const monomial& m) const;
    monomial& operator-=(const monomial& m);
    monomial operator*(const monomial& m) const;
    monomial& operator*=(const monomial& m);

    monomial operator-() const;

    friend ostream& operator<<(ostream &ostr, const monomial &m);
};

class polynomial {
private:
    List<monomial> *listMonom;
    listIterator<monomial> iter;

public:
    polynomial();
    polynomial(const polynomial& p);
    ~polynomial();

    int getValue(int x, int y, int z) const;

    listIterator<monomial> getIterBeginMonom();
    listIterator<monomial> getIterEndMonom();

    polynomial& operator=(const polynomial& p);

    polynomial operator*(const int& val);
    polynomial& operator*=(const int& val);

    polynomial operator+(const monomial& m);
    polynomial& operator+=(const monomial& m);
    polynomial operator-(const monomial& m);
    polynomial& operator-=(const monomial& m);
    polynomial operator*(const monomial& m);
    polynomial& operator*=(const monomial& m);

    polynomial operator+(const polynomial& m);
    polynomial& operator+=(const polynomial& m);
    polynomial operator-(const polynomial& m);
    polynomial& operator-=(const polynomial& m);
    polynomial operator*(const polynomial& m);
    polynomial& operator*=(const polynomial& m);

    friend ostream& operator<<(ostream &ostr, const polynomial &m);
};