#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int find_max(vector<pair<int, int>> v);
int main(void) {
	int N;
	cin >> N;

	vector<pair<int, int>> v;
	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(), v.end());

	int max = find_max(v);
	cout << max;

	return 0;
}

int find_max(vector<pair<int, int>> v) {
	int end = v[0].first, max = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].second >= end) {
			end = v[i].first;
			max++;
		}
	}
	return max;
}