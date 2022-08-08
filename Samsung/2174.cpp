#include <iostream>
using namespace std;

char dir[4] = {'W', 'N', 'E', 'S'};
struct pos{
    int x;
    int y;
    char dir;
};

int board[101][101] = {0,};

int main(void) {
    int A, B, N, M;
    cin >> A >> B;
    cin >> N >> M;

    struct pos *robot = new struct pos[N];
    for(int i = 0; i < N; i++) {
        cin >> robot[i].x >> robot[i].y >> robot[i].dir;
        board[robot[i].y][robot[i].x] = i + 1;
    }

    int num, cnt;
    char type;
    for(int i = 0; i < M; i++) {
        cin >> num >> type >> cnt;
        for(int j = 0; j < cnt; j++) {
            switch(type) {
                case 'L':
                    for(int i = 0; i < 4; i++) {
                        if(robot[num - 1].dir == dir[i]) {
                            robot[num - 1].dir = dir[(i + 3) % 4];
                            break;
                        }
                    }                     
                    break;
                case 'R':                    
                    for(int i = 0; i < 4; i++) {
                        if(robot[num - 1].dir == dir[i]) {
                            robot[num - 1].dir = dir[(i + 1) % 4];
                            break;
                        }
                    }                     
                    break;
                case 'F':
                    int x = robot[num - 1].x;
                    int y = robot[num - 1].y;

                    if(robot[num - 1].dir == 'W') x--;
                    else if(robot[num - 1].dir == 'N') y++;
                    else if(robot[num - 1].dir == 'E') x++;
                    else y--;

                    if(x <= 0 || x > A || y <= 0 || y > B) {
                        cout << "Robot " << num << " crashes into the wall";
                        return 0;
                    }
                    if(board[y][x] > 0) {
                        cout << "Robot " << num << " crashes into robot " << board[y][x];
                        return 0;
                    }
                    board[robot[num - 1].y][robot[num - 1].x] = 0;
                    board[y][x] = num;
                    robot[num - 1].x = x;
                    robot[num - 1].y = y;
                    break;
            }
        }
    }

    cout << "OK";
    return 0;
}