#include <iostream>

int main(void) {
	int num, sum = 0, min = 0;
	for (int i = 0; i < 7; i++) {
		std::cin >> num;
		if (num % 2 == 1) {
			sum += num;
			if (min == 0 || min > num) min = num;
		}
	}
	if (sum == 0) std::cout << -1 << std::endl;
	else std::cout << sum << '\n' << min << std::endl;

	return 0;
}