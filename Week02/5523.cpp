#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	
	int A, B;
	int cA = 0, cB = 0;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		if (A > B) cA++;
		else if (A < B) cB++;
	}
	cout << cA << ' ' << cB << endl;
	return 0;
}