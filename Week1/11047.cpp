#include <iostream>

int main(void) {
	int N, K;
	std::cin >> N >> K;

	int* coin = new int[N];
	for (int i = 0; i < N; i++) std::cin >> coin[i];

	int sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		int num = K / coin[i];
		K -= num * coin[i];
		sum += num;
	}
	std::cout << sum << std::endl;

	return 0;
}