#include <iostream>

int main(void) {
	int N;
	std::cin >> N;

	int count = 0;
	for (int i = 5; i <= N; i += 5) {
		int temp = i;
		while (temp % 5 == 0) {
			count++;
			temp /= 5;
		}
	}
	std::cout << count;

	return 0;
}