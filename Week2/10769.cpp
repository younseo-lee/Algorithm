#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string s; 
	getline(cin, s);

	int happy = -3, sad = -3;
	int hc = 0, sc = 0;
	while (1) {
		happy = s.find(":-)", happy + 3);
		if (happy == string::npos) break;
		hc++;
	}
	while (1) {
		sad = s.find(":-(", sad + 3);
		if (sad == string::npos) break;
		sc++;
	}

	if (hc == 0 && sc == 0) cout << "none";
	else if (hc == sc)cout << "unsure";
	else if (hc > sc) cout << "happy";
	else cout << "sad";

	return 0;
}