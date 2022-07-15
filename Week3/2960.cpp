#include <iostream>
using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;

	int cnt = 1;
	int* check = new int[N + 1]{ 0 };

	int tmp = 1;
	while (cnt <= K) {
		tmp++;
		while (check[tmp] == 1) tmp++;
		for (int i = tmp; i <= N; i += tmp) {
			if (check[i] == 1) continue;
			if (cnt == K) {
				cout << i;
				cnt++;
				break;
			}
			check[i] = 1;
			cnt++;
		}
	}

	delete[] check;
	return 0;
}