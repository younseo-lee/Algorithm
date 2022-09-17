#include <iostream>
#include <vector>
using namespace std;

int *visited, max_node = 0, max_dist = 0;
vector<pair<int, int>> *v;
void dfs(int node, int dist);

int main(void) {
    int V; 
    cin >> V; 

    int start, end, cost;
    v = new vector<pair<int, int>> [V + 1];

    for(int i = 0; i < V; i++) {
        cin >> start; 
        while(1) {
            cin >> end;
            if(end == -1) break;
            cin >> cost;    
            v[start].push_back(make_pair(end, cost));
            v[end].push_back(make_pair(start, cost));
        }
    }

    visited = new int [V + 1] {0};
    dfs(1, 0);
    for(int i = 1; i <= V; i++) visited[i] = 0;
    dfs(max_node, 0); 

    cout << max_dist; 
    return 0;
}

void dfs(int node, int dist) {
    if(dist > max_dist) {
        max_dist = dist; 
        max_node = node;
    }

    visited[node] = 1;
    for(int i = 0; i < v[node].size(); i++) {
        if(visited[v[node][i].first]) continue;
        dfs(v[node][i].first, dist + v[node][i].second);
    }
}