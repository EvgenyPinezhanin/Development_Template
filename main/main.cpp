#include<iostream>
#include<converter.h>

using namespace std;

int main() {
	cout << "Hello!" << endl;
	int k = 0;
	arabic ar;
	converter conv;
	while (k != 4000) {
		cout << "Enter arabic number: ";
		cin >> k;
		ar.value = k;
		conv.setArabic(ar);
		cout << "Roman number: " << conv.getRoman().value << endl;
	}
	
	return 0;
}
