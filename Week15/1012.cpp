#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};

int main(void) {
    int T, M, N, K, X, Y;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        int **cabbage = new int*[N];
        for(int i = 0; i < N; i++) cabbage[i] = new int[M]{0};

        vector<pair<int, int>> v;
        for(int i = 0; i < K; i++) {
            cin >> X >> Y;
            cabbage[Y][X] = 1;
            v.push_back(make_pair(X, Y));
        }

        queue<pair<int, int>> q;
        int count = 0;
        for(int i = 0; i < K; i++) {
            if(!cabbage[v[i].second][v[i].first]) continue;
            q.push(v[i]);
            cabbage[v[i].second][v[i].first] = 0;
            count++;
            while(!q.empty()) {
                pair<int, int> tmp = q.front();
                q.pop();

                for(int j = 0; j < 4; j++) {
                    int tmp_x = tmp.first + x[j];
                    int tmp_y = tmp.second + y[j];

                    if(tmp_x < 0 || tmp_x >= M || tmp_y < 0 || tmp_y >= N) continue;
                    if(cabbage[tmp_y][tmp_x]) {
                        cabbage[tmp_y][tmp_x] = 0;
                        q.push(make_pair(tmp_x, tmp_y));
                    }
                }
            }
        }
        cout << count << endl;
    }
}