#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int num, cnt[2001] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> num;
		cnt[num + 1000]++;
	}

	for (int i = 0; i < 2001; i++) {
		if (cnt[i] > 0) cout << i - 1000 << ' ';
	}

	return 0;
}