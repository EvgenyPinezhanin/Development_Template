#include <polynomial.h>

monomial::monomial(int coeff, int x, int y, int z) : coefficient(coeff) {
    if (x >= maxPower || y >= maxPower || z >= maxPower) throw logic_error("Power is greater than the maximum power");
    S = x * maxPower * maxPower + y * maxPower + z;
}

int monomial::getX() const {
    return S / (maxPower * maxPower);
}

int monomial::getY() const {
    int tmpX = S / (maxPower * maxPower);
    return (S - tmpX * maxPower * maxPower) / maxPower;
}

int monomial::getZ() const {
    int tmpX = S / (maxPower * maxPower);
    int tmpY = (S - tmpX * maxPower * maxPower) / maxPower;
    return S - tmpX * maxPower * maxPower - tmpY * maxPower;
}

int monomial::getS() const {
    return S;
}

int monomial::getCoeff() const {
    return coefficient;
}

bool monomial::operator==(const monomial& m) const {
	return S == m.S;
}

bool monomial::operator!=(const monomial& m) const {
	return S != m.S;
}

bool monomial::operator>(const monomial& m) const {
	return S > m.S;
}

bool monomial::operator>=(const monomial& m) const {
	return S >= m.S;
}

bool monomial::operator<(const monomial& m) const {
	return S < m.S;
}

bool monomial::operator<=(const monomial& m) const {
	return S <= m.S;
}

monomial monomial::operator*(const int& val) {
    monomial tmp = *this;
    tmp.coefficient *= val;
    return tmp;
}

monomial& monomial::operator*=(const int& val) {
    this->coefficient *= val;
    return *this;
}

monomial monomial::operator+(const monomial& m) {
    if (S != m.S) throw logic_error("Different power of monomials");
    monomial tmp = *this;
    tmp.coefficient += m.coefficient;
    return tmp;
}

monomial& monomial::operator+=(const monomial& m) {
    if (S != m.S) throw logic_error("Different power of monomials");
    coefficient += m.coefficient;
    return *this;
}

monomial monomial::operator-(const monomial& m) {
    if (S != m.S) throw logic_error("Different power of monomials");
    monomial tmp = *this;
    tmp.coefficient -= m.coefficient;
    return tmp;
}

monomial& monomial::operator-=(const monomial& m) {
    if (S != m.S) throw logic_error("Different power of monomials");
    coefficient -= m.coefficient;
    return *this;
}

monomial monomial::operator*(const monomial& m) {
    if (getX() + m.getX() >= maxPower) throw ("The resulting power exceeds the maximum");
    if (getY() + m.getY() >= maxPower) throw ("The resulting power exceeds the maximum");
    if (getZ() + m.getZ() >= maxPower) throw ("The resulting power exceeds the maximum");
    monomial tmp = *this;
    tmp.coefficient *= m.coefficient;
    tmp.S += m.S;
    return tmp;
} 

monomial& monomial::operator*=(const monomial& m) {
    if (getX() + m.getX() >= maxPower) throw ("The resulting power exceeds the maximum");
    if (getY() + m.getY() >= maxPower) throw ("The resulting power exceeds the maximum");
    if (getZ() + m.getZ() >= maxPower) throw ("The resulting power exceeds the maximum");
    coefficient *= m.coefficient;
    S += m.S;
    return *this;
}

ostream& operator<<(ostream &ostr, const monomial &m) {
    ostr << m.coefficient << "*" << "x^" << m.getX() << "y^" << m.getY() << "z^" << m.getZ();
    return ostr;
}

void polynomial::addMonom(int coeff, int x, int y, int z) {
    iter = listMonom->begin();
    iter = listMonom->insert(iter, monomial(coeff, x, y, z));
}

polynomial::polynomial() {
    listMonom = new List<monomial>;
    addMonom(0, 0, 0, 0);
}

polynomial::~polynomial() {

}

ostream& operator<<(ostream &ostr, polynomial &m) {
    m.iter = m.listMonom->begin();
    while (m.iter.hasNext()) {
        monomial monom = m.iter.next();
        if (monom.getCoeff() > 0) {
            cout  << "+" << monom;
        } else if (monom.getCoeff() < 0)
        {
            cout << monom;
        }
    }
    return ostr;
}