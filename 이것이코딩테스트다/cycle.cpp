#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int findParent(vector<int>& parent, int x){
    if(parent[x] != x)
        parent[x] = findParent(parent, parent[x]);
    return parent[x];
}

void unionParent(vector<int>& parent, int a, int b){
    a = findParent(parent, a);
    b = findParent(parent, b);
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<int> parent(v);
    for(int i=1;i<=v;i++)
        parent[i] = i;

    vector<pair<int,int>> edges;

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        edges.push_back(make_pair(a,b));
    }

    bool cycle = false;

    for(auto edge : edges){
        if(findParent(parent,edge.first) != findParent(parent,edge.second)){
            unionParent(parent,edge.first,edge.second);
        }else{
            cycle = true;
            break;
        }
    }

    if(cycle)
        cout << "Cycle Detected !" << endl;
    else
        cout << "No Cycle" << endl;
    return 0;
}