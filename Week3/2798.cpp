#include <iostream>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	int* card = new int[N];
	int min = 0;
	for (int i = 0; i < N; i++) cin >> card[i];

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int tmp = card[i] + card[j] + card[k];
				if (tmp <= M && M - tmp < M - min) min = tmp;
			}
		}
	}
	cout << min;
	return 0;
}