#include<iostream>
#include<queue>

using namespace std;

struct elem {
	int x,y;
	elem(int _x, int _y) : x(_x), y(_y) {};
};

void search(queue<elem> &q, int ** array, int &count, int M, int N) {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if (array[x][y] == 0) {
			count++;
			array[x][y] = count;
			if (x - 1 >= 0) {
				if (array[x-1][y] == 0) q.push(elem(x - 1, y));
			}
			if (x + 1 < M) {
				if (array[x+1][y] == 0) q.push(elem(x + 1, y));
			}
			if (y - 1 >= 0) {
				if (array[x][y-1] == 0) q.push(elem(x, y - 1));
			}
			if (y + 1 < N) {
				if (array[x][y+1] == 0) q.push(elem(x, y + 1));
			}
		}
	}
}

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	int **array = new int*[M];
	for (int i = 0; i < M; i++) {
		array[i] = new int[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			array[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		array[x][y] = -1;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << array[j][i] << " ";
		}
		cout << endl;
	}
	int count = 0;
	queue<elem> q;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (array[i][j] == 0) {
				q.push(elem(i, j));
				search(q, array, count, M, N);
			}
		}
	}
	cout << count << endl;
	return 0;
}