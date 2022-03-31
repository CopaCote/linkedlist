#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <tuple>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<tuple<int,int,int>> edges;
    for(int i=0;i<M;i++){
        int a,b,d;
        cin >> a >> b >> d;
        edges.push_back(make_tuple(a,b,d));
    }

    vector<long long> distance(N+1,INT32_MAX);
    distance[1] = 0;
    for(int i=0;i<N;i++){
        for(auto t : edges){
            int a = get<0>(t);
            int b = get<1>(t);
            int d = get<2>(t);
            if(distance[a] != INT32_MAX && distance[a] + d < distance[b]){
                distance[b] = distance[a] + d;
                if(i == N-1){
                    cout << "-1" << endl;
                    return 0;
                }
            }
        }
    }

    for(int i=2;i<=N;i++){
        if(distance[i] == INT32_MAX)
            cout << "-1" << endl;
        else
            cout << distance[i] << endl;
    }

    return 0;
}