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

ostream& operator<<(ostream &ostr, const monomial &m) {
    ostr << m.coefficient << "*" << "x^" << m.getX() << "y^" << m.getY() << "z^" << m.getZ();
    return ostr;
}

polynomial::polynomial() {
    listMonom = new List<monomial>;

}

polynomial::~polynomial() {

}