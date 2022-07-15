#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int* t = new int[N];
	for (int i = 0; i < N; i++) cin >> t[i];

	sort(t, t + N);

	int sum = 0;
	for (int i = 0; i < N; i++) sum += t[i] * (N - i);
	cout << sum;

	return 0;
}