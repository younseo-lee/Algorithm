#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	string* s = new string[N];
	int flag = 0;
	for (int i = 0; i < N; i++) cin >> s[i];
	for (int i = 0; i < N - 1; i++) {
		if (s[i] > s[i + 1]) {
			if (flag == 0 || flag == 1) flag = 1;
			else {
				flag = 0;
				break;
			}
		}
		else {
			if (flag == 0 || flag == -1) flag = -1;
			else {
				flag = 0;
				break;
			}
		}
	}
	if (flag == 1) cout << "DECREASING";
	else if (flag == 0) cout << "NEITHER";
	else if (flag == -1) cout << "INCREASING";

	return 0;
}