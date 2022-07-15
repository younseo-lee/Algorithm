#include <iostream>
#include <queue>
using namespace std;

int x[2][6] = { {-1, -1, 0, 1, 0, -1}, {-1, 0, 1, 1, 1, 0} };
int y[6] = { 0, -1, -1, 0, 1, 1 };

int main(void) {
	int W, H;
	cin >> W >> H;

	int** map = new int* [H + 2];
	map[0] = new int[W + 2]{ 0 };
	map[H + 1] = new int[W + 2]{ 0 };
	for (int i = 1; i <= H; i++) {
		map[i] = new int[W + 2]{ 0 };
		for (int j = 1; j <= W; j++) cin >> map[i][j];
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	pair<int, int> p;
	int visited[102][102] = { 0, }, count = 0;
	visited[0][0] = 1;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		int index = p.first % 2;
		for (int i = 0; i < 6; i++) {
			int temp_y = p.first + y[i];
			int temp_x = p.second + x[index][i];
			if (temp_y >= 0 && temp_y <= H + 1 && temp_x >= 0 && temp_x <= W + 1) {
				if (map[temp_y][temp_x] == 1) {
					count++;
					continue;
				}
				if (!visited[p.first + y[i]][p.second + x[index][i]]) {
					q.push(make_pair(temp_y, temp_x));
					visited[temp_y][temp_x] = 1;
				}
			}
		}
	}
	cout << count;
	return 0;
}