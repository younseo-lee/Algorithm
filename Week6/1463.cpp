#include <iostream>
using namespace std;

int* arr;

int make_one(int N);
int main(void) {
	int N;
	cin >> N;
	arr = new int[N + 1] {0, };

	int min = make_one(N);
	cout << min;

	return 0;
}

int make_one(int N) {
	if (N == 1) return 0;
	if (arr[N] != 0) return arr[N];

	int min, temp;
	min = 1 + make_one(N - 1);

	if (N % 3 == 0) {
		temp = 1 + make_one(N / 3);
		if (min > temp) min = temp;
	}
	if (N % 2 == 0) {
		temp = 1 + make_one(N / 2);
		if (min > temp) min = temp;
	}

	arr[N] = min;
	return min;
}