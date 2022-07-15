#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	long long* len = new long long[N - 1];
	long long* price = new long long[N];

	for (int i = 0; i < N - 1; i++) cin >> len[i];
	for (int i = 0; i < N; i++) cin >> price[i];

	int i = 0;
	long long result = 0;
	while (i < N - 1) {
		int temp = i + 1, sum = len[i];
		while (temp < N - 1 && price[i] <= price[temp]) sum += len[temp++];
		
		result += price[i] * sum;
		i = temp;
	}
	cout << result;
	return 0;
}