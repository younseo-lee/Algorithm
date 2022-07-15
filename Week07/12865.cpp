#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int* W = new int[N + 1];
	int* V = new int[N + 1];
	for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];

	int** value = new int* [N + 1];
	value[0] = new int[K + 1]{ 0, };

	for (int i = 1; i <= N; i++) {
		value[i] = new int[K + 1]{ 0, };

		for (int j = 0; j <= K; j++) {
			if (j >= W[i]) value[i][j] = max(value[i - 1][j], V[i] + value[i - 1][j - W[i]]);
			else value[i][j] = value[i - 1][j];
		}
	}

	cout << value[N][K];
	return 0;
}