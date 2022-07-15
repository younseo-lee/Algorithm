#include <iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;

	int* a = new int[T];
	int* b = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> a[i] >> b[i];
	}

	int max, min; 
	for (int i = 0; i < T; i++) {
		if (a[i] >= b[i]) {
			max = a[i];
			min = b[i];
		}
		else {
			max = b[i];
			min = a[i];
		}
		for (int j = max; ; j += max) {
			if (j % min == 0) {
				cout << j << ' ';
				break;
			}
		}
		for (int j = min; j >= 1; j--) {
			if (min % j == 0 && max % j == 0) {
				cout << j << endl;
				break;
			}
		}
	}
	return 0;
}