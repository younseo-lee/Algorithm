#include <iostream>
using namespace std;

int main(void) {
	int people, space;
	cin >> people >> space;

	people *= space;

	int news[5];
	for (int i = 0; i < 5; i++) cin >> news[i];
	for (int i = 0; i < 5; i++) cout << news[i] - people << ' ';

	return 0;
}