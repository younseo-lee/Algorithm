#include <iostream>
using namespace std;

int field[50][50] = {0,};

int main(void) {
    int N, M;
    cin >> N >> M;

    // 0: 북, 1: 동, 2: 남, 3: 서
    int r, c, d;
    cin >> r >> c >> d;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) cin >> field[i][j];
    }

    int flag = 0, cnt = 1, tmp_d, tmp_r, tmp_c;
    field[r][c] = 2;

    while(1) {
        tmp_d = d;
        for(int i = 0; i < 4; i++) {
            tmp_r = r; tmp_c = c;
            tmp_d = (tmp_d + 3) % 4;

            if(tmp_d == 0) tmp_r--;
            else if(tmp_d == 1) tmp_c++;
            else if(tmp_d == 2) tmp_r++;
            else tmp_c--;

            if(tmp_r < 0 || tmp_r >= N || tmp_c < 0 || tmp_c >= M || field[tmp_r][tmp_c] != 0) continue;
            flag = 1;  
            break;          
        }

        if(flag) {
            r = tmp_r; c = tmp_c; d = tmp_d;
            cnt++;
            field[r][c] = 2;
            flag = 0;
        }
        else {
            if(d == 0) r++;
            else if(d == 1) c--;
            else if(d == 2) r--;
            else c++;
            
            if(r < 0 || r >= N || c < 0 || c >= M || field[r][c] == 1) break;
        }
    }

    cout << cnt;
    return 0;
}