#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	string s, temp;
	cin >> s;

	int start = 0, minus = -1;
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			temp = s.substr(start, i - start);
			start = i + 1;
			v.push_back(stoi(temp));
			if (s[i] == '-' && minus == -1) minus = v.size();
		}
	}
	temp = s.substr(start, s.size() - start);
	v.push_back(stoi(temp));
	if (minus == -1) minus = v.size();

	int result = v[0];
	for (int i = 1; i < minus; i++) result += v[i];
	for (int i = minus; i < v.size(); i++) result -= v[i];

	cout << result;
	return 0;
}