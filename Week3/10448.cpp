#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int K;	// 3 ¡Â K ¡Â 1,000
	int push = 1, cnt, min = 0;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> K;
		while (1) {
			int tmp = (push * (push + 1)) / 2;
			if (tmp >= K) break;
			v.push_back(tmp);
			push++;
		}

		cnt = push - 2;
		while (v[cnt] >= K) cnt--;

		int flag = 0;
		while(cnt >= 0) {
			int i = cnt;
			int rem = K - v[cnt];
			while (v[cnt] >= K) i--;
			for (int j = i; j >= 0; j--) {
				for (int k = i; k >= 0; k--) {
					if (v[j] + v[k] == rem) {
						flag = 1;
						break;
					}
				}
			}
			if (flag) break;
			cnt--;
		}
		if (flag) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}