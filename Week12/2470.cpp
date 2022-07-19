#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, tmp;
	cin >> N;

	vector<int> acid, alk;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		//if (tmp >= 0) acid.push_back(tmp);
		//else alk.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int start = 0, end = N - 1;

	int result = 2000000000;
	int n1 = 0, n2 = 0;

	while (start < end) {
		int tmp = arr[start] + arr[end];
		cout << arr[start] << ' ' << arr[end] << ' ' << result << endl;

		if (abs(tmp) < result) {
			result = abs(tmp);
			n1 = arr[start];
			n2 = arr[end];
			if (result == 0) break;
		}

		if (tmp < 0) start++;
		else end--;
	}
	cout << n1 << ' ' << n2;
	return 0;
}
