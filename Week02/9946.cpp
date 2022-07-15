#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	string a, b;
	vector<int> v;

	while (1) {
		cin >> a >> b;
		if (a == "END" && b == "END") break;
		if (a.size() != b.size()) v.push_back(0);
		else {
			sort(a.begin(), a.end(), greater<char>());
			sort(b.begin(), b.end(), greater<char>());
			if (a == b) v.push_back(1);
			else v.push_back(0);
		}	
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) cout << "Case " << i + 1 << ": different" << endl;
		else cout << "Case " << i + 1 << ": same" << endl;
	}

	return 0;
}