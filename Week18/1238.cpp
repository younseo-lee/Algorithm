#include <iostream>
#include <queue>
using namespace std;

#define INF 1000000

int path[1001][1001] = {0,};
int N, *len;
void solve(int start, int end);

int main(void) {
    int M, X;
    cin >> N >> M >> X;

    int start, end, T;
    for(int i = 0; i < M; i++) {
        cin >> start >> end >> T;
        path[start][end] = T;
    }

    int *time = new int[N + 1] {0};
    len = new int[N + 1];
    for(int i = 1; i <= N; i++) {
        solve(i, X);
        time[i] = len[X];
    }

    solve(X, 0);
    int result = 0;
    for(int i = 1; i <= N; i++) {
        result = max(result, time[i] + len[i]);
    }
    cout << result;
    return 0;
}

void solve(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for(int i = 1; i <= N; i++) len[i] = INF;
    int *visited = new int[N + 1] {0};
    q.push(make_pair(0, start));
    len[start] = 0;

    while(!q.empty()) {
        start = q.top().second;
        q.pop();
        visited[start] = 1;
        if(visited[end]) return;

        for(int i = 1; i <= N; i++) {
            if(start == i || visited[i] || !path[start][i]) continue;
            if(len[start] + path[start][i] < len[i]) {
                len[i] = len[start] + path[start][i];
                q.push(make_pair(len[i], i));
            }
        }
    }
}