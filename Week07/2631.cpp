#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int* num = new int[N];
	for (int i = 0; i < N; i++) cin >> num[i];

	int* inc = new int[N];
	inc[0] = 1;

	int inc_max = 1;
	for (int i = 1; i < N; i++) {
		int max = 1;
		for (int j = i - 1; j >= 0; j--) {
			int temp = inc[j];
			if (num[i] > num[j] && temp + 1 > max) max = temp + 1;
		}
		inc[i] = max;
		if (max > inc_max) inc_max = max;
	}
	cout << N - inc_max;

	return 0;
}