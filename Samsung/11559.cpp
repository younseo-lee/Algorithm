#include <iostream>
#include <vector>
using namespace std;

int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};
char field[12][6] = {0,};
int visited[12][6] = {0,};
vector<pair<int, int>> v;

void check(int i, int j);

int main(void) {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) cin >> field[i][j];
    }

    int flag = 0, cnt = 0;
    while(1) {
        flag = 0;
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(field[i][j] == '.') continue;

                check(i, j);
                if(v.size() >= 4) {
                    for(int k = 0; k < v.size(); k++) {
                        field[v[k].first][v[k].second] = '.';
                    }
                    flag = 1;
                }
                for(int k = 0; k < v.size(); k++) visited[v[k].first][v[k].second] = 0;
                v.clear();
            }
        }
        if(!flag) break;
        cnt++;

        for(int j = 0; j < 6; j++) {
            for(int i = 10; i >= 0; i--) {
                int tmp_i = i;
                while(field[tmp_i + 1][j] == '.') {
                    field[tmp_i + 1][j] = field[tmp_i][j];
                    field[tmp_i][j] = '.';
                    tmp_i++;
                }
            }
        }    
    }
    cout << cnt;
    return 0;
}

void check(int i, int j) {
    v.push_back(make_pair(i, j));
    visited[i][j] = 1;

    for(int k = 0; k < 4; k++) {
        int tmp_x = j + x[k];
        int tmp_y = i + y[k];

        if(tmp_x < 0 || tmp_x >= 6 || tmp_y < 0 || tmp_y >= 12) continue;
        if(visited[tmp_y][tmp_x]) continue;
        if(field[tmp_y][tmp_x] == field[i][j]) check(tmp_y, tmp_x);
    }
}