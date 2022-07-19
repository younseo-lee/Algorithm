#include <iostream>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	int* node = new int[N + 1]{ 0 };
	int n1, n2, p1, p2;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;

		p1 = n1;
		while (node[p1]) p1 = node[p1];

		p2 = n2;
		while (node[p2]) p2 = node[p2];

		if (p1 == p2) continue;
		node[max(p1, p2)] = min(p1, p2);
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (!node[i]) count++;
	}
	cout << count;
	return 0;
}