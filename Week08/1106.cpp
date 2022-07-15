#include <iostream>

using namespace std;

int main(void) {
	int C, N;
	cin >> C >> N;

	int* price = new int[N];
	int* client = new int[N];
	for (int i = 0; i < N; i++) cin >> price[i] >> client[i];

	int* min_price = new int[C + 1]{ 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < client[i]; j++) {
			if (min_price[j]) min_price[j] = min(min_price[j], price[i]);
			else min_price[j] = price[i];
		}
		for (int j = client[i]; j <= C; j++) {
			if (min_price[j]) min_price[j] = min(min_price[j], price[i] + min_price[j - client[i]]);
			else min_price[j] = price[i] + min_price[j - client[i]];
		}
	}

	cout << min_price[C];
	return 0;
}
