#include <iostream>
#include <vector>
using namespace std;

int* start_team, **num, N, result = 400000;

void team(int index, int cnt, int n);
int main(void) {
	cin >> N;

	num = new int* [N];
	start_team = new int[N];
	for (int i = 0; i < N; i++) {
		start_team[i] = 0;
		num[i] = new int[N];
		for (int j = 0; j < N; j++) cin >> num[i][j];
	}

	for (int i = 1; i <= N / 2; i++) {
		team(0, 0, i);
	}
	cout << result;
}

void team(int index, int cnt, int n) {
	if (cnt == n) {
		vector<int> start, link;
		for (int i = 0; i < N; i++) {
			if (start_team[i]) start.push_back(i);
			else link.push_back(i);
		}

		int dif = 0;
		for (int i = 0; i < start.size() - 1; i++) {
			for (int j = i + 1; j < start.size(); j++) {
				dif += (num[start[i]][start[j]] + num[start[j]][start[i]]);
			}
		}

		for (int i = 0; i < link.size() - 1; i++) {
			for (int j = i + 1; j < link.size(); j++) {
				dif -= (num[link[i]][link[j]] + num[link[j]][link[i]]);
			}
		}

		result = min(result, abs(dif));
		return;
	}

	for (int i = index; i < N; i++) {
		start_team[i] = 1;
		team(i + 1, cnt + 1, n);
		start_team[i] = 0;
	}

}
