#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string** arr;
string cal_pascal(int n, int m);

int main(void) {
	int n, m;
	cin >> n >> m;

	arr = new string * [n];
	for (int i = 0; i < n; i++) arr[i] = new string[i + 2];

	string cal = cal_pascal(n, m);
	cout << cal;

	return 0;
}

string cal_pascal(int n, int m) {
	if (n == 1) return "1";
	if (m == 0 || n == m) return "1";

	if (arr[n - 1][m].length() > 0) return arr[n - 1][m];

	string a = cal_pascal(n - 1, m - 1);
	string b = cal_pascal(n - 1, m);

	int a_len = a.length() - 1;
	int b_len = b.length() - 1;

	int plus_len = max(a_len, b_len) + 1;
	string plus;

	int carry = 0, aa = 0, bb = 0;
	while (plus_len >= 0) {
		if (a_len < 0) aa = 0;
		else aa = a[a_len--] - '0';

		if (b_len < 0) bb = 0;
		else bb = b[b_len--] - '0';

		int temp = aa + bb + carry;
		if (temp >= 10) {
			plus.push_back(temp - 10 + '0');
			carry = 1;
		}
		else {
			plus.push_back(temp + '0');
			carry = 0;
		}
		plus_len--;
	}
	if (plus.back() == '0') plus.pop_back();
	reverse(plus.begin(), plus.end());

	arr[n - 1][m] = plus;
	return plus;
}
