#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1,vector<int>(N+1,INT16_MAX));
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for(int i=1;i<=N;i++)
        graph[i][i] = 0;

    for(int i=1;i<=N;i++){
        for(int a=1;a<=N;a++){
            for(int b=1;b<=N;b++){
                if(a==b)
                    continue;
                graph[a][b] = min(graph[a][b], graph[a][i]+graph[i][b]);
            }
        }
    }

    int K, X;
    cin >> K >> X;

    if(graph[1][K] == INT16_MAX || graph[K][X] == INT16_MAX)
        cout << -1 << endl;
    cout << graph[1][K]+graph[K][X] << endl;

    return 0;
}