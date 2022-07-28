#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int num[100000][3] = {0,};

int main(void) {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i][0] >> num[i][1] >> num[i][2];

    int s_min[3] = {0,}, s_max[3] = {0,}, tmp[3] = {0,};
    s_min[0] = s_max[0] = num[0][0];
    s_min[1] = s_max[1] = num[0][1];
    s_min[2] = s_max[2] = num[0][2];

    for(int i = 1; i < N; i++) {
        tmp[0] = min(s_min[0], s_min[1]) + num[i][0];
        tmp[1] = min({s_min[0], s_min[1], s_min[2]}) + num[i][1];
        tmp[2] = min(s_min[1], s_min[2]) + num[i][2];
        memcpy(s_min, tmp, sizeof(s_min));

        tmp[0] = max(s_max[0], s_max[1]) + num[i][0];
        tmp[1] = max({s_max[0], s_max[1], s_max[2]}) + num[i][1];
        tmp[2] = max(s_max[1], s_max[2]) + num[i][2];
        memcpy(s_max, tmp, sizeof(s_max));
    }

    cout << max({s_max[0], s_max[1], s_max[2]}) << " ";
    cout << min({s_min[0], s_min[1], s_min[2]});
    return 0;
}