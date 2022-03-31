#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int findParent(vector<int>& parent, int x){
    if(parent[x] != x)
        parent[x] = findParent(parent, parent[x]);
    return parent[x];
}

void unionParent(vector<int>& parent, int a, int b){
    a = findParent(parent,a);
    b = findParent(parent,b);
    if(a<b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    // 아이디어 : 최소 신장트리(크루스칼)를 만들고, 거기서 최댓값의 길을 없앤다.
    int N, M;
    cin >> N >> M;

    vector<int> parent(N+1);
    for(int i=1;i<N+1;i++)
        parent[i] = i;

    vector<tuple<int,int,int>> edges;
    for(int i=0;i<M;i++){
        int a,b,d;
        cin >> a >> b >> d;
        edges.push_back(make_tuple(d,a,b));
    }

    sort(edges.begin(),edges.end());

    int result=0;
    int maxCost=0;
    for(auto edge : edges){
        int a = get<1>(edge);
        int b = get<2>(edge);
        int cost = get<0>(edge);
        // No Cycle
        if(findParent(parent,a) != findParent(parent,b)){
            unionParent(parent,a,b);
            result += cost;
            // 지울 최댓값 기록(어차피 오름차순이니까 마지막에 하는 놈이 최댓값임)
            maxCost = cost;
        }
    }
    result -= maxCost;
    cout << result << endl;
    return 0;
}