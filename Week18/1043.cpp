#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int num, person, truth[51] = {0,}; 
    queue<int> q;

    cin >> num; 
    for(int i = 0; i < num; i++) {
        cin >> person;
        truth[person] = 1;
        q.push(person);
    }

    int *flag = new int [M] {0};
    vector<int> *party = new vector<int> [M];
    vector<int> *people = new vector<int> [N + 1];

    for(int i = 0; i < M; i++) {
        cin >> num;
        for(int j = 0; j < num; j++) {
            cin >> person;
            party[i].push_back(person);
            people[person].push_back(i);
        }
    }

    while(!q.empty()) {
        person = q.front();
        q.pop();

        for(int i = 0; i < people[person].size(); i++) {
            num = people[person][i];
            if(flag[num]) continue;

            flag[num] = 1;
            for(int j = 0; j < party[num].size(); j++) {
                if(!truth[party[num][j]]) {
                    q.push(party[num][j]);
                    truth[party[num][j]] = 1;
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < M; i++) {
        if(!flag[i]) cnt++;
    }
    cout << cnt;
    return 0;
}