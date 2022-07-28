#include <iostream>
using namespace std;

int board[20][20]; 
int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};

int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }



}