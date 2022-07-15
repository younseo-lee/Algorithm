#include <iostream>
using namespace std;

int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };
int N, M, paper[501][501];

struct tet {
	int i1;
	int j1;
	int i2;
	int j2;
};

struct tet s1[8] = { {0, 0, 1, 0}, {1, 0, 2, 0}, {0, 1, 1, 1}, {1, 1, 2, 1}, \
					{0, 0, 0, 1}, {0, 1, 0, 2}, {1, 0, 1, 1}, {1, 1, 1, 2} };
struct tet s2[4] = { {0, 0, 2, 1}, {0, 1, 2, 0}, {0, 0, 1, 2}, {1, 0, 0, 2} };
struct tet s3[4] = { {0, 0, 2, 0}, {0, 1, 2, 1}, {0, 0, 0, 2}, {1, 0, 1, 2} };

int shape1(int i, int j);
int shape2(int i, int j);
int shape3(int i, int j);
int shape4(int i, int j);
int shape5(int i, int j);

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> paper[i][j];
	}

	int _max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			_max = max(_max, shape1(i, j));
			_max = max(_max, shape2(i, j));
			_max = max(_max, shape3(i, j));
			_max = max(_max, shape4(i, j));
			_max = max(_max, shape5(i, j));
		}
	}

	cout << _max;
	return 0;
}

int shape1(int i, int j) {
	int dir1 = 0, dir2 = 0;
	if (i + 3 < N) {
		for (int k = 0; k < 4; k++) dir1 += paper[i + k][j];
	}
	if (j + 3 < M) {
		for (int k = 0; k < 4; k++) dir2 += paper[i][j + k];
	}
	return max(dir1, dir2);
}

int shape2(int i, int j) {
	if (i + 1 < N && j < 1 < M) {
		return paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1];
	}
	return 0;
}

int shape3(int i, int j) {
	int sum1 = 0, sum2 = 0, _max = 0;
	sum1 = sum2 = shape2(i, j);

	if (i + 2 < N && j + 1 < M) {
		sum1 += paper[i + 2][j] + paper[i + 2][j + 1];

		int _min = sum1;
		for (int k = 0; k < 4; k++) {
			_min = min(_min, paper[i + s1[k].i1][j + s1[k].j1] + paper[i + s1[k].i2][j + s1[k].j2]);
		}
		sum1 -= _min;
	}

	if (i + 1 < N && j + 2 < M) {
		sum2 += paper[i][j + 2] + paper[i + 1][j + 2];

		int _min = sum2;
		for (int k = 4; k < 8; k++) {
			_min = min(_min, paper[i + s1[k].i1][j + s1[k].j1] + paper[i + s1[k].i2][j + s1[k].j2]);
		}
		sum2 -= _min;
	}
	return max(sum1, sum2);
}

int shape4(int i, int j) {
	int sum1 = 0, sum2 = 0, _max = 0;
	sum1 = sum2 = shape2(i, j);

	if (i + 2 < N && j + 1 < M) {
		sum1 += paper[i + 2][j] + paper[i + 2][j + 1];

		int _min = sum1;
		for (int k = 0; k < 2; k++) {
			_min = min(_min, paper[i + s2[k].i1][j + s2[k].j1] + paper[i + s2[k].i2][j + s2[k].j2]);
		}
		sum1 -= _min;
	}

	if (i + 1 < N && j + 2 < M) {
		sum2 += paper[i][j + 2] + paper[i + 1][j + 2];

		int _min = sum2;
		for (int k = 2; k < 4; k++) {
			_min = min(_min, paper[i + s2[k].i1][j + s2[k].j1] + paper[i + s2[k].i2][j + s2[k].j2]);
		}
		sum2 -= _min;
	}
	return max(sum1, sum2);
}

int shape5(int i, int j) {
	int sum1 = 0, sum2 = 0, _max = 0;
	sum1 = sum2 = shape2(i, j);

	if (i + 2 < N && j + 1 < M) {
		sum1 += paper[i + 2][j] + paper[i + 2][j + 1];

		int _min = sum1;
		for (int k = 0; k < 2; k++) {
			_min = min(_min, paper[i + s3[k].i1][j + s3[k].j1] + paper[i + s3[k].i2][j + s3[k].j2]);
		}
		sum1 -= _min;
	}

	if (i + 1 < N && j + 2 < M) {
		sum2 += paper[i][j + 2] + paper[i + 1][j + 2];

		int _min = sum2;
		for (int k = 2; k < 4; k++) {
			_min = min(_min, paper[i + s3[k].i1][j + s3[k].j1] + paper[i + s3[k].i2][j + s3[k].j2]);
		}
		sum2 -= _min;
	}
	return max(sum1, sum2);
}