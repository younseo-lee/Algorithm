#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> v, vector<int> seq, int m);

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;
    cin >> N >> M;

    vector<int> v, seq;
    for(int i = 0; i < N; i++) {
        cin >> num; 
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    solve(v, seq, M);

    return 0;
}

void solve(vector<int> v, vector<int> seq, int m) {
    if(m == 0) {
        for(int i = 0; i < seq.size(); i++) cout << seq[i] << " ";
        cout << "\n"; 
        return;
    }

    for(int i = 0; i < v.size(); i++) {
        vector<int> v_tmp = v, seq_tmp = seq; 
        seq_tmp.push_back(v[i]);
        v_tmp.erase(v_tmp.begin() + i);
        solve(v_tmp, seq_tmp, m - 1);
    }
}