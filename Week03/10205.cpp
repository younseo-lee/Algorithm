#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int head;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> head >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'c') head += 1;
			else if (s[j] == 'b') head -= 1;
		}
		cout << "Data Set " << i + 1 << ":\n" << head << "\n\n";
	}
	return 0;
}