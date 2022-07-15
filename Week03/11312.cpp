#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	long long A, B, sum;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		sum = (A / B) * (A / B);
		cout << sum << '\n';
	}

	return 0;
}