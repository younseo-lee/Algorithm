#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	string s;
	vector<int> v;

	while (1) {
		getline(cin, s);
		if (s == "EOI") break;

		for(int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
		if (s.find("nemo") != string::npos) v.push_back(1);
		else v.push_back(0);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1) cout << "Found" << endl;
		else cout << "Missing" << endl;
	}
	return 0;
}