#include <iostream>
using namespace std;

int num[1025][1025] = {0,};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> num[i][j];
            num[i][j] += num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;
    for(int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << num[x1 - 1][y1 - 1] + num[x2][y2] - num[x1 - 1][y2] - num[x2][y1 - 1] << '\n';
    }
    return 0;
}