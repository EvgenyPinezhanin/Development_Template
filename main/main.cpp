#include<iostream>
#include<stack>

using namespace std;

int heightSearch(int* arrayN, int* arrayD, int k) {
	if (k == -1) return 1;
		else if (arrayD[k] > 0) return arrayD[k] + 1;
		 	else arrayD[k] = heightSearch(arrayN, arrayD, arrayN[k]);
	return arrayD[k] + 1;
}

int RecurAlg(int* arrayN, int* arrayD, int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		arrayD[i] = heightSearch(arrayN, arrayD, arrayN[i]);
		if (arrayD[i] > count) count = arrayD[i];
	}
	return count;
}

int IterAlg(int* arrayN, int* arrayD, int N) {
	int count = 1;
	int k = 0;
	stack<int> st;
 	for (int i = 0; i < N; i++) {
		k = arrayN[i];
		st.push(i);
		while(true) {
			if ((k == -1) || (arrayD[k] > 0)) {
				while(!st.empty()) {
					if (k == -1) {
						arrayD[st.top()] = 1;
					} else {
						arrayD[st.top()] = arrayD[k] + 1;
					}
					k = st.top();
					st.pop();
				}
				break;
			}
			st.push(k);
			k = arrayN[k];
		}
		if (arrayD[i] > count) count = arrayD[i];
	}
	return count;
}

int main() {
	int N;
	cin >> N;
	int* arrayNode = new int[N];
	int* arrayDepth = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arrayNode[i];
		arrayDepth[i] = 0;
	}
	int count = RecurAlg(arrayNode, arrayDepth, N);
	cout << count << endl;
	for (int i = 0; i < N; i++) {
		arrayDepth[i] = 0;
	}
	count = IterAlg(arrayNode, arrayDepth, N);
	cout << count << endl;
	return 0;
}


/* for (int i = 0; i < N; i++) {
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
} */

/* int count = 0;
for (int i = 0; i < N; i++) {
	int k = i;
	int c = 1;
	while (k != -1) {
		k = array[k];
		if (k != -1) c++;
	}
	if (c > count) count = c;
} */
