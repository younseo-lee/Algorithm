#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000

int N, **path, *len;
vector<pair<int, int>> *v;
void solve(int start, int v1, int v2);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int E, v1, v2;
    cin >> N >> E;

    v = new vector<pair<int, int>> [N + 1]; 
    int a, b, c;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;
    
    len = new int[N + 1];
    int start_v1, start_v2, v1_v2, v1_end, v2_end;

    solve(1, v1, v2);
    start_v1 = len[v1];
    start_v2 = len[v2];

    solve(v1, v2, v2);
    v1_v2 = len[v2];

    solve(N, v1, v2);
    v1_end = len[v1];
    v2_end = len[v2];

    int result = min(start_v1 + v2_end, start_v2 + v1_end) + v1_v2;
    if(result >= INF) cout << "-1";
    else cout << result;

    return 0;
}

void solve(int start, int v1, int v2) {
    int *visited = new int[N + 1] {0};
    for(int i = 1; i <= N; i++) len[i] = INF;
    len[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push(make_pair(0, start));

    while(!q.empty()) {
        start = q.top().second;
        q.pop();
        visited[start] = 1;
        if(visited[v1] && visited[v2]) return;

        for(int i = 0; i < v[start].size(); i++) {
            int next = v[start][i].first;
            int next_len = v[start][i].second;

            if(len[start] + next_len < len[next]) {
                len[next] = len[start] + next_len;
                q.push(make_pair(len[next], next));
            }
        }
    }
}