#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;

	string s, tmp;
	cin >> s;
	stringstream str(s);

	int* arr = new int[N];
	vector<int> v;
	for (int i = 0; i < N; i++) {
		getline(str, tmp, ',');
		v.push_back(stoi(tmp));
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < v.size() - 1; j++) v[j] = v[j + 1] - v[j];
		v.pop_back();
	}
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ',';
	}
	cout << v.back();
	return 0;
}