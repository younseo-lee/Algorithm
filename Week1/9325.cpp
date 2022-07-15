#include <iostream>

int main(void) {
	int num;
	std::cin >> num;

	int* s = new int[num];
	for (int i = 0; i < num; i++) {
		int n;
		std::cin >> s[i] >> n;

		int q, p;
		for (int j = 0; j < n; j++) {
			std::cin >> q >> p;
			s[i] += q * p;
		}
	}
	for (int i = 0; i < num; i++)
		std::cout << s[i] << std::endl;

	return 0;
}