#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	string s;
	cin >> s;

	int count = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] != s[i]) count++;
	}

	cout << 1 + (count + 1) / 2;
	return 0;
}