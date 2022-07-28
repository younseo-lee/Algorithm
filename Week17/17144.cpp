#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};

int main(void) {
    int R, C, T; 
    cin >> R >> C >> T;

    int **house = new int*[R];
    int **tmp = new int*[R];
    vector<pair<int, int>> air;
    
    for(int i = 0; i < R; i++) {
        house[i] = new int[C];
        tmp[i] = new int[C]{0};
        for(int j = 0; j < C; j++) {
            cin >> house[i][j];
            if(house[i][j] == -1) air.push_back(make_pair(i, j));
        }
    }

    for(int t = 0; t < T; t++) {
        for(int i = 0; i < R; i++) 
            for(int j = 0; j < C; j++) tmp[i][j] = 0;

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(house[i][j] == -1) tmp[i][j] = -1;
                else if(house[i][j] > 0) {
                    int cnt = 0; 
                    for(int k = 0; k < 4; k++) {
                        int tmp_x = j + x[k], tmp_y = i + y[k];
                        if(tmp_x < 0 || tmp_x >= C || tmp_y < 0 || tmp_y >= R || house[tmp_y][tmp_x] == -1) continue;
                        tmp[tmp_y][tmp_x] += house[i][j] / 5; 
                        cnt++;
                    }
                    tmp[i][j] += house[i][j] - (house[i][j] / 5) * cnt;
                }
            }
        }
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                house[i][j] = tmp[i][j];
            }
        }

        for(int i = air[0].first - 1; i > 0; i--) house[i][air[0].second] = house[i - 1][air[0].second];
        for(int j = air[0].second; j < C - 1; j++) house[0][j] = house[0][j + 1];
        for(int i = 0; i < air[0].first; i++) house[i][C - 1] = house[i + 1][C - 1];
        for(int j = C - 1; j > air[0].second + 1; j--) house[air[0].first][j] = house[air[0].first][j - 1];
        house[air[0].first][air[0].second + 1] = 0;

        for(int i = air[1].first + 1; i < R - 1; i++) house[i][air[1].second] = house[i + 1][air[1].second];
        for(int j = air[1].second; j < C - 1; j++) house[R - 1][j] = house[R - 1][j + 1];
        for(int i = R - 1; i > air[1].first; i--) house[i][C - 1] = house[i - 1][C - 1];
        for(int j = C - 1; j > air[1].second + 1; j--) house[air[1].first][j] = house[air[1].first][j - 1];
        house[air[1].first][air[0].second + 1] = 0;
    }

    int sum = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(house[i][j] == -1) continue;
            sum += house[i][j];
        }
    }
    cout << sum; 
    return 0;
}