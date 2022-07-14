#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<int> train(N + 1, 0);
	int cmd, i, x;

	for (int m = 0; m < M; m++) {
		cin >> cmd;
		switch (cmd) {
		case 1:
			cin >> i >> x;
			train[i] |= (1 << x);
			break;
		case 2:
			cin >> i >> x;
			train[i] &= ~(1 << x);
			break;
		case 3:
			cin >> i;
			train[i] = train[i] << 1;
			train[i] &= ((1 << 21) - 1);
			break;
		case 4:
			cin >> i;
			train[i] = train[i] >> 1;
			train[i] &= ~1;
			break;
		}
	}

	int count = 0;
	bool* vis = new bool[1 << 21]{ 0 };
	for (int i = 1; i <= N; i++) {
		if (vis[train[i]]) continue;
		vis[train[i]] = true;
		count++;
	}

	cout << count;
	return 0;
}