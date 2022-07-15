#include <iostream>
#include <map>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;

	int* price = new int[n];
	for (int i = 0; i < n; i++) cin >> price[i];

	int* count = new int[k + 1]{ 0 };
	count[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = price[i]; j <= k; j++)
			count[j] += count[j - price[i]];
	}

	cout << count[k];

	return 0;
}

