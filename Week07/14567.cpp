#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<int>* v = new vector<int>[N + 1];
	
	int pre, next;
	for (int i = 0; i < M; i++) {
		cin >> pre >> next;
		v[next].push_back(pre);
	}

	int sub = 0, sem_count = 1;
	int* sem = new int[N + 1]{ 0, };

	while (sub < N) {
		int count = 0;
		for (int i = 1; i <= N; i++) {
			if (sem[i] == 0 && v[i].empty()) {
				sem[i] = sem_count;
				sub++;
			}
		}
		for(int i = 1; i <= N; i++) {
			if(sem[i] == sem_count) {
				for (int j = i + 1; j <= N; j++) {
					auto index = find(v[j].begin(), v[j].end(), i);
					if (index != v[j].end()) v[j].erase(index);
				}
			}
		}
		sem_count++;
	}

	for (int i = 1; i <= N; i++) cout << sem[i] << " ";
	return 0;
}