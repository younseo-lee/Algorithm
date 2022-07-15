#include <iostream>
using namespace std;

int main(void) {
	int X;
	cin >> X;

	int count;
	if (X < 100) count = X;
	else count = 99;

	int ten = (X % 100) / 10, one = X % 10;
	for (int i = 1; i <= X / 100; i++) {
		int dif = 0;
		for(dif = 0; dif <= i / 2; dif++) {
			int tmp_ten = i - dif;
			int tmp_one = tmp_ten - dif;
			if (i < X / 100 || tmp_ten < ten || (tmp_ten == ten && tmp_one <= one)) count++;
		}
		for (dif = 1; dif <= (9 - i) / 2; dif++) {
			int tmp_ten = i + dif;
			int tmp_one = tmp_ten + dif;
			if (i < X / 100 || tmp_ten < ten || (tmp_ten == ten && tmp_one <= one)) count++;
		}
	}
	cout << count;
	return 0;
}