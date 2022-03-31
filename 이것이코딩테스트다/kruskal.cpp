#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int findParent(vector<int>& parent, int x){
    if(parent[x] != x)
        parent[x] = findParent(parent,parent[x]);
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

    vector<int> parent(v+1);
    for(int i=1;i<v+1;i++)
        parent[i] = i;

    vector<tuple<int,int,int>> edges;
    for(int i=0;i<e;i++){
        int a,b,d;
        cin >> a >> b >> d;
        edges.push_back(make_tuple(d,a,b));
    }
    sort(edges.begin(),edges.end());

    int cost = 0;
    for(auto edge : edges){
        // If has no Cycle
        if(findParent(parent, get<1>(edge)) != findParent(parent, get<2>(edge))){
            cost += get<0>(edge);
            unionParent(parent, get<1>(edge), get<2>(edge));
        }
    }
    cout << cost << endl;
    return 0;
}