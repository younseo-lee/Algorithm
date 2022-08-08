#include <iostream>
using namespace std;

int N;
char board[50][50] = {0,};
int solve(int dir, int index);

int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }

    int result = 0;
    for(int i = 0; i < N; i++) {
        result = max(result, solve(0, i));
        result = max(result, solve(1, i));
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i + 1 < N && board[i][j] != board[i + 1][j]) {
                char tmp = board[i][j];
                board[i][j] = board[i + 1][j];
                board[i + 1][j] = tmp;
                
                result = max(result, solve(0, i));
                result = max(result, solve(0, i + 1));
                result = max(result, solve(1, j));

                board[i + 1][j] = board[i][j];
                board[i][j] = tmp;
            }
            if(j + 1 < N && board[i][j] != board[i][j + 1]) {                
                char tmp = board[i][j];
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = tmp;
                
                result = max(result, solve(0, i));
                result = max(result, solve(1, j));
                result = max(result, solve(1, j + 1));

                board[i][j + 1] = board[i][j];
                board[i][j] = tmp;
            } 
        }
    }
    cout << result;
    return 0;
}

int solve(int dir, int index) {
    int max_cnt = 1, cnt = 1;

    if(dir == 0) {
        for(int k = 1; k < N; k++) {
            if(board[index][k] == board[index][k - 1]) cnt++;
            else {
                max_cnt = max(max_cnt, cnt);
                cnt = 1;
            }            
        }
    }
    else {
        for(int k = 1; k < N; k++) {
            if(board[k][index] == board[k - 1][index]) cnt++;
            else {
                max_cnt = max(max_cnt, cnt);
                cnt = 1;
            }
        }
    }
    
    max_cnt = max(max_cnt, cnt);
    return max_cnt;
}