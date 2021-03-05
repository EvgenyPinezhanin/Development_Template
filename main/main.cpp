#include<iostream>
#include<cstdlib>
#include <ctime>
#include<polynomial.h>

using namespace std;

int main() {
	polynomial polynom1, polynom2;
	//polynom1 += monomial(5, 2, 4, 8);
	//polynom2 += monomial(5, 2, 4, 8);
	//
	//polynom1 += monomial(5, 2, 3, 8);
	//polynom2 += monomial(5, 5, 4, 8);
	int count = 10;
	for (int i = 0; i < maxPower - count; i++) {
		for (int j = 0; j < maxPower - count; j++) {
			for (int k = 0; k < maxPower - count; k++) {
				polynom1 += monomial( rand() % 10 - 5, i, j, k);
				polynom2 += monomial( rand() % 10 - 5, i, j, k);
			}
		}
	}
	//cout << polynom1 << endl;
	//cout << polynom2 << endl << endl;
	//polynomial polynom2(polynom1);
	//polynom2 *= 5;
	//cout << polynom1 << endl;
	clock_t time_start = clock();
	polynom1 *= polynom2;
	clock_t time_end = clock() - time_start;
	cout <<  (double)time_end / CLOCKS_PER_SEC << " s" << endl;
	cout << polynom1.getSum() << endl;
	return 0;
}
