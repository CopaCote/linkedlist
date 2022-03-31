#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

int main(){
    int N, M, C;
    cin >> N >> M >> C;

    vector<vector<pair<int,int>>> graph(N+1, vector<pair<int,int>>());
    for(int i=0;i<M;i++){
        int a,b,d;
        cin >> a >> b >> d;
        graph[a].push_back(make_pair(b,d));
    }

    vector<int> distance(N+1,INT16_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    distance[C] = 0;
    q.push(make_pair(distance[C],C));

    while(!q.empty()){
        auto cur = q.top();
        q.pop();

        if(cur.first > distance[cur.second])
            continue;

        for(auto next : graph[cur.second]){
            int cost = next.second + distance[cur.second];
            if(cost < distance[next.first]){
                distance[next.first] = cost;
                q.push(make_pair(distance[next.first],cost));
            }
        }
    }

    int count=0;
    int cost=0;
    for(int i=1;i<=N;i++){
        if(distance[i] != INT16_MAX){
            count++;
            cost = max(cost,distance[i]);
        }
    }
    cout << count-1 << " " << cost << endl;
    return 0;
}