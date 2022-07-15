#include <iostream>

int main(void) {
	int N;
	std::cin >> N;

	char* num = new char[N];
	std::cin >> num;

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += (int)(num[i] - '0');

	std::cout << sum;
	return 0;
}