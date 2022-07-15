
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int* num = new int[N + 1];
	for (int i = 1; i <= N; i++) cin >> num[i];

	map<int, long long>* m = new map<int, long long>[N];
	m[1][num[1]] = 1;

	for (int i = 2; i < N; i++) {
		for (auto iter = m[i - 1].begin(); iter != m[i - 1].end(); iter++) {
			int plus = iter->first + num[i];
			int minus = iter->first - num[i];
			if (plus <= 20) {
				if (m[i].find(plus) != m[i].end()) m[i][plus] += iter->second;
				else m[i][plus] = iter->second;
			}
			if (minus >= 0) {
				if (m[i].find(minus) != m[i].end()) m[i][minus] += iter->second;
				else m[i][minus] = iter->second;
			}
		}
	}
	cout << m[N - 1][num[N]];
	return 0;
}