#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string name[5];
	int pos, flag = 0;

	for (int i = 0; i < 5; i++)
		cin >> name[i];

	for (int i = 0; i < 5; i++) {
		pos = name[i].find("FBI");
		if (pos == string::npos) continue;
		cout << i + 1 << ' ';
		flag = 1;
	}
	if (!flag) cout << "HE GOT AWAY!";
	return 0;
}