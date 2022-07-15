#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int** people = new int* [N + 1];
	people[0] = new int[M + 1]{ 0 };
	int input;

	for (int i = 1; i <= N; i++) {
		people[i] = new int[M + 1]{ 0 };

		for (int j = 1; j <= M; j++) {
			cin >> input;
			people[i][j] = input + people[i - 1][j] + people[i][j - 1] - people[i - 1][j - 1];
		}
	}

	int K, rec[4];
	cin >> K;

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 4; j++) 
			cin >> rec[j];

		cout << people[rec[2]][rec[3]] + people[rec[0] - 1][rec[1] - 1] - people[rec[0] - 1][rec[3]] - people[rec[2]][rec[1] - 1] << "\n";
	}

	return 0;
}