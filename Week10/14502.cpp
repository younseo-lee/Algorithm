#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };

int N, M, map[8][8], safe[8][8];
vector<pair<int, int>> blank, virus;

int bfs(int w1, int w2, int w3);

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) blank.push_back(make_pair(i, j));
			else if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
	
	int result = 0;
	for (int i = 0; i < blank.size() - 2; i++) {
		for (int j = i + 1; j < blank.size() - 1; j++) {
			for (int k = j + 1; k < blank.size(); k++) {
				result = max(result, bfs(i, j, k));
			}
		}
	}
	cout << result;
	return 0;
}

int bfs(int w1, int w2, int w3) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) safe[i][j] = map[i][j];
	}
	safe[blank[w1].first][blank[w1].second] = 1;
	safe[blank[w2].first][blank[w2].second] = 1;
	safe[blank[w3].first][blank[w3].second] = 1;

	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) q.push(virus[i]);

	pair<int, int> p;
	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int temp_x = p.second + xx[i];
			int temp_y = p.first + yy[i];

			if (temp_x < 0 || temp_x >= M || temp_y < 0 || temp_y >= N || safe[temp_y][temp_x] != 0) continue;

			q.push(make_pair(temp_y, temp_x));
			safe[temp_y][temp_x] = 2;
		}
	}
	
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!safe[i][j]) count++;
		}
	}
	return count;
}