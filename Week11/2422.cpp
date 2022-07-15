#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<int>* v = new vector<int>[N + 1];

	int p1, p2;
	for (int i = 0; i < M; i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}

	int count = 0;
	for (int i = 1; i <= N - 2; i++) {
		for (int j = i + 1; j <= N - 1; j++) {
			if (find(v[j].begin(), v[j].end(), i) != v[j].end()) continue;
			for (int k = j + 1; k <= N; k++) {
				if (find(v[k].begin(), v[k].end(), i) != v[k].end() || find(v[k].begin(), v[k].end(), j) != v[k].end()) continue;
				count++;
			}
		}
	}
	cout << count;
	return 0;
}