#include<iostream>
#include<cstdlib>
#include <ctime>
#include<polynomial.h>

using namespace std;

int main() {
	polynomial polynom1, polynom2;
	//monomial monom(4, 3, 4, 9);
	//polynom1 += monomial(5, 2, 4, 8);
	//polynom1 += monomial(5, 2, 3, 8);
	//polynom1 += monomial(7, 4, 9, 3);
//
	//polynom2 += monomial(5, 2, 4, 8);
	//polynom2 += monomial(5, 5, 4, 8);
	//polynom2 += monomial(6, 7, 2, 6);
//
	//cout << "polynom1: " << polynom1 << endl;
	//cout << "polynom2: " << polynom2 << endl;
	//cout << endl;
	//cout << "polynom1 * 5: " << polynom1 * 5 << endl;
	//cout << "polynom2 * (-3): " << polynom2 * (-3) << endl;
	//cout << endl;
	//cout << "polynom1 + polynom2: " << polynom1 + polynom2 << endl;
	//cout << "polynom1 - polynom2: " << polynom1 - polynom2 << endl;
	//cout << endl;
	//cout << "polynom1 * monom: " << polynom1 * monom << endl;
	//cout << "polynom1 * polynom2: " << polynom1 * polynom2 << endl;

	int count = 10;
	for (int i = 0; i < maxPower - count; i++) {
		for (int j = 0; j < maxPower - count; j++) {
			for (int k = 0; k < maxPower - count; k++) {
				polynom1 += monomial( /*rand() % 10 - 5*/1, i, j, k);
				polynom2 += monomial( /*rand() % 10 - 5*/1, i, j, k);
			}
		}
	}
	clock_t time_start = clock();
	polynom1 *= polynom2;
	clock_t time_end = clock() - time_start;
	cout <<  (double)time_end / CLOCKS_PER_SEC << " s" << endl;
	cout << polynom1.getValue(1, 1, 1) << endl;
	return 0;
}
