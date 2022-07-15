#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string word;
	cin >> word;

	int alpha[26] = { 0, };
	for (int i = 0; i < word.size(); i++) {
		if (word[i] >= 'a') alpha[(int)(word[i] - 'a')]++;
		else alpha[(int)(word[i] - 'A')]++;
	}
	int max = alpha[0], max2 = 0, index = 0;
	for (int i = 1; i < 26; i++) {
		if (alpha[i] > max) {
			max2 = max;
			max = alpha[i];
			index = i;
		}
		else if (alpha[i] > max2) max2 = alpha[i];
	}
	if (max == max2) cout << '?';
	else cout << (char)(index + 'A');

	return 0;
}