#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;

	int ta = 0, tb = 0;
	stringstream aa(a), bb(b);
	string tmp_a, tmp_b;

	int div = 3600;
	for (int i = 0; i < 3; i++) {
		getline(aa, tmp_a, ':');
		getline(bb, tmp_b, ':');

		ta += stoi(tmp_a) * div;
		tb += stoi(tmp_b) * div;
		div /= 60;
	}

	if (ta >= tb) ta -= 24 * 3600;
	int t = tb - ta;

	cout.width(2);
	cout.fill('0');
	cout << t / 3600 << ':';

	cout.width(2);
	cout.fill('0');
	cout << (t % 3600) / 60 << ':';

	cout.width(2);
	cout.fill('0');
	cout << t % 60;

	return 0;
}