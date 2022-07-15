#include <iostream>
using namespace std;

int* one, * two, N, K;
int min_jump(int n, int flag);

int main(void) {
	cin >> N;

	one = new int[N - 1];
	two = new int[N - 1];

	for (int i = 0; i < N - 1; i++) cin >> one[i] >> two[i];
	cin >> K;

	int min_energy = min_jump(0, 0);
	cout << min_energy;

	return 0;
}

int min_jump(int n, int flag) {
	if (n == N - 1) return 0;

	int min_energy = one[n] + min_jump(n + 1, flag);
	if (n + 2 < N) {
		int temp = two[n] + min_jump(n + 2, flag);
		min_energy = min(temp, min_energy);
	}
	if (n + 3 < N && flag == 0) {
		int temp = K + min_jump(n + 3, 1);
		min_energy = min(temp, min_energy);
	}
	return min_energy;
}