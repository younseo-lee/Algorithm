#include <iostream>
#include <queue>
using namespace std;

int x[4] = {0, -1, 0, 1}, y[4] = {-1, 0, 1, 0};
int field[50][50] = {0,}, visited[2][50][50] = {0,};

struct pos {
    int x; 
    int y;
    int dir;
};

int main(void) {
    int N;
    cin >> N;

    int b_cnt = 0, e_cnt = 0;
    char ch;
    struct pos b, e;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> ch;
            if(ch == 'B') {
                field[i][j] = 0;
                b_cnt++;
                
                if(b_cnt == 1) {
                    b.x = j; b.y = i;
                }
                if(b_cnt == 2) {
                    if(j - b.x == 1) b.dir = 0; // 가로
                    else b.dir = 1; // 세로
                    b.x = j; b.y = i;
                }
            }
            else if(ch == 'E') {
                field[i][j] = 0;
                e_cnt++;
                
                if(e_cnt == 1) {
                    e.x = j; e.y = i;
                }
                if(e_cnt == 2) {
                    if(j - e.x == 1) e.dir = 0; // 가로
                    else e.dir = 1; // 세로
                    e.x = j; e.y = i;
                }
            }
            else field[i][j] = ch - '0';
        }
    }

    queue<struct pos> q;
    q.push(b);
    visited[b.dir][b.y][b.x] = 1;

    while(!q.empty()) {
        struct pos tmp = q.front();
        q.pop();

        if(tmp.x == e.x && tmp.y == e.y && tmp.dir == e.dir) {
            cout << visited[tmp.dir][tmp.y][tmp.x] - 1;
            return 0;
        }

        b.dir = tmp.dir;
        for(int i = 0; i < 4; i++) {
            int tmp_x = tmp.x + x[i];
            int tmp_y = tmp.y + y[i];

            if(!b.dir) {
                if(tmp_x <= 0 || tmp_x >= N - 1 || tmp_y < 0 || tmp_y >= N) continue;
                if(field[tmp_y][tmp_x] || field[tmp_y][tmp_x - 1] || field[tmp_y][tmp_x + 1]) continue;
            }
            else {
                if(tmp_x < 0 || tmp_x >= N || tmp_y <= 0 || tmp_y >= N - 1) continue;                
                if(field[tmp_y][tmp_x] || field[tmp_y - 1][tmp_x] || field[tmp_y + 1][tmp_x]) continue;
            }

            if(visited[b.dir][tmp_y][tmp_x]) continue;
            b.x = tmp_x; b.y = tmp_y; 
            q.push(b);
            visited[b.dir][b.y][b.x] = visited[tmp.dir][tmp.y][tmp.x] + 1;
        }
        
        if(b.dir == 1) b.dir = 0;
        else b.dir = 1;

        int flag = 0;
        if(tmp.x <= 0 || tmp.x >= N - 1 || tmp.y <= 0 || tmp.y >= N - 1) continue;
        for(int i = tmp.y - 1; i <= tmp.y + 1; i++) {
            for(int j = tmp.x - 1; j <= tmp.x + 1; j++) {
                if(field[i][j]) flag = 1;
            }
        }

        if(!flag) {
            if(visited[b.dir][tmp.y][tmp.x]) continue;
            b.x = tmp.x; b.y = tmp.y; 
            q.push(b);
            visited[b.dir][b.y][b.x] = visited[tmp.dir][tmp.y][tmp.x] + 1;
        }
    }
    cout << 0;
    return 0;
}