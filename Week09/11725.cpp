#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(int* visited, int v);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int>* v = new vector<int>[N + 1];

	int n1, n2;
	for (int i = 1; i < N; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	int* visited = new int[N + 1]{ 0 };
	queue<int> q;
	q.push(1);

	int n;
	while (q.empty() == 0) {
		n = q.front();
		q.pop();

		for (int i = 0; i < v[n].size(); i++) {
			if (visited[v[n][i]] == 0) {
				visited[v[n][i]] = n;
				q.push(v[n][i]);
			}
		}
	}

	for (int i = 2; i <= N; i++) cout << visited[i] << '\n';
	return 0;
}

