#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string S;
	cin >> S;

	int fir[26];
	for (int i = 0; i < 26; i++) fir[i] = -1;

	for (int i = 0; i < S.size(); i++) {
		if (fir[(int)(S[i] - 'a')] == -1) 
			fir[(int)(S[i] - 'a')] = i;
	}

	for (int i = 0; i < 26; i++) cout << fir[i] << ' ';
	return 0;
}