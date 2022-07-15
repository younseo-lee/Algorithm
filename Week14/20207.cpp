#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    int S, E;
    for(int i = 0; i < N; i++) {
        cin >> S >> E;
        v.push_back(make_pair(S, E));
    }
    sort(v.begin(), v.end());

    int cal[366] = {0,};
    for(int i = 0; i < N; i++) {
        for(int j = v[i].first; j <= v[i].second; j++) cal[j]++;
    }

    int width = 0, height = 0, total = 0;
    for(int i = 1; i <= 365; i++) {
        if(!cal[i]) {
            total += width * height;
            width = height = 0;
            continue;
        }
        width++;
        height = max(cal[i], height);
    }
    total += width * height;

    cout << total;
    return 0;
}