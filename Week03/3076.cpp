#include <iostream>
using namespace std;

int main(void) {
	int R, C, A, B;
	cin >> R >> C >> A >> B;

	char ch1, ch2;
	for (int i = 0; i < R * A; i++) {
		if ((i / A) % 2 == 0) {
			ch1 = 'X';
			ch2 = '.';
		}
		else {
			ch1 = '.';
			ch2 = 'X';
		}

		for (int j = 0; j < C * B; j++) {
			if ((j / B) % 2 == 0) cout << ch1;
			else cout << ch2;
		}
		cout << '\n';
	}
}