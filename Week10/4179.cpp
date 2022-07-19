#include <iostream>
#include <queue>
using namespace std;

int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };

struct pos {
	int x;
	int y;
	int t;
};

int R, C;
char maze[1001][1001];
int visited[1001][1001] = { 0, };

queue<pair<int, int>> fire;
void update_fire();

int main(void) {
	cin >> R >> C;

	queue<struct pos> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'J') {
				struct pos temp;
				temp.x = j; temp.y = i; temp.t = 0;
				q.push(temp);
				maze[i][j] = '.';
				visited[i][j] = 1;
			}
			else if (maze[i][j] == 'F') fire.push(make_pair(i, j));
		}
	}

	struct pos p, temp;
	int time = 0, flag = 0, temp_x, temp_y;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		if (p.t == time) {
			update_fire();
			time++;
		}

		for (int i = 0; i < 4; i++) {
			temp_x = p.x + xx[i];
			temp_y = p.y + yy[i];

			if (temp_x < 0 || temp_x >= C || temp_y < 0 || temp_y >= R) {
				flag = 1;
				break;
			}
				
			if(maze[temp_y][temp_x] != '.' || visited[temp_y][temp_x]) continue;

			temp.x = temp_x;
			temp.y = temp_y;
			temp.t = p.t + 1;

			q.push(temp);
			visited[temp_y][temp_x] = 1;
		}

		if (flag) break;
	}

	if (!flag) cout << "IMPOSSIBLE";
	else cout << time;
	
	return 0;
}

void update_fire() {
	int temp_x, temp_y, cnt = fire.size();
	for (int f = 0; f < cnt; f++) {
		pair<int, int> temp = fire.front();
		fire.pop();

		for (int i = 0; i < 4; i++) {
			temp_x = temp.second + xx[i];
			temp_y = temp.first + yy[i];

			if (temp_x < 0 || temp_x >= C || temp_y < 0 || temp_y >= R || maze[temp_y][temp_x] != '.') continue;

			fire.push(make_pair(temp_y, temp_x));
			maze[temp_y][temp_x] = 'F';
		}
	}
}