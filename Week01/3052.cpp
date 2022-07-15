#include <iostream>

int main(void) {
	int num, rem[10], count = 0;
	for (int i = 0; i < 10; i++) {
		std::cin >> num;
		int r = num % 42;
		int flag = 0;

		for (int j = 0; j < count; j++) {
			if (rem[j] == r) flag = 1;
		}
		if (flag == 0) rem[count++] = r;
	}
	std::cout << count << std::endl;
	return 0;
}