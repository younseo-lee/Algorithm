#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<int> v;
	string command;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push_front") {
			cin >> num;
			v.insert(v.begin(), num);
		}
		else if (command == "push_back") {
			cin >> num;
			v.push_back(num);
		}
		else if (command == "pop_front") {
			if (v.empty()) cout << "-1" << endl;
			else {
				cout << v.front() << endl;
				v.erase(v.begin());
			}
		}
		else if (command == "pop_back") {
			if (v.empty()) cout << "-1" << endl;
			else {
				cout << v.back() << endl;
				v.pop_back();
			}
		}
		else if (command == "size") {
			cout << v.size() << endl;
		}
		else if (command == "empty") {
			cout << (int)v.empty() << endl;
		}
		else if (command == "front") {
			if (v.empty()) cout << "-1" << endl;
			else cout << v.front() << endl;
		}
		else if (command == "back") {
			if (v.empty()) cout << "-1" << endl;
			else cout << v.back() << endl;
		}
	}

	return 0;
}