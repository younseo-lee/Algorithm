#include <iostream>
using namespace std;

char chess[51][51] = {0,};
int board[2][51][51] = {0,};

int main(void) {
    int N, M;
    cin >> N >> M;

    char type = 'B';{}
    for(int i = 1; i <= N; i++) {
        if(i % 2) type = 'W';
        else type = 'B';

        for(int j = 1; j <= M; j++) {
            cin >> chess[i][j];

            board[0][i][j] = board[0][i-1][j] + board[0][i][j-1] - board[0][i-1][j-1];
            board[1][i][j] = board[1][i-1][j] + board[1][i][j-1] - board[1][i-1][j-1];

            if(chess[i][j] == type) board[0][i][j]++;
            else board[1][i][j]++;

            if(type == 'W') type = 'B';
            else type = 'W'; 
        }
    }

    int result = 64; 
    for(int i = 8; i <= N; i++) {
        for(int j = 8; j <= M; j++) {
            result = min(result, board[0][i][j] + board[0][i-8][j-8] - board[0][i-8][j] - board[0][i][j-8]);
            result = min(result, board[1][i][j] + board[1][i-8][j-8] - board[1][i-8][j] - board[1][i][j-8]);
        }
    }

    cout << result;
    return 0;
}