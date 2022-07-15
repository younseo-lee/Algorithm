#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	long long* loss = new long long[N];
	for (int i = 0; i < N; i++) cin >> loss[i];

	sort(loss, loss + N);

	long long max = 0;
	if (N % 2 == 1) {
		max = loss[N - 1];
		N -= 1;
	}

	for (int i = 0; i < N / 2; i++) {
		if (max < loss[i] + loss[N - 1 - i]) max = loss[i] + loss[N - 1 - i];
	}
	cout << max;

	return 0;
}