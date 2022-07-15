#include <iostream>
#include <queue>
using namespace std;

int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };

int main(void) {
	int T;
	cin >> T;

	int H, W, ** sheep, ** visited;
	char ch;

	for (int t = 0; t < T; t++) {
		cin >> H >> W;

		sheep = new int* [H + 2];
		visited = new int* [H + 2];

		for (int i = 0; i <= H + 1; i++) {
			sheep[i] = new int[W + 2]{ 0 };
			visited[i] = new int[W + 2]{ 0 };
			if (i == 0 || i == H + 1) continue;

			for (int j = 1; j <= W; j++) {
				cin >> ch;
				sheep[i][j] = ch == '#' ? 1 : 0;
			}
		}

		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));

		pair<int, int> p, sh_p;
		int count = 0;
		while (!q.empty()) {
			p = q.front();
			q.pop();
			if (visited[p.second][p.first]) continue;
			else visited[p.second][p.first] = 1;

			for (int i = 0; i < 4; i++) {
				int temp_x = p.first + xx[i];
				int temp_y = p.second + yy[i];
				if (temp_x < 0 || temp_x > W || temp_y < 0 || temp_y > H || visited[temp_y][temp_x]) continue;

				if (sheep[temp_y][temp_x]) {
					queue < pair<int, int>> sh;
					sh.push(make_pair(temp_x, temp_y));
					sheep[temp_y][temp_x] = 0;

					while (!sh.empty()) {
						sh_p = sh.front();
						sh.pop();

						for (int j = 0; j < 4; j++) {
							int sh_x = sh_p.first + xx[j];
							int sh_y = sh_p.second + yy[j];
							if (sh_x < 1 || sh_x > W || sh_y < 1 || sh_y > H) continue;

							if (sheep[sh_y][sh_x]) {
								sh.push(make_pair(sh_x, sh_y));
								sheep[sh_y][sh_x] = 0;
							}
						}
					}
					count++;
				}
				else q.push(make_pair(temp_x, temp_y));
			}
		}
		cout << count << endl;
	}
	return 0;
}