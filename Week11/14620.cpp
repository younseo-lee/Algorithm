#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };

int N, ** flower;
int bloom(vector<pair<int, int>>* f, int x, int y);
int check(vector<pair<int, int>>* f1, vector<pair<int, int>>* f2);

int main(void) {
	cin >> N;

	flower = new int* [N];
	for (int i = 0; i < N; i++) {
		flower[i] = new int[N];
		for (int j = 0; j < N; j++) cin >> flower[i][j];
	}

	int result = 3001, cost_i, cost_j, cost_k;
	vector<pair<int, int>> f_i, f_j, f_k;

	for (int i = 0; i < N * N - 2; i++) {
		cost_i = bloom(&f_i, i % N, i / N);
		if (cost_i == -1) continue;

		for (int j = i + 1; j < N * N - 1; j++) {
			cost_j = bloom(&f_j, j % N, j / N);
			if(cost_j == -1) continue;
			if (check(&f_i, &f_j) == -1) continue;

			for (int k = j + 1; k < N * N; k++) {
				cost_k = bloom(&f_k, k % N, k / N);
				if (cost_k == -1) continue;
				if (check(&f_i, &f_k) == -1) continue;
				if (check(&f_j, &f_k) == -1) continue;

				result = min(result, cost_i + cost_j + cost_k);
			}
		}
	}
	
	cout << result;
	return 0;
}

int bloom(vector<pair<int, int>>* f, int x, int y) {
	int cost = 0;

	f->clear();
	f->push_back(make_pair(x, y));
	cost += flower[y][x];

	for (int i = 0; i < 4; i++) {
		int temp_x = x + xx[i];
		int temp_y = y + yy[i];

		if (temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= N) return -1;
		f->push_back(make_pair(temp_x, temp_y));
		cost += flower[temp_y][temp_x];
	}
	return cost;
}

int check(vector<pair<int, int>>* f1, vector<pair<int, int>>* f2) {
	pair<int, int> tmp1, tmp2;
	for (int i = 0; i < f1->size(); i++) {
		tmp1 = f1->at(i);
		for (int j = 0; j < f2->size(); j++) {
			tmp2 = f2->at(j);
			if (tmp1.first == tmp2.first && tmp1.second == tmp2.second) return -1;
		}
	}
	return 0;
}
