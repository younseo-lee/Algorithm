#include <iostream>
using namespace std;

int main(void) {
	int A, B;
	cin >> A >> B;

	int count = 0;
	while (A < B) {
		if (B % 2 == 0) B /= 2;
		else if (B % 10 == 1) B /= 10;
		else break;

		count++;
	}
	if (A == B) cout << count + 1;
	else cout << -1;
}