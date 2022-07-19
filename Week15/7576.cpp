#include <iostream>
#include <queue>
using namespace std;

int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};
int tomato[1000][1000];

int main(void) {
    int M, N;
    cin >> M >> N;

    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) q.push(make_pair(i, j));
        }
    }

    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();

        int num = tomato[tmp.first][tmp.second] + 1;

        for(int i = 0; i < 4; i++) {
            int tmp_x = tmp.second + x[i];
            int tmp_y = tmp.first + y[i];

            if(tmp_x < 0 || tmp_x >= M || tmp_y < 0 || tmp_y >= N) continue;

            if(tomato[tmp_y][tmp_x] == 0 || tomato[tmp_y][tmp_x] > num) {
                tomato[tmp_y][tmp_x] = num;
                q.push(make_pair(tmp_y, tmp_x));
            }
        }
    }

    int max_date = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(tomato[i][j] == 0) {
                cout << -1;
                return 0;
            }
            max_date = max(max_date, tomato[i][j]);
        }
    }
    cout << max_date - 1;
    return 0;
}