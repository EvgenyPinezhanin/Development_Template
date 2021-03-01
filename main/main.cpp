#include<iostream>
#include<polynomial.h>

using namespace std;

int main() {
	//List<int> list;
	//list.push_back(5);
	//list.push_back(6);
	//list.push_back(7);
	//list.push_back(8);
	//listIterator<int> iter = list.begin();
	//while (iter.hasNext()) {
	//	cout << iter.next() << " ";
	//}
	//cout << endl;
	//cout << list << endl;
	monomial m(45, 3, 5, 10);
	cout << m << endl;
	return 0;
}
