#include <iostream>
using namespace std;

int main(void) {
    int N, r, c;
    cin >> N >> r >> c;

    int x = 0, y = 0, size, tmp_x, tmp_y, count = 0;
    for(int i = N; i > 0; i--) {
        size = 1 << (i - 1);
        tmp_x = x + size;
        tmp_y = y + size;

        if(r < tmp_y && c >= tmp_x) {
            count += size * size;
            x = tmp_x;
        }
        else if(r >= tmp_y && c < tmp_x) {
            count += size * size * 2;
            y = tmp_y;
        }
        else if(r >= tmp_y && c >= tmp_x) {
            count += size * size * 3;
            x = tmp_x;
            y = tmp_y;
        }
    }
    
    cout << count;
    return 0;
}