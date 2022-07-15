#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int* price = new int[N];
	for (int i = 0; i < N; i++) cin >> price[i];
	sort(price, price + N);
	reverse(price, price + N);

	int sum = 0;
	for (int i = 0; i < N; i += 3) sum += price[i];
	for (int i = 1; i < N; i += 3) sum += price[i];

	cout << sum;
	return 0;
}