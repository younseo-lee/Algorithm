#include <iostream>
using namespace std;

int score[2][100000];

int main(void) {
    int T, n;
    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) cin >> score[i][j];
        }

        int max_score = 0;
        if(n > 1) {
            score[0][1] += score[1][0];
            score[1][1] += score[0][0];
        }

        for(int i = 2; i < n; i++) {
            score[0][i] += max(score[1][i - 2], score[1][i - 1]);
            score[1][i] += max(score[0][i - 2], score[0][i - 1]);
        }
        cout << max(score[0][n - 1], score[1][n - 1]) << endl;
    }
}