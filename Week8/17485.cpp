#include <iostream>

using namespace std;

int N, M;
int** num, *** price;

int min_price(int i, int j, int dir);

int main(void) {
	cin >> N >> M;

	num = new int* [N];
	price = new int** [N];

	for (int i = 0; i < N; i++) {
		num[i] = new int[M];
		price[i] = new int*[M];
		for (int j = 0; j < M; j++) {
			cin >> num[i][j];
			price[i][j] = new int[4]{ 0 };
			//for (int k = 0; k < 4; k++) price[i][j][k] = -1;
		}
	}

	int min_p = min_price(0, 0, 3);
	for (int i = 1; i < M; i++) {
		min_p = min(min_p, min_price(0, i, 3));
	}

	cout << min_p;
	return 0;
}

int min_price(int i, int j, int dir) {
	if (i == N - 1) return num[i][j];
	if (price[i][j][dir]) return price[i][j][dir];

	int min_p = -1;
	if(dir != 1) min_p = min_price(i + 1, j, 1);
	if (j > 0 && dir != 0) {
		if (min_p == -1) min_p = min_price(i + 1, j - 1, 0);
		else min_p = min(min_p, min_price(i + 1, j - 1, 0));
	}
	if (j < M - 1 && dir != 2) {
		if (min_p == -1) min_p = min_price(i + 1, j + 1, 2);
		else min_p = min(min_p, min_price(i + 1, j + 1, 2));
	}

	return price[i][j][dir] = num[i][j] + min_p;
}