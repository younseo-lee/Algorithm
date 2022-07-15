#include <iostream>

int main(void) {
	int N;
	std::cin >> N;

	int apple, stud, sum = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> stud >> apple;
		sum += apple % stud;
	}
	std::cout << sum << std::endl;

	return 0;
}