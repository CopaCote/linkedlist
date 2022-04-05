#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

int main(){
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    vector<vector<int>> v(N+1,vector<int>());

    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    queue<int> q;
    vector<int> dist(N+1,-1);
    q.push(X);
    dist[X] = 0;
    while(!q.empty()){
        int n = q.front();
        q.pop();

        for(auto i : v[n]){
            if(dist[i] == -1){
                dist[i] = dist[n] + 1;
                q.push(i);
            }
        }
    }

    int count = 0;
    for(int i=1;i<N+1;i++){
        if(dist[i] == K){
            cout << i << endl;
            count++;
        }
    }
    if(count == 0)
        cout << "-1" << endl;
    return 0;
}