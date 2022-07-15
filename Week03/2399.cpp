#include <iostream>
#include <cstdlib>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	long long* dot = new long long[n];
	for (int i = 0; i < n; i++) cin >> dot[i];

	long long sum = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			sum += abs(dot[i] - dot[j]) * 2;
		}
	}
	cout << sum;
	return 0;
}