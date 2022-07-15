#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	double* price = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < n; i++) {
		cout << '$' << price[i] * 0.8 << endl;
	}

	return 0;
}