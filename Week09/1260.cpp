#include <iostream>
#include <queue>
using namespace std;

int N;
int node[1001][1001] = { 0, };
queue<int> q;

void dfs(int* visited, int v);
void bfs(int* visited, int v);

int main(void) {
	int M, V;
	cin >> N >> M >> V;

	int n1, n2;

	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		node[n1][n2] = 1;
		node[n2][n1] = 1;
	}

	int* dfs_visited = new int[N + 1]{ 0 };
	dfs(dfs_visited, V);
	cout << endl;

	int* bfs_visited = new int[N + 1]{ 0 };
	bfs(bfs_visited, V);

	return 0;
}

void dfs(int* visited, int v) {
	cout << v << ' ';
	visited[v] = 1;

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0 && node[i][v] == 1) {
			dfs(visited, i);
		}
	}
}

void bfs(int* visited, int v) {
	q.push(v);
	visited[v] = 1;

	while (q.empty() == 0) {
		v = q.front();
		cout << v << ' ';
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0 && node[i][v] == 1) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}