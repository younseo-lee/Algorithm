#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct pos {
    int blue_x; 
    int blue_y;
    int red_x; 
    int red_y;
    int dir;
    int count; 
};

int board[10][10], N, M, hole_x, hole_y;;
int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};

struct pos input(); 
struct pos move_ball(struct pos tmp, int dir); 
void print(struct pos tmp);

int main(void) {
    cin >> N >> M;
    struct pos init = input(); 

    queue<struct pos> q;
    q.push(init);

    vector<struct pos> v;
    v.push_back(init); 

    while(!q.empty()) {
        struct pos tmp = q.front();
        q.pop();
        v.push_back(tmp);

        for(int i = 0; i < 4; i++) {
            if(abs(tmp.dir - i) == 2) continue; 
            struct pos move = move_ball(tmp, i); 
            if(move.dir == -1) {
                if(move.count >= 10) cout << -1;
                else cout << move.count + 1; 
                return 0;
            } 
            else if(move.count != tmp.count) {
                int flag = 0;
                for(int j = 0; j < v.size(); j++) {
                    if(v[j].blue_x == move.blue_x && v[j].blue_y == move.blue_y && v[j].red_x == move.red_x && v[j].red_y == move.red_y) {
                        flag = 1; 
                        break;
                    }
                }
                if(!flag) {
                    q.push(move); 
                    //print(move);
                }
            }
        }
    }
    cout << -1;
    return 0;
}

struct pos input() {
    char in;
    struct pos init;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> in;
            switch(in) {
                case '#': 
                    board[i][j] = 1; 
                    break;
                case 'B': 
                    board[i][j] = 0; 
                    init.blue_x = j; 
                    init.blue_y = i; 
                    break;
                case 'R':
                    board[i][j] = 0; 
                    init.red_x = j;
                    init.red_y = i;
                    break;
                case 'O':
                    board[i][j] = 0; 
                    hole_x = j;
                    hole_y = i;
                    break;
            }
        }
    }
    init.dir = -10; 
    init.count = 0; 
    return init;
}

struct pos move_ball(struct pos tmp, int dir) {
    struct pos move = tmp;
    int check = 0, b_flag = 0; 

    while(1) {
        int blue_x = move.blue_x + x[dir];
        int blue_y = move.blue_y + y[dir];

        if(board[blue_y][blue_x]) break; 
        if(blue_x == move.red_x && blue_y == move.red_y) {
            b_flag = 1; 
            break;
        }
        if(blue_x == hole_x && blue_y == hole_y) return move; 
        
        move.blue_x = blue_x; 
        move.blue_y = blue_y; 
        check++;
    }

    while(1) {
        int red_x = move.red_x + x[dir];
        int red_y = move.red_y + y[dir];

        if(board[red_y][red_x]) break; 
        if(red_x == move.blue_x && red_y == move.blue_y) break;
        if(red_x == hole_x && red_y == hole_y) {
            if(!b_flag) move.dir = -1;
            return move;
        }

        if(b_flag) {
            move.blue_x = move.red_x;
            move.blue_y = move.red_y;
        }   
        move.red_x = red_x; 
        move.red_y = red_y;
        check++; 
    }

    if(check) {
        move.dir = dir;
        move.count++;
    }
    return move;
}

void print(struct pos tmp) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 1) cout << '#';
            else if(i == tmp.blue_y && j == tmp.blue_x) cout << 'B';
            else if(i == tmp.red_y && j == tmp.red_x) cout << 'R';
            else if(i == hole_y && j == hole_x) cout << 'O';
            else cout << '.';
        }
        cout << endl; 
    }
    cout << endl; 
}