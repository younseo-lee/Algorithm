#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	cin.ignore();

	string* s = new string[N];
	int alpha[26] = { 0, }, flag0 = 0, flag1 = 0, flag2 = 0;
	char ch;

	for (int i = 0; i < N; i++) {
		getline(cin, s[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			ch = tolower(s[i][j]);
			if (ch >= 'a' && ch <= 'z') alpha[(int)(ch - 'a')]++;
		}
		for (int j = 0; j < 26; j++) {
			if (alpha[j] == 0) flag0 = 1;
			else if (alpha[j] == 1) flag1 = 1;
			else if (alpha[j] == 2) flag2 = 1;
			alpha[j] = 0;
		}
		cout << "Case " << i + 1 << ": ";
		if (flag0) cout << "Not a pangram" << endl;
		else if (flag1) cout << "Pangram!" << endl;
		else if (flag2)cout << "Double pangram!!" << endl;
		else cout << "Triple pangram!!!" << endl;

		flag0 = 0; flag1 = 0; flag2 = 0;
	}
	return 0;
}