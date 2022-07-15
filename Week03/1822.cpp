#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_A, num_B;
	cin >> num_A >> num_B;

	int tmp;
	set<int> A;
	for (int i = 0; i < num_A; i++) {
		cin >> tmp;
		A.insert(tmp);
	}

	for (int i = 0; i < num_B; i++) {
		cin >> tmp;
		A.erase(tmp);
	}

	cout << A.size() << '\n';
	
	set<int>::iterator iter;
	for (iter = A.begin(); iter != A.end(); iter++) cout << *iter << ' ';

	return 0;
}