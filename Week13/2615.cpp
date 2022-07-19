#include <iostream>
#include <vector>
using namespace std;

int xx[4] = { 0, 1, 1, 1 };
int yy[4] = { 1, 0, 1, -1 };

int main(void) {
	vector<pair<int, int>> black, white;
	int board[21][21] = { 0, };

	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) black.push_back(make_pair(i, j));
			else if (board[i][j] == 2) white.push_back(make_pair(i, j));
		}
	}

	while (!black.empty()) {
		pair<int, int> xy = black[0];
		black.erase(black.begin());

		for (int i = 0; i < 4; i++) {
			int flag = 0;
			for (int j = 1; j <= 5; j++) {
				int temp_x = xy.second + xx[i] * j;
				int temp_y = xy.first + yy[i] * j;

				if (j == 5 && board[temp_y][temp_x] != 1) {
					flag = 1;
					break;
				}
				if (temp_x <= 0 || temp_x > 19 || temp_y <= 0 || temp_y > 19 || board[temp_y][temp_x] != 1) break;
			}
			if (flag) {
				int temp_x = xy.second - xx[i];
				int temp_y = xy.first - yy[i];

				if (board[temp_y][temp_x] != 1) {
					cout << "1\n";
					cout << xy.first << ' ' << xy.second;
					return 0;
				}
			}
		}
	}
	
	while (!white.empty()) {
		pair<int, int> xy = white[0];
		white.erase(white.begin());

		for (int i = 0; i < 4; i++) {
			int flag = 0;
			for (int j = 1; j <= 5; j++) {
				int temp_x = xy.second + xx[i] * j;
				int temp_y = xy.first + yy[i] * j;

				if (j == 5 && board[temp_y][temp_x] != 2) {
					flag = 1;
					break;
				}
				if (temp_x <= 0 || temp_x > 19 || temp_y <= 0 || temp_y > 19 || board[temp_y][temp_x] != 2) break;
			}
			if (flag) {
				int temp_x = xy.second - xx[i];
				int temp_y = xy.first - yy[i];

				if (board[temp_y][temp_x] != 2) {
					cout << "2\n";
					cout << xy.first << ' ' << xy.second;
					return 0;
				}
			}
		}
	}
	cout << "0";
	return 0;
}