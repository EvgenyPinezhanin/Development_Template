#include<iostream>

using namespace std;

int main() {
	int N;
	int* array = new int[N];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		bool b = true;
		for (int j = 0; j < N; j++) {
			if (array[j] == i) {
				b = false;
				break;
			}
		}
		int k = i;
		int c = 1;
		if (b) {
			while (k != -1) {
				k = array[k];
				if (k != -1) c++;
			}
		}
		if (c > count) count = c;
	}
	
	cout << count << endl;
	return 0;
}
