#include <iostream>
using namespace std;

#define INF 100000000

int main(void) {
    int N, M;
    cin >> N;
    cin >> M;

    int **bus = new int*[N + 1], start, end, price;
    for(int i = 1; i <= N; i++) {
        bus[i] = new int[N + 1];
        for(int j = 1; j <= N; j++) bus[i][j] = INF;
    }

    for(int i = 0; i < M; i++) {
        cin >> start >> end >> price;
        if(bus[start][end] > price) bus[start][end] = price;
    }

    cin >> start >> end;
    int *min_price = new int[N + 1] {-1}, *visited = new int[N + 1] {0};
    for(int i = 1; i <= N; i++) min_price[i] = INF;
    min_price[start] = 0;

    while(1) {
        visited[start] = 1;
        for(int i = 1; i <= N; i++) {
            if(i == start || visited[i]) continue;
            if(bus[start][i] != -1) {
                if(min_price[start] + bus[start][i] < min_price[i]) {
                    min_price[i] = min_price[start] + bus[start][i];
                }
            }
        }

        int min_p = INF;
        for(int i = 1; i <= N; i++) {
            if(visited[i]) continue;
            if(min_price[i] < min_p) {
                min_p = min_price[i];
                start = i;
            }
        }
        if(min_p == INF) break;
    }

    cout << min_price[end];
    return 0;
}