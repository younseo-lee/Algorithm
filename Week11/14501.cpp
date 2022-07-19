#include <iostream>
using namespace std;

int N, *term, *price, *max_price;

int dfs(int index);
int main(void) {
	cin >> N;

	term = new int[N];
	price = new int[N];
	max_price = new int[N] {0};

	for (int i = 0; i < N; i++) {
		cin >> term[i] >> price[i];
	}

	cout << dfs(0);
	return 0;
}

int dfs(int index) {
	if (index >= N) return 0;
	if (max_price[index]) return max_price[index];

	for (int i = index; i < N; i++) {
		if (i + term[i] > N) continue;
		max_price[index] = max(max_price[index], price[i] + dfs(i + term[i]));
	}
	return max_price[index];
}
