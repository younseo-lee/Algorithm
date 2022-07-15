#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

int main(void) {
	// 'i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili'
	string str = "";
	getline(cin, str);

	stringstream ss(str);
	string buffer;
	vector<string> v;

	while (getline(ss, buffer, ' '))
		v.push_back(buffer);

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == "i" || v[i] == "pa" || v[i] == "te" || v[i] == "ni" || v[i] == "niti" || v[i] == "a" || v[i] == "ali" || v[i] == "nego" || v[i] == "no" || v[i] == "ili") {
			if (i == 0) cout << (char)toupper(v[i][0]);
		}
		else cout << (char)toupper(v[i][0]);
	}
	return 0;
}