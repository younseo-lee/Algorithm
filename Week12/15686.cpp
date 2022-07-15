#include <iostream>
#include <vector>
using namespace std;

int N, M, ** city, * store, result = -1;
vector<pair<int, int>> house, chicken;

void distance(int index, int cnt, int n);
int main(void) {
	cin >> N >> M;

	city = new int* [N];
	for (int i = 0; i < N; i++) {
		city[i] = new int[N];

		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) house.push_back(make_pair(i, j));
			else if (city[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}

	store = new int[chicken.size()]{ 0 };
	for (int i = 1; i <= M; i++) {
		distance(0, 0, i);
	}
	cout << result;
	return 0;
}

void distance(int index, int cnt, int n) {
	if (cnt == n) {
		vector<pair<int, int>> tmp;
		for (int i = 0; i < chicken.size(); i++) {
			if (store[i]) tmp.push_back(chicken[i]);
		}

		int dist = 0;
		for (int i = 0; i < house.size(); i++) {
			int min_dist = 100;
			for (int j = 0; j < tmp.size(); j++) {
				min_dist = min(min_dist, abs(house[i].first - tmp[j].first) + abs(house[i].second - tmp[j].second));
			}
			dist += min_dist;
		}

		if (result == -1) result = dist;
		else result = min(result, dist);
	}

	for (int i = index; i < chicken.size(); i++) {
		store[i] = 1;
		distance(i + 1, cnt + 1, n);
		store[i] = 0;
	}
}