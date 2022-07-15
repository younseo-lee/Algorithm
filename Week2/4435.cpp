#include <iostream>
using namespace std;

int main(void) {
	int a[6] = { 1, 2, 3, 3, 4, 10 };
	int b[7] = { 1, 2, 2, 2, 3, 5, 10 };

	int N;
	cin >> N;

	int* result = new int[N];
	for (int i = 0; i < N; i++) {
		int sum_a = 0, sum_b = 0, temp;
		for (int j = 0; j < 6; j++) {
			cin >> temp;
			sum_a += temp * a[j];
		}
		for (int j = 0; j < 7; j++) {
			cin >> temp;
			sum_b += temp * b[j];
		}
		result[i] = sum_a - sum_b;
	}

	for (int i = 0; i < N; i++) {
		cout << "Battle " << i + 1 << ": ";
		if (result[i] > 0) cout << "Good triumphs over Evil" << endl;
		else if (result[i] < 0) cout << "Evil eradicates all trace of Good" << endl;
		else if (result[i] == 0) cout << "No victor on this battle field" << endl;
	}
	return 0;
}