#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

int main(){
    int nodes, vertices;
    cin >> nodes >> vertices;

    int start;
    cin >> start;

    vector<vector<pair<int,int>>> graph(nodes+1,vector<pair<int,int>>());

    for(int i=0;i<vertices;i++){
        int from, to, dis;
        cin >> from >> to >> dis;
        graph[from].push_back(make_pair(to,dis));
    }

    vector<int> distanceTable(nodes+1,INT16_MAX);

    // 거리, 노드
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    distanceTable[start] = 0;
    q.push(make_pair(distanceTable[start],start));

    while(!q.empty()){
        pair<int,int> cur = q.top();
        q.pop();
        
        if(distanceTable[cur.second] < cur.first)
            continue;

        // 노드, 거리
        for(pair<int,int> p : graph[cur.second]){
            int dist = p.second + distanceTable[cur.second];
            if(dist < distanceTable[p.first]){
                distanceTable[p.first] = dist;
                q.push(make_pair(distanceTable[p.first],p.first));
            }
        }
    }

    for(int i=1;i<distanceTable.size();i++){
        cout << distanceTable[i] << endl;
    }
    return 0;
}