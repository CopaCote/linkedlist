#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int findParent(vector<int>& parentTable, int node){
    if(parentTable[node] != node)
        parentTable[node] = findParent(parentTable, parentTable[node]);
    return parentTable[node];
}

void Union(vector<int>& parentTable, int a, int b){
    a = findParent(parentTable,a);
    b = findParent(parentTable,b);
    if(a < b)
        parentTable[b] = a;
    else
        parentTable[a] = b;
}

int main(){
   int v,e;
   cin >> v >> e;

    vector<int> parentTable(v+1);
    for(int i=1;i<=v;i++)
        parentTable[i] = i;

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        Union(parentTable,a,b);
    }

    for(int i=1;i<=v;i++)
        cout << findParent(parentTable,i) << " ";
    cout << endl;

    return 0;
}