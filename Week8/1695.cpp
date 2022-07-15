#include <iostream>

using namespace std;

int* num; 
int** pal;
int palindrome(int start, int end);

int main(void) {
	int N;
	cin >> N;

	num = new int[N];
	for (int i = 0; i < N; i++) cin >> num[i];

	pal = new int* [N];
	for (int i = 0; i < N; i++) {
		pal[i] = new int[N];
		for (int j = 0; j < N; j++) pal[i][j] = -1;
	}

	cout << palindrome(0, N - 1);
	return 0;
}

int palindrome(int start, int end) {
	if (start >= end) return 0;
	if (pal[start][end] != -1) return pal[start][end];

	if (num[start] == num[end]) return pal[start][end] = palindrome(start + 1, end - 1);
	return pal[start][end] = 1 + min(palindrome(start + 1, end), palindrome(start, end - 1));
}

