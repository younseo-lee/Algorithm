#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;

	int* S = new int[N + 1]{ 0 };
	int* D = new int[N + 1]{ 0 };

	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= N; i++) cin >> D[i];

	int* tmp = new int[N + 1]{ 0 };
	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= N; j++) {
			tmp[D[j]] = S[j];
		}
		memcpy(S, tmp, (N + 1) * sizeof(int));
	}
	for (int i = 1; i <= N; i++) cout << S[i] << ' ';
	return 0;
}