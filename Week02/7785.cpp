#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string name, state;
	map<string, int, greater<>> m;

	for (int i = 0; i < n; i++) {
		cin >> name >> state;
		if (state == "enter") m[name] = 1;
		else m[name] = 0;
	}

	for (auto i : m) {
		if (i.second == 1) cout << i.first << '\n';
	}
;
	return 0;
}