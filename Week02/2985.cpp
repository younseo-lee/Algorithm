#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	char r1, r2;
	if (a + b == c) {
		r1 = '+';
		r2 = '=';
	}
	else if (a - b == c) {
		r1 = '-';
		r2 = '=';
	}
	else if (a * b == c) {
		r1 = '*';
		r2 = '=';
	}
	else if (a / b == c) {
		r1 = '/';
		r2 = '=';
	}
	if (a == b + c) {
		r1 = '=';
		r2 = '+';
	}
	else if (a == b - c) {
		r1 = '=';
		r2 = '-';
	}
	else if (a == b * c) {
		r1 = '=';
		r2 = '*';
	}
	else if (a == b / c) {
		r1 = '=';
		r2 = '/';
	}
	cout << a << r1 << b << r2 << c;
	return 0;
}