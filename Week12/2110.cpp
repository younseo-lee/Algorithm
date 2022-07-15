#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C, result = 0;

int main(void) {
	cin >> N >> C;
	vector<int> house(N);

	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
	sort(house.begin(), house.end());

	int start = 1, end = house[N - 1], cnt = 2, result = 0;
	while (start <= end) {
		int mid = (start + end) / 2;

		int tmp = house[0], cnt = 1;
		for (int i = 1; i < house.size(); i++) {
			if (house[i] - tmp >= mid) {
				cnt++;
				tmp = house[i];
			}
		}

		if (cnt >= C) {
			result = max(result, mid);
			start = mid + 1;
		}
		else end = mid - 1;
	}

	cout << result;
	return 0;
}