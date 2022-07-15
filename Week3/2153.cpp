#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') sum += s[i] - 'a' + 1;
		else if (s[i] >= 'A' && s[i] <= 'Z') sum += s[i] - 'A' + 27;
	}
	
	int count = 0;
	for (int i = 1; i <= sum; i++) {
		if (sum % i == 0) count++;
	}
	if (count <= 2) cout << "It is a prime word.";
	else cout << "It is not a prime word.";

	return 0;
}