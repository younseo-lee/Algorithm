#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;

	int start = 0, end = s.size() % 3;
	if (end == 1) cout << s[0];
	else if (end == 2) cout << (int)(s[0] - '0') * 2 + (int)(s[1] - '0');

	for (int i = end; i < s.size(); i += 3) {
		cout << (int)(s[i] - '0') * 4 + (int)(s[i + 1] - '0') * 2 + (int)(s[i + 2] - '0');
	}
	return 0;
}