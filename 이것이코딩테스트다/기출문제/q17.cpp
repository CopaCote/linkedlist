// DFS로 풀었지만, 풀이는 BFS를 권장하네요

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void dfs(int x, int y, vector<vector<int>>& v, vector<vector<int>>& t, int s, int N, int t_limit){
    if(x < 1 || x >= v.size() || y < 1 || y >= v.size())
        return;
    if(s > t_limit)
        return;

    // 시간이 작을때만 증식
    if(s < t[x][y]){
        t[x][y] = s;
        v[x][y] = N;
        dfs(x+1,y,v,t,s+1, N,t_limit);
        dfs(x-1,y,v,t,s+1, N,t_limit);
        dfs(x,y+1,v,t,s+1, N,t_limit);
        dfs(x,y-1,v,t,s+1, N,t_limit);
    }
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<vector<int>> v(N+1,vector<int>(N+1));
    vector<vector<int>> t(N+1,vector<int>(N+1,INT32_MAX));
    vector<vector<pair<int,int>>> nums(K+1,vector<pair<int,int>>());
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int n;
            cin >> n;
            v[i][j] = n;
            if(n != 0){
                t[i][j] = 0;
                nums[n].push_back(make_pair(i,j));
            }
        }
    }

    int S,X,Y;
    cin >> S >> X >> Y;

    
    for(int i=1;i<=K;i++){
        for(auto pos : nums[i]){
            dfs(pos.first+1,pos.second,v,t,1,i,S);
            dfs(pos.first-1,pos.second,v,t,1,i,S);
            dfs(pos.first,pos.second+1,v,t,1,i,S);
            dfs(pos.first,pos.second-1,v,t,1,i,S);
        }
    }

    cout << v[X][Y] << endl;
    return 0;
}