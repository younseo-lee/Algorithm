#include <iostream>
#include <queue>
using namespace std;

struct pos {
    int x;
    int y;
    int dir;
};
int house[17][17]; 

int main(void) {
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin>> house[i][j];
    }

    queue<struct pos> q;
    struct pos init = {1, 2, 1};
    q.push(init);

    int count = 0; 
    while(!q.empty()) {
        struct pos tmp = q.front();
        q.pop();
        
        if(house[tmp.x][tmp.y]) continue;
        if(tmp.dir == 3) {
            if(house[tmp.x - 1][tmp.y] || house[tmp.x][tmp.y - 1]) continue;
        }
        if(tmp.x == N && tmp.y == N) {
            count++;
            continue;
        }

        switch(tmp.dir) {
        case 1:
            if(tmp.y == N) break;
            tmp.y++; 
            q.push(tmp);

            if(tmp.x == N) break;
            tmp.x++;
            tmp.dir = 3;
            q.push(tmp);   
            break;

        case 2:
            if(tmp.x == N) break;
            tmp.x++; 
            q.push(tmp);

            if(tmp.y == N) break;
            tmp.y++;
            tmp.dir = 3;
            q.push(tmp);   
            break;       

        case 3:
            struct pos insert;
            if(tmp.y < N) {
                insert.x = tmp.x;
                insert.y = tmp.y + 1;
                insert.dir = 1;
                q.push(insert);
            }
            if(tmp.x < N) {
                insert.x = tmp.x + 1;
                insert.y = tmp.y;
                insert.dir = 2;
                q.push(insert);
            }
            if(tmp.x < N && tmp.y < N) {
                tmp.x++;
                tmp.y++;
                q.push(tmp);
            }
            break;
        }
    } 

    cout << count;
    return 0;
}