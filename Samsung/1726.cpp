#include <iostream>
#include <queue>
using namespace std;

int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};
int field[101][101] = {0,}, visited[4][101][101] = {0,};

struct pos {
    int x; 
    int y;
    int dir; // 동쪽이 0, 남쪽이 1, 서쪽이 2, 북쪽이 3
    int cnt;
};

int main(void) {
    int M, N;
    cin >> M >> N;

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) cin >> field[i][j];
    }

    struct pos start, end, insert;
    cin >> start.y >> start.x >> start.dir;
    if(start.dir == 2) start.dir = 3;
    else if(start.dir == 3) start.dir = 2;
    start.dir--;

    cin >> end.y >> end.x >> end.dir;
    if(end.dir == 2) end.dir = 3;
    else if(end.dir == 3) end.dir = 2;
    end.dir--;

    queue<struct pos> q;
    start.cnt = 0;
    q.push(start);
    visited[start.dir][start.y][start.x] = 1;

    while(!q.empty()) {
        struct pos tmp = q.front();
        q.pop();

        if(tmp.x == end.x && tmp.y == end.y && tmp.dir == end.dir) {
            cout << tmp.cnt;
            return 0;
        }
        tmp.cnt++;

        for(int i = 1; i <= 3; i++) {
            int tmp_x = tmp.x + x[tmp.dir] * i;
            int tmp_y = tmp.y + y[tmp.dir] * i;

            if(tmp_x <= 0 || tmp_x > N || tmp_y <= 0 || tmp_y > M || field[tmp_y][tmp_x]) break;
            if(visited[tmp.dir][tmp_y][tmp_x]) continue;

            insert.x = tmp_x;
            insert.y = tmp_y;
            insert.dir = tmp.dir;
            insert.cnt = tmp.cnt;

            q.push(insert);
            visited[insert.dir][insert.y][insert.x] = 1;
        }

        insert.x = tmp.x;
        insert.y = tmp.y;
        insert.dir = (tmp.dir + 1) % 4;
        insert.cnt = tmp.cnt;
        if(!visited[insert.dir][insert.y][insert.x]) {
            q.push(insert);
            visited[insert.dir][insert.y][insert.x] = 1;
        }

        insert.x = tmp.x;
        insert.y = tmp.y;
        insert.dir = (tmp.dir + 3) % 4;
        insert.cnt = tmp.cnt;        
        if(!visited[insert.dir][insert.y][insert.x]) {
            q.push(insert);
            visited[insert.dir][insert.y][insert.x] = 1;
        }
    }

    cout << 0;
    return 0;
}