#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    if(n == 1) cout << 1;
    else if(n == 2) cout << 2;
    else {
        int n1 = 1, n2 = 2;
        for(int i = 3; i <= n; i++) {
            int tmp = (n1 + n2) % 10007;
            n1 = n2;
            n2 = tmp;
        }
        cout << n2;
    }
    
    return 0;
}