#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int* T = new int[N + 1];
	int* P = new int[N + 1];
	for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];

	int* profit = new int[N + 2];
	profit[N + 1] = 0;

	for (int i = N; i > 0; i--) {
		if (T[i] + i > N + 1) profit[i] = profit[i + 1];
		else profit[i] = max(profit[T[i] + i] + P[i], profit[i + 1]);
	}

	cout << profit[1];

	return 0;
}