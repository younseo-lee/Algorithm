#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int S, T;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		v.push_back(make_pair(S, T));
	}

	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(v[0].second);

	for (int i = 1; i < N; i++) {
		if (q.top() <= v[i].first) q.pop();
		q.push(v[i].second);
	}

	cout << q.size();
	return 0;
}