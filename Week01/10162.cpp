#include <iostream>

int main(void) {
	int T;
	std::cin >> T;

	if (T % 10 != 0) std::cout << "-1" << std::endl;
	else {
		int temp = T / 300;
		std::cout << temp << ' ';

		T -= temp * 300;
		temp = T / 60;
		std::cout << temp << ' ';

		T -= temp * 60;
		std::cout << T / 10 << std::endl;
	}
	return 0;
}