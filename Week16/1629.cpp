#include <iostream>
using namespace std;

int func(int);
int A, B, C; 

int main(void) {
    cin >> A >> B >> C;
    cout << func(B);

    return 0;
}

int func(int mul) {
    if(mul == 1) return A % C;

    long long div = func(mul / 2);
    if(mul % 2) return (div * div % C * A) % C; 
    return (div * div) % C;
}