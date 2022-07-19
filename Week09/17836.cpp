#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int x;
	int y;
	int t;
};

int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };
int visited[101][101] = { 0, };

int main(void) {
	int N, M, T;
	cin >> N >> M >> T;

	int** castle = new int* [N + 1];
	for (int i = 1; i <= N; i++) {
		castle[i] = new int[M + 1];
		for (int j = 1; j <= M; j++) cin >> castle[i][j];
	}

	queue<struct pos> q;
	struct pos p;
	p.x = 1; p.y = 1; p.t = 0;
	q.push(p);
	visited[1][1] = 1;

	int sword = T + 1, flag = 0;
	while (!q.empty() && p.t <= T) {
		p = q.front();
		q.pop(); 

		if (p.y == N && p.x == M) {
			flag = 1;
			break;
		}
		if (castle[p.y][p.x] == 2) {
			sword = min(sword, p.t + N - p.y + M - p.x);
			flag = 1;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int temp_x = p.x + xx[i];
			int temp_y = p.y + yy[i];
			if (temp_x < 1 || temp_x > M || temp_y < 1 || temp_y > N) continue;

			if (!visited[temp_y][temp_x] && castle[temp_y][temp_x] != 1) {
				struct pos temp_p;
				temp_p.x = temp_x; temp_p.y = temp_y;  temp_p.t = p.t + 1;
				q.push(temp_p);
				visited[temp_y][temp_x] = temp_p.t;
			}
		}
	}
	if (!visited[N][M]) visited[N][M] = T + 1;
	
	if (!flag || (visited[N][M] > T && sword > T)) cout << "Fail";
	else cout << min(sword, visited[N][M]);
	return 0;
}