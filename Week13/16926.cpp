#include <iostream>
using namespace std;
	
int N, M, R, ** arr;

void rotation(void);
int main(void) {
	cin >> N >> M >> R;

	arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M] {0};
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < R; i++) rotation();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cout << arr[i][j] << ' ';
		cout << endl;
	}

	return 0;
}

void rotation(void) {
	int x = M, y = N;
	while (x > M / 2 && y > N / 2) {
		int tmp = arr[N - y][M - x];
		for (int i = M - x; i < x - 1; i++) arr[N - y][i] = arr[N - y][i + 1];
		for (int i = N - y; i < y - 1; i++) arr[i][x - 1] = arr[i + 1][x - 1];
		for (int i = x - 1; i > M - x; i--) arr[y - 1][i] = arr[y - 1][i - 1];	
		for (int i = y - 1; i > N - y; i--) arr[i][M - x] = arr[i - 1][M - x];
		arr[N - y + 1][M - x] = tmp;

		x--; y--;
	}
}