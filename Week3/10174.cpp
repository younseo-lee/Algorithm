#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	int N, flag;
	cin >> N;
	cin.ignore();
	
	string s;
	for (int i = 0; i < N; i++) {
		getline(cin, s);
		flag = 0;
		for (int j = 0; j < s.size() / 2; j++) {
			if (tolower(s[j]) != tolower(s[s.size() - 1 - j])) flag = 1;
		}
		if (flag) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}