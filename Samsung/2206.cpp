#include <iostream>
#include <queue>
using namespace std;

int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};
int field[1000][1000] = {0,}, visited[2][1000][1000] = {0,};

struct pos{
    int x;
    int y;
    int flag;
};

int main(void) {
    int N, M;
    cin >> N >> M;

    char ch;
    for(int i = 0; i < N; i++) {
        for(int j = 0;j < M; j++) {
            cin >> ch;
            field[i][j] = ch - '0';
        }
    }

    queue<struct pos> q;
    struct pos insert;

    insert.x = 0; insert.y = 0; insert.flag = 0;
    q.push(insert);
    visited[0][0][0] = 1;

    while(!q.empty()) {
        struct pos tmp = q.front();
        q.pop();
        if(tmp.x == M - 1 && tmp.y == N - 1) {
            cout << visited[tmp.flag][tmp.y][tmp.x];
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int tmp_x = tmp.x + x[i];
            int tmp_y = tmp.y + y[i];

            if(tmp_x < 0 || tmp_x >= M || tmp_y < 0 || tmp_y >= N) continue;
            insert.x = tmp_x; 
            insert.y = tmp_y;

            if(field[tmp_y][tmp_x] == 0) insert.flag = tmp.flag;
            else if(!tmp.flag) insert.flag = 1;
            else continue;

            if(visited[insert.flag][insert.y][insert.x]) continue;
            visited[insert.flag][insert.y][insert.x] = visited[tmp.flag][tmp.y][tmp.x] + 1;
            q.push(insert);
        }
    }
    
    cout << -1;
    return 0;
}