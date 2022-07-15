#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int* liter = new int[N];
	for (int i = 0; i < N; i++) cin >> liter[i];

	sort(liter, liter + N);
	double sum = liter[N - 1];
	for (int i = 0; i < N - 1; i++) {
		sum += liter[i] / 2.0;
	}
	cout << sum;

	return 0;
}