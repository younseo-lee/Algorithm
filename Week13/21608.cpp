#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };

int N, ** seat;

vector<int> *like;

void find_seat(int num);

int main(void) {
	cin >> N;

	seat = new int* [N];
	for (int i = 0; i < N; i++) seat[i] = new int[N] {0};
	like = new vector<int>[N * N + 1];

	int num, tmp;
	for (int i = 0; i < N * N; i++) {
		cin >> num;
		for (int j = 0; j < 4; j++) {
			cin >> tmp;
			like[num].push_back(tmp);
		}
		find_seat(num);
	}
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			num = seat[i][j];

			int like_tmp = 0;
			for (int k = 0; k < 4; k++) {
				int x_tmp = j + xx[k], y_tmp = i + yy[k];
				if (x_tmp < 0 || x_tmp >= N || y_tmp < 0 || y_tmp >= N) continue;
				if (find(like[num].begin(), like[num].end(), seat[y_tmp][x_tmp]) != like[num].end()) like_tmp++;
			}
			if(like_tmp) sum += pow(10, like_tmp - 1);
		}
	}
	cout << sum;
	return 0;
}

void find_seat(int num) {
	int like_cnt = 0, empty_cnt = 0;
	pair<int, int> max_seat = make_pair(-1, -1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (seat[i][j]) continue;
			if (max_seat.first == -1 && max_seat.second == -1) max_seat = make_pair(i, j);

			int like_tmp = 0, empty_tmp = 0;
			for (int k = 0; k < 4; k++) {
				int x_tmp = j + xx[k], y_tmp = i + yy[k];
				if (x_tmp < 0 || x_tmp >= N || y_tmp < 0 || y_tmp >= N) continue;

				if (!seat[y_tmp][x_tmp]) empty_tmp++;
				else if (find(like[num].begin(), like[num].end(), seat[y_tmp][x_tmp]) != like[num].end()) like_tmp++;
			}

			if (like_cnt < like_tmp) {
				like_cnt = like_tmp;
				empty_cnt = empty_tmp;
				max_seat = make_pair(i, j);
			}
			else if (like_cnt == like_tmp) {
				if (empty_cnt < empty_tmp) {
					empty_cnt = empty_tmp;
					max_seat = make_pair(i, j);
				}
			}
		}
	}
	seat[max_seat.first][max_seat.second] = num;
}