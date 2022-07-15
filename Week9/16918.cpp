#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int R, C, N;
	cin >> R >> C >> N;

	int** board = new int* [R + 2];
	char in;
	board[0] = new int[C + 2];
	board[R + 1] = new int[C + 2];
	for (int i = 1; i <= R; i++) {
		board[i] = new int[C + 2];
		for (int j = 1; j <= C; j++) {
			cin >> in;
			board[i][j] = in == '.' ? 0 : 1;
		}
	}

	for (int time = 2; time <= N; time++) {
		if (time % 2 == 0) {
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					if (board[i][j] == 0) board[i][j] = 1;
					else board[i][j] = 2;
				}
			}
		}
		else {
			vector<pair<int, int>> v;
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					if (board[i][j] == 1) board[i][j] = 2;
					else if(board[i][j] == 2) {
						v.push_back(make_pair(i, j));
					}
				}
			}
			for (int k = 0; k < v.size(); k++) {
				int i = v[k].first;
				int j = v[k].second;
				board[i][j] = 0;
				board[i - 1][j] = 0;
				board[i + 1][j] = 0;
				board[i][j - 1] = 0;
				board[i][j + 1] = 0;
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] == 0) cout << '.';
			else cout << 'O';
		}
		cout << endl;
	}

}