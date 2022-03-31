#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v+1,vector<int>());
    vector<int> degree(v+1,0);

    for(int i=0;i<e;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }
    
    queue<int> q;
    for(int i=1;i<v+1;i++)
        if(degree[i] == 0)
            q.push(i);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int n : graph[node]){
            degree[n]--;
            if(degree[n] == 0)
                q.push(n);
        }
    }
    cout << endl;
    return 0;
}