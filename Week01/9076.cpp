#include <iostream>

int main(void) {
	int T; // 1 <= T <= 10
	std::cin >> T;

	int** score = new int* [T];
	for (int i = 0; i < T; i++) {
		score[i] = new int[5];
		for (int j = 0; j < 5; j++) std::cin >> score[i][j];
	}

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4 - j; k++) {
				if (score[i][k] > score[i][k + 1]) {
					int temp = score[i][k];
					score[i][k] = score[i][k + 1];
					score[i][k + 1] = temp;
				}
			}
		}
		if (score[i][3] - score[i][1] >= 4) std::cout << "KIN" << std::endl;
		else {
			int sum = score[i][1] + score[i][2] + score[i][3];
			std::cout << sum << std::endl;
		}
	}

	for (int i = 0; i < T; i++)
		delete[] score[i];
	delete[] score;
}