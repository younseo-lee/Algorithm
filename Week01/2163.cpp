#include <iostream>

int main(void) {
	int N, M;
	std::cin >> N >> M;
	std::cout << N - 1 + (M - 1) * N << std::endl;

	return 0;
}