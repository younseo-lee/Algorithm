#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<int> v;
void zoac(int start, int end);

int main(void) {
    cin >> s;

    for(int i = 0; i < s.size(); i++) v.push_back(0);
    zoac(0, s.size() - 1);

    return 0;
}

void zoac(int start, int end) {
    if(start > end) return;
    if(start == end) {
        v[start] = 1;
        for(int i = 0; i < s.size(); i++) {
            if(v[i]) cout << s[i];
        }
        cout << endl;
        return;
    }

    int min = start;
    for(int i = start + 1; i <= end; i++) {
        if(s[i] < s[min]) min = i;
    }
    v[min] = 1;
    for(int i = 0; i < s.size(); i++) {
        if(v[i]) cout << s[i];
    }
    cout << endl;

    zoac(min + 1, end);
    zoac(start, min - 1);
}